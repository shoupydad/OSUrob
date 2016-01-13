#include "stdafx.h"
#include <string.h>
#include <sys/timeb.h>
#include <time.h>
#include <comutil.h>
#include "defines.h"
#include "Form1.h"
#include "OkayDialog.h"
#include "YesNoDialog.h"
#include "ProgressDialog.h"
#include "MoveScopeDialog.h"

using namespace System;
using namespace System::IO::Ports;
using namespace System::Runtime::InteropServices;
//using namespace ASCOM::Interface;
//using namespace ASCOM::DriverAccess;
//using namespace Meade;

namespace OSUrob {

/* Support routines */

int MessageBox(char *prompt, int buttons) {
	switch (buttons) {
		case OKAY:
			if (! OkayDialogExists) {
				gcnew OkayDialog();
			}
			OkayDialog::SetMessage(prompt);
			MessageBoxAnswer = NOANSWER;
			OkayDialog::ShowTheDialog();
			return MessageBoxAnswer;
			break;
		case YESNO:
			if (! YesNoDialogExists) {
				gcnew YesNoDialog();
			}
			YesNoDialog::SetMessage(prompt);
			MessageBoxAnswer = NOANSWER;
			YesNoDialog::ShowTheDialog();
			return MessageBoxAnswer;
			break;
	}
	return NOANSWER;
}

void usleep(int usecs, bool DoEvents) {
	int msecs;

	msecs =  usecs/1000;
	System::Threading::Thread::Sleep(msecs);
	if (DoEvents)
		DoMainEvents();

	return;
}

void DoMainEvents(void) {
	Application::DoEvents();
}


void stripTrailingBlanks(char *string) {

	char *cptr;
	int blank=' ';

	do {
		cptr = strrchr(string, blank);  /* find a blank */
		if (cptr == NULL)
			break;
		if (*(cptr+1) != 0)   /* check if its a trailing blank */
			break;
		*cptr = 0;
	} while (true);

	return;
}



/*=======================================================================}
{*  Procedure julian_day                                                *}
{*  Calling Parameters: None                                            *}
{*  Return Parameters: jd                                               *}
{*  Reference: "Astronomical Algorithms"  Page 59                       *}
{*  Description: JULIAN_DAY returns the julian day for the current      *}
{*    system calendar date and time.                                    *}
{*======================================================================*/
void JulianDay(int year, int month, int day, int hour, int minute,
	       int second, int sec100, double *jd)
{
   int A, B, m, y;
   double d;

   DecimalDay(day,hour,minute,second,sec100,&d);
   month++;  // correct for 0-11 instead of 1-12
   if (month > 2) {
      y = year;
      m = month;
   } else {
      y = year-1;  // was y = year - 1
      m = month+12;  // was m = month + 12;
   }

   A = y / 100;

   if ((year <= 1582) ||
       ((year == 1582) &&
	((month <= 10) ||
	 ((month == 10) && (day <= 4)))))
      B = 0;
   else
      B = 2 - A + A / 4;

   *jd = floor(365.25 * (y + 4716)) +
	floor(30.6001 * (m + 1)) + d + B - 1524.5;
}




/*=======================================================================}
{*  Procedure decimal_day                                               *}
{*  Calling Parameters: none                                            *}
{*  Return Parameters: dec_day                                          *}
{*  Reference: David Genet                                              *}
{*  Description: DECIMAL_DAY returns the day and the fractional part    *}
{*     of a day for the current system date and time.                   *}
{*======================================================================*/
void DecimalDay(int day, int hour, int minute, int second, int sec100,
		double *DecDay)
{
   double FracDay;
   long int TempHour;

   TempHour = (long) hour;    //for the muliplication by 3600 to prevent overflow
   FracDay  = (TempHour*3600.0+minute*60.0+second+sec100/100.0)/86400.0;
   *DecDay = day+FracDay;
}




/*=======================================================================}
{*  Procedure LMST                                                      *}
{*  Calling Parameters: None                                            *}
{*  Return Parameters: lst                                              *}
{*  Reference: "Astronomical Algorithms"  Page 83 Formulas 11.1 & 11.4  *}
{*  Description: LMST returns the current mean sidereal time for the    *}
{*    location specified by the global variable site_longitude and the  *}
{*    passed julian date.                                               *}
{*======================================================================*/
void lmst(double julian_date, double *lst)
{

#define num1 280.46061837

   double t; // number of Julian centuries since j2000
   double Theta, Theta1; // IAU convention for mean sidereal time at Greenwhich at 0h UT
   double num2, num3, num4, gmst;
   long int x;

   t = (julian_date-2451545.0)/36525.0;
   num2 = 360.98564736629*(julian_date-2451545.0);
   num3 = t*t*0.000387933;
   num4 = -(t*t*t)/38710000.0;
   Theta1 = num1+num2+num3+num4;

   Theta = 0;
   if (Theta1 < 0) {
      x = (long) (-floorl(Theta1/360.0) - 1);
      Theta = ((x+1)*360)+Theta1;
   }

   if (Theta1 >= 360.0) {
      x = (long) floorl(Theta1/360.0);
      Theta = Theta1 - (x*360);
   }

   gmst = Theta/15.0;
   *lst  = gmst+(Observatory.SiteLongitude/15.0);

   /* convert from Greenwich mean sidereal time to local mean sidereal
      time and also convert from degrees to hours */

   if (*lst<0) *lst = *lst+24.0;
   if (*lst>=24.0) *lst = *lst-24.0;
}

bool SendObsCon(char *command, char *response, int MaxNumBytes) {

	int TotalBytes, TimeOutCounts;
	char ch;
	String ^ComPortName;
	String ^buffer;

	// Open com port if necessary

	if (Form1::ObsConComPortPtr == nullptr) {
		if (! CheckIfComPortExists(OBSCON_COM_PORT_NAME)) {
			return false;
		}
		ComPortName = gcnew String(OBSCON_COM_PORT_NAME);
		Form1::ObsConComPortPtr = gcnew SerialPort(ComPortName);
		Form1::ObsConComPortPtr->Open();
	}

	if (! Form1::ObsConComPortPtr->IsOpen) {
		Form1::StatusPrint("*** Warning - Trying to write to unopened com port (SendObsCon)\n");
		return false;
	}

	// Clear off any waiting "responses"

	while (Form1::ObsConComPortPtr->BytesToRead > 0)
		Form1::ObsConComPortPtr->ReadChar();

	// Send command to observatory controller

	buffer = gcnew String(command);
	Form1::ObsConComPortPtr->Write(buffer);

	// Check for any characters waiting

	TotalBytes = 0;
	response[0] = '\0';
	TimeOutCounts = 5000;
	do {
		if (Form1::ObsConComPortPtr->BytesToRead > 0) {
			ch = Form1::ObsConComPortPtr->ReadChar();
			response[TotalBytes++] = ch;
			if (ch == '#') {
				response[TotalBytes] = '\0';
				break;
			}
		} else {
			usleep(10000, false); // 0.01 sec
			TimeOutCounts--;
		}
		if (TotalBytes >= MaxNumBytes) {
			response[TotalBytes-1] = '\0';
			break;
		}
	} while (TimeOutCounts > 0);

	return (TimeOutCounts <= 0);
}


int MirrorCover(bool open) {

//	if (open) {
//		cbDBitOut(USB1024BOARD0, FIRSTPORTA, USB1024_BITC4, 1);
//	} else {
//		cbDBitOut(USB1024BOARD0, FIRSTPORTA, USB1024_BITC4, 0);
//	}
	return true;
}

bool SpectroLampOnOff(bool On) {

	char Response[80];

	if (On) {
		SendObsCon("$SC_LON#", Response, sizeof(Response));
		if (strcmp(Response, "$SUCCESS#") != 0) {
			Form1::StatusPrint("*** Warning - Error turning on neon lamp\n");
			return false;
		}
	} else {
		SendObsCon("$SC_LOF#", Response, sizeof(Response));
		if (strcmp(Response, "$SUCCESS#") != 0) {
			Form1::StatusPrint("*** Warning - Error turning off neon lamp\n");
			return false;
		}
	}

	return true;
}


bool SelectPort(int port)
{
	int numStepsNeeded, nTries;
	char Message[120], Response[80];
	bool Success;

	Success = true;
	if ((port < 0) || (port > 5)) {  // check for valid port number
		Form1::StatusPrint("*** Warning - Invalid port number for instrument selector\n");
		Success = false;
	}

	if (Success) {
		if ((! ISSettings.Initialized) || (port == 0)) {
			Form1::StatusPrint("*** Info - Finding home...\n");
			usleep(500000,true);
			nTries = 0;
			do {
				SendObsCon("$IS_HOM#", Response, sizeof(Response));
				if (strcmp(Response, "$SUCCESS#") == 0) break;
				nTries++;
				usleep(100000, true);
			} while (nTries < 10);
			if (strcmp(Response, "$SUCCESS#") != 0) {
				sprintf_s(Message, sizeof(Message), "*** Warning - Can't find instrument selector home position (%s)\n",
					Response);
				Form1::StatusPrint(Message);
				Success = false;
			} else {
				ISSettings.CurrentPort = 0;
				ISSettings.CurrentStepPosition = 0;
				ISSettings.Initialized = true;
			}
		}
	}

	if (Success) {
		if (ISSettings.CurrentPort != port) {
			if (ISSettings.CurrentPort == 0) {
				numStepsNeeded = ISSettings.PortStepPositions[port-1];
				if (numStepsNeeded > 800)  // was 0 ALS - 08/10/11 
					numStepsNeeded -= 1600;
			} else {
				numStepsNeeded = ISSettings.PortStepPositions[port-1] - ISSettings.PortStepPositions[ISSettings.CurrentPort-1];
				if (numStepsNeeded > 800)  // was 0 ALS - 08/10/11
					numStepsNeeded -= 1600;
				else if (numStepsNeeded < -800) // was -1600 ALS - 08/10/11
					numStepsNeeded += 1600;
			}
			sprintf_s(Message, sizeof(Message), "*** Info - Stepping Instrument Selector by %d steps.\n", numStepsNeeded);
			Form1::StatusPrint(Message);
			usleep(500000,true);
			Success = StepSelectorMotor(numStepsNeeded);  // step them
			if (Success) {
				ISSettings.CurrentPort = port;
				ISSettings.CurrentStepPosition = ISSettings.PortStepPositions[port-1];
				Form1::StatusPrint("*** Info - Instrument Selector set to requested port.\n");
			} else {
				Form1::StatusPrint("*** WARNING - Instrument Selector position unknown.\n");
				ISSettings.Initialized = false;
				ISSettings.CurrentPort = 0;
				Form1::SetInstrumentPortButtons((short) 0);
			}
		}
	}

	return Success;
}



bool StepSelectorMotor(short numSteps) {

	char Message[80], Response[160];
	int nTries;

	if (abs(numSteps) > 1600) {
		sprintf_s(Message, sizeof(Message),
			"*** Warning - too many steps in StepSelectorMotor: %i\n", numSteps);
		Form1::StatusPrint(Message);
		return false;
	}

	// Do Steps

	sprintf_s(Message, sizeof(Message), "$IS_STE %d#", numSteps);
	nTries = 0;
	do {
		SendObsCon(Message, Response, sizeof(Response));
		if (strcmp(Response, "$SUCCESS#") == 0) break;
		nTries++;
	} while (nTries < 10);
	if (strcmp(Response, "$SUCCESS#") != 0) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Error stepping instrument selector: %s\n", Response);
		Form1::StatusPrint(Message);
		return false;
	}

	return true;
}

bool StepMicrometerMotor(short numSteps) {

	bool StepCW;
	char Message[80], Response[80];

	StepCW = (numSteps > 0);
	numSteps = abs(numSteps);
	if (numSteps > 1000) {
		sprintf_s(Message, sizeof(Message),
			"*** Warning - too many steps in StepMicrometerMotor: %i\n", numSteps);
		Form1::StatusPrint(Message);
		return false;
	}

	sprintf_s(Message, sizeof(Message), "$SC_STE %d", numSteps);
	SendObsCon(Message, Response, sizeof(Response));
	if (strcmp(Response, "$SUCCESS#") != 0) {
		Form1::StatusPrint("*** Warning - Error stepping instrument selector\n");
		return false;
	}

	return true;
}


bool PowerOnOff(short OutletNum, bool On)
{
//	static short OutletBit[4]={1,2,4,8};
	char Message[80], Response[80];
	bool success;

	if ((OutletNum < 1) || (OutletNum > 8)) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Outlet # not valid: %d\n",
			OutletNum);
		Form1::StatusPrint(Message);
		success = false;
	} else if ((OutletNum >= 1) && (OutletNum <= 4)) {
		success = RoboFocuser::Ptr->SetUserButtonOnOff(OutletNum, On);
	} else {
		if (On)
			sprintf_s(Message, sizeof(Message), "$AC_ON %d#", OutletNum-5);
		else
			sprintf_s(Message, sizeof(Message), "$AC_OFF %d#", OutletNum-5);
		success = SendObsCon(Message, Response, sizeof(Response));
	}

	if (!success) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Can't turn on/off AC power to port %d\n",
			OutletNum);
		Form1::StatusPrint(Message);
	}

	return success;
}


// Routines to control Digital Dome Works (dome control)


bool SendDDWText(char *text) {

	String ^buffer;

	if (! Form1::ComPortPtr->IsOpen) {
		Form1::StatusPrint("*** Warning - Trying to write to unopened com port (SendDDWText)\n");
		return false;
	}
	buffer = gcnew String(text);
	Form1::ComPortPtr->Write(buffer);
	return true;

}


int GetDDWText(char *buffer, short MaxNBytes, short timeout) {

	short TotalBytes, TimeOutCounts;
	char ch;

	// Check if port open

	if (! Form1::ComPortPtr->IsOpen) {
		Form1::StatusPrint("*** Warning - Trying to read from unopened com port (GetDDWText)\n");
		return false;
	}

	// Check for any characters waiting

	TotalBytes = 0;
	if (Form1::ComPortPtr->BytesToRead <= 0) {
		buffer[0] = '\0';
		return 0;
	}
	do {
		ch = Form1::ComPortPtr->ReadChar();
		if (ch == 13) {
			buffer[TotalBytes] = '\0';
			break;
		} else
			buffer[TotalBytes++] = ch;
		TimeOutCounts = timeout;
		while ((Form1::ComPortPtr->BytesToRead <= 0) && (TimeOutCounts-- > 0))
			usleep(10000, false); // 0.01 sec
		if (TotalBytes >= MaxNBytes) {
			buffer[TotalBytes-1] = '\0';
			break;
		}
	} while (TimeOutCounts > 0);

	return TotalBytes;
}


bool GetDDWGinfResponse(DDW_INFO *DDWInfo, int timeout) {

	int nItems, nBytesRead, dummy;
	char *cptr, buffer[1024], message[2048];

	// Check if port open

	if (! Form1::ComPortPtr->IsOpen) {
		Form1::StatusPrint("*** Warning - Trying to read from unopened com port (SendDDWText)\n");
		return false;
	}

	// Wait for response in COM port, return if "timed-out"

//	usleep(500000, false); // wait 0.5 sec
	do {
		cptr = NULL;
		nBytesRead = GetDDWText(buffer, sizeof(buffer), 1000);
		if (nBytesRead > 0) {
			cptr = strchr(buffer,'V');
			if (cptr != NULL)
				break;
		}
		if ((nBytesRead > 0) && (GlobalDebug)) {  // Debuging
			sprintf_s(message,sizeof(message),"*** DEBUG - Response from DDW: %s (%d,%d)\n", buffer, nBytesRead, timeout);
			Form1::StatusPrint(message);
		}
//		usleep(1000, false);  // sleep for 1 ms
		timeout--;
		if (timeout <= 0) break;
	} while (true);
	if (cptr == NULL)
		return false;

	// Parse response into DDW_INFO structure

	nItems = sscanf_s(cptr, "V%hu,%hu,%hu,%hu,%hu,%hu,%hu,%hu,%d,%hu,%hu,%hu,%d,"
						 "%d,%d,%d,%d,%d,%d,%d,%hu",
		&DDWInfo->version, &DDWInfo->TicksPerRotation, &DDWInfo->HomePosition,
		&DDWInfo->CoastDistance, &DDWInfo->CurrentDomeAzimuth,
		&DDWInfo->Slaved, &DDWInfo->ShutterState, &DDWInfo->DSRState,
		&DDWInfo->Home, &DDWInfo->HomePositionCCWEdge,
		&DDWInfo->HomePositionCWEdge, &DDWInfo->UserPinStatus,
		&dummy, &dummy, &dummy, &dummy, &dummy, &dummy, &dummy, &dummy,
		&DDWInfo->ScopeAzimuth);
	if (nItems != 21) {
		sprintf_s(message,"*** Warning - Bad format in DDW GINF response: %s\n",
				buffer);
		Form1::StatusPrint(message);
		return false;
	}
	Observatory.DomeCountsPerDegreeCCW = Observatory.DomeCountsPerDegreeCW =
			DDWInfo->TicksPerRotation/((float) 360.0);
	Observatory.DomeCurrentAzimuth = DDWInfo->CurrentDomeAzimuth/Observatory.DomeCountsPerDegreeCW;
	Observatory.DomeHome = (DDWInfo->Home == 0);
	if (DDWInfo->ShutterState == 0)
		Observatory.ShutterPercentOpen = -99;
	else if (DDWInfo->ShutterState == 1)
		Observatory.ShutterPercentOpen = 0;
	else
		Observatory.ShutterPercentOpen = 100;
	Observatory.ScopeAzimuth = DDWInfo->ScopeAzimuth;

//	for (i=0; i<4; i++) 
//		Observatory.ACPower[i+4] = ((DDWInfo->UserPinStatus & (0x01<<i)) != 0);
	Observatory.DDWUserPins = DDWInfo->UserPinStatus;
	Observatory.DSRInterlock = DDWInfo->DSRState;

	return true;
}

bool CheckIfComPortExists(char *name) {

	array<String ^>^ serialPorts;
	String ^Name;

	Name = gcnew String(name);

	serialPorts = Form1::ComPortPtr->GetPortNames();

	for each(String^ port in serialPorts) {
		if (port->CompareTo(Name) == 0) {
			return true;
		}
	}

	return false;
}


bool DoDomeFunction(short function, short *value, bool state) {

	static DDW_INFO DDWInfo;
	static bool DDWBusy=false, First=true;;
	short current, nBytesRead, ntries, timeout;
	short TargetAzimuth, StartAzimuth, DiffAzimuth, diff;
	double LapsedSeconds;
	float percent, StartPercent;
	bool success;
	struct _timeb timebuffer;
	time_t StartTime, CurrentTime;
	char ch, buffer[1024], message[1124];
	String ^ComPortName;

	if (DDWBusy)
		return false;
	DDWBusy = true;

	if (First) {
		DDWInfo.LinkOpen = false;
		First = false;
	}

	success = false;
	switch (function) {
		case DDW_INIT: // Initialize connection to DDW
			Form1::StatusPrint("*** Info - Initializing dome control...\n");
			if (!CheckIfComPortExists(DDW_COM_PORT_NAME)) {
				sprintf_s(message, sizeof(message), "*** Warning - %s port does not exist for DDW (DoDomeFunctions)\n", DDW_COM_PORT_NAME);
				Form1::StatusPrint(message);
				DDWInfo.LinkOpen = false;
				break;
			}
			ComPortName = gcnew String(DDW_COM_PORT_NAME);
			Form1::ComPortPtr = gcnew SerialPort(ComPortName);
			Form1::ComPortPtr->Open();
			ntries = 0;
			do {
				ntries++;
				success = SendDDWText("GINF");
				if (! success) {
					Form1::StatusPrint("*** Warning - Can't send GINF to DDW (DDW_INIT)\n");
					continue;
				}
				usleep(500000,false);
				success = GetDDWGinfResponse(&DDWInfo,10);
				if (! success) {
					Form1::StatusPrint("*** Warning - Can't get response to GINF (DDW_INIT)\n");
					continue;
				}
			} while ((! success) && (ntries < 6));
			if (! success) break;
			if (ntries >= 6) {
				Form1::StatusPrint("*** Warning - Tried 6 times to connect, failed\n");
				DDWInfo.LinkOpen = false;
				break;
			}
			Form1::StatusPrint("*** Info - Done initializing dome control...\n");
			DDWInfo.LinkOpen = true;
			success = true;
			break;
		case DDW_CLOSE: // Close connection to DDW
			if (! DDWInfo.LinkOpen) break;
			Form1::ComPortPtr->Close();
			DDWInfo.LinkOpen = false;
			success = true;
			break;
		case DDW_OPEN_SHUTTER:
			if (! DDWInfo.LinkOpen) break;
			if (DDWInfo.DSRState != DDW_DSR_CLOSED) {
				Form1::StatusPrint("*** WARNING - DSR must be closed before opening shutter!\n");
				break;
			}
			SendDDWText("GOPN");
			_ftime64_s(&timebuffer);
			StartTime = timebuffer.time;
			if (Observatory.ShutterPercentOpen < 0)
				Observatory.ShutterPercentOpen = 0;
			StartPercent = ((float) Observatory.ShutterPercentOpen);
			if (! ProgressDialogExists)
				gcnew ProgressDialog();
			ProgressDialog::FormPtr->SetLabel("Dome Shutter Opening Progress");
			ProgressDialog::FormPtr->ShowTheDialog();
			ProgressDialog::FormPtr->SetProgressBarValue(((int) StartPercent));
			LapsedSeconds = 0.0;
			do {
				usleep(10000, true); // 0.01 sec
				nBytesRead = GetDDWText(buffer,sizeof(buffer),100);
				if (nBytesRead > 1) {
					ch = buffer[0];
					if (ch == 'S') {  // SZdd  current value of shutter motor current
						sscanf_s(buffer,"SZ%hd", &current);
						if (current > 27) {
							SendDDWText("GSTP");
							sprintf_s(message,sizeof(message),"*** Warning - Stopped shutter open due to large current: %d\n",
								current);
							Form1::StatusPrint(message);
							break;
						}
					} else if (ch == 'V') { // INF sent, must be fully open
						break;
					}
				}
				_ftime64_s(&timebuffer);
				CurrentTime = timebuffer.time;
				LapsedSeconds = difftime(CurrentTime,StartTime+10);
				if (LapsedSeconds > Observatory.ShutterOpenCloseTime) {
					Form1::StatusPrint("*** Warning - Timed out waiting from shutter to open (DDW_OPEN_SHUTTER)\n");
					break;
				}
				percent = StartPercent + ((float) (LapsedSeconds/Observatory.ShutterOpenCloseTime * 100.0));
				if (percent > 100.0) percent = 100.0;
				if (percent < 0.0) percent = 0.0;
				ProgressDialog::FormPtr->SetProgressBarValue(((int) percent));
				Observatory.ShutterPercentOpen = ((int) percent);
				if (ProgressDialog::FormPtr->CancelRequested) {
					SendDDWText("GSTP");
					break;
				}
			} while (true);
			ProgressDialog::FormPtr->HideTheDialog();
			if (percent > 100.0)
				percent = 100.0;
			else if (percent < 0.0)
				percent = 0.0;
			Observatory.ShutterPercentOpen = ((int) percent);
			success = true;
			break;
		case DDW_CLOSE_SHUTTER:
			if (! DDWInfo.LinkOpen) break;
			if (! Observatory.DomeHome) {
				Form1::StatusPrint("*** Warning - Dome not home, move dome home first...\n");
				break;
			}
			if (DDWInfo.DSRState != DDW_DSR_CLOSED) {
				Form1::StatusPrint("*** WARNING - DSR must be closed before closing shutter!\n");
				break;
			}
			SendDDWText("GCLS");
			_ftime64_s(&timebuffer);
			StartTime = timebuffer.time;
			if (Observatory.ShutterPercentOpen < 0)
				Observatory.ShutterPercentOpen = 100;
			StartPercent = ((float) Observatory.ShutterPercentOpen);
			if (! ProgressDialogExists)
				gcnew ProgressDialog();
			ProgressDialog::FormPtr->SetLabel("Dome Shutter Closing Progress");
			ProgressDialog::FormPtr->ShowTheDialog();
			ProgressDialog::FormPtr->SetProgressBarValue(((int) (99.9-StartPercent)));
			do {
				usleep(10000, true); // 0.01 sec
				nBytesRead = GetDDWText(buffer,sizeof(buffer),100);
				if (nBytesRead > 1) {
					ch = buffer[0];
					if (ch == 'S') {  // SZdd  current value of shutter motor current
						sscanf_s(buffer,"SZ%hd", &current);
						if (current > 27) {
							SendDDWText("GSTP");
							sprintf_s(message,sizeof(message),"*** Warning - Stopped shutter close due to large current: %d\n",
								current);
							Form1::StatusPrint(message);
							break;
						}
					} else if (ch == 'V') { // inf response must be fully closed
						break;
					}
				}
				_ftime64_s(&timebuffer);
				CurrentTime = timebuffer.time;
				LapsedSeconds = difftime(CurrentTime,StartTime);
				if (LapsedSeconds > Observatory.ShutterOpenCloseTime+10) {
					Form1::StatusPrint("*** Warning - Timed out waiting from shutter to close (DDW_CLOSE_SHUTTER)\n");
					break;
				}
				percent = StartPercent - ((float) (LapsedSeconds/Observatory.ShutterOpenCloseTime * 100.0));
				if (percent < 0.0) percent = 0.0;
				if (percent > 100.0) percent = 100.0;
				Observatory.ShutterPercentOpen = ((int) percent);
				ProgressDialog::FormPtr->SetProgressBarValue(((int) (99.9-percent)));
				if (ProgressDialog::FormPtr->CancelRequested) {
					SendDDWText("GSTP");
					break;
				}
			} while (true);
			ProgressDialog::FormPtr->HideTheDialog();
			if (percent > 100.0)
				percent = 100.0;
			else if (percent < 0.0)
				percent = 0.0;
			Observatory.ShutterPercentOpen = ((int) percent);
			success = true;
			break;
		case DDW_ROTATE_DOME:
			success = false;
			if (! DDWInfo.LinkOpen) break;
			if (Observatory.DomeHome) {
				if (DDWInfo.DSRState != DDW_DSR_CLOSED) {
					Form1::StatusPrint("*** WARNING - DSR must be closed before rotating dome!\n");
					break;
				}
			}
			StartAzimuth = ((short) Observatory.DomeCurrentAzimuth);
			TargetAzimuth = *value;
			DiffAzimuth = TargetAzimuth - StartAzimuth;
			if (DiffAzimuth < -180) {
				DiffAzimuth += 360;
			} else if (DiffAzimuth > 180) {
				DiffAzimuth -= 360;
			}
			DiffAzimuth = abs(DiffAzimuth);
			sprintf_s(message, sizeof(message), "*** Info - rotating dome by %d degrees.\n", DiffAzimuth);
			Form1::StatusPrint(message);
			usleep(200000,true);
			sprintf_s(buffer, sizeof(buffer), "G%03d", TargetAzimuth);
			SendDDWText(buffer);
			if (! ProgressDialogExists)
				gcnew ProgressDialog();
			sprintf_s(buffer, sizeof(buffer), "Rotating dome by %d degrees", DiffAzimuth);
			ProgressDialog::FormPtr->SetLabel(buffer);
			ProgressDialog::FormPtr->SetProgressBarValue(0);
			ProgressDialog::FormPtr->ShowTheDialog();
			usleep(1000000, true);  // 1.0 sec pause to let function start
			timeout = 50;
			do {
				usleep(10000, true); // 0.01 sec
				nBytesRead = GetDDWText(buffer,sizeof(buffer),100);
				if (nBytesRead > 1) {
					ch = buffer[0];
					if (ch == 'P') {  // Pdd  current position in ticks
						sscanf_s(buffer,"P%hd", &current);
						sprintf_s(buffer, sizeof(buffer), "%4.0f", current/Observatory.DomeCountsPerDegreeCW);
						Form1::SetDomeAzTextBox(buffer);
						timeout = 50; // reset timeout counter (used to check if dome stuck)
					} else if (ch == 'V') { // info response must be at target azimuth
						success = true;
						break;
					}
				} else {
					usleep(100000,true);
					timeout--;  // counter to watch for dome stuck
					if (timeout <= 0) {
						SendDDWText("GSTP");
						Form1::StatusPrint("*** WARNING - Dome is stuck, stopped rotation...\n");
						break;
					}
				}
				diff = ((short) (TargetAzimuth - current/Observatory.DomeCountsPerDegreeCW));
				if (diff < -180)
					diff += 360;
				else if (diff > 180)
					diff -= 360;
				percent = ((float) ((1.0-abs(diff)/((float) DiffAzimuth))*100));
				if (percent < 0.0) percent = 1.0;
				if (percent > 100.0) percent = 100.0;
				ProgressDialog::FormPtr->SetProgressBarValue(((int) percent));
				if (ProgressDialog::FormPtr->CancelRequested) {
					SendDDWText("GSTP");
					Form1::StatusPrint("*** Info - Dome rotation canceled by user\n");
					break;
				}
			} while (true);
			ProgressDialog::FormPtr->HideTheDialog();
			break;
		case DDW_HOME_DOME:
			success = false;
			if (! DDWInfo.LinkOpen) break;
			SendDDWText("GHOM");
			Form1::StatusPrint("*** Info - Dome is moving home...\n");
			usleep(1000000, true);  // 1.0 sec pause to let function start
			timeout = 50;
			do {
				usleep(10000, true); // 0.01 sec
				nBytesRead = GetDDWText(buffer,sizeof(buffer),100);
				if (nBytesRead > 1) {
					ch = buffer[0];
					if (ch == 'P') {  // Pdd  current position in ticks
						sscanf_s(buffer,"P%hd", &current);
						sprintf_s(buffer, sizeof(buffer), "%4.0f", current/Observatory.DomeCountsPerDegreeCW);
						Form1::SetDomeAzTextBox(buffer);
						timeout = 50; // reset timeout counter (used to check if dome stuck)
					} else if (ch == 'V') { // inf response must be at target azimuth
						success = true;
						break;
					}
				} else {
					usleep(100000,true);
					timeout--;  // counter to watch for dome stuck
					if (timeout <= 0) {
						SendDDWText("GSTP");
						Form1::StatusPrint("*** WARNING - Dome is stuck, stopped rotation...\n");
						break;
					}
				}
			} while (true);
			if (success) 
				Form1::StatusPrint("*** Info - Dome is home...\n");
			break;
		case DDW_GET_DOME_POSITION:
			if (! DDWInfo.LinkOpen) break;
			Form1::StatusPrint("*** Warning - Function not implimented yet...\n");
			success = false;
			break;
		case DDW_TRAIN_DOME:
			if (! DDWInfo.LinkOpen) break;
			Form1::StatusPrint("*** Warning - Function not implimented yet...\n");
			success = false;
			break;
		case DDW_STOP:
			if (! DDWInfo.LinkOpen) break;
			Form1::StatusPrint("*** Warning - Function not implimented yet...\n");
			success = false;
			break;
		case DDW_SET_USER_PINS:
			if (! DDWInfo.LinkOpen) break;
			if (state)   // Turn On
				Observatory.DDWUserPins = Observatory.DDWUserPins | *value;
			else {   // Turn Off
				*value = ~ *value;
				Observatory.DDWUserPins = Observatory.DDWUserPins & *value;
			}
			sprintf_s(buffer,sizeof(buffer), "GP%02X", Observatory.DDWUserPins);
			SendDDWText(buffer);
			usleep(2000000,true);
			GetDDWGinfResponse(&DDWInfo, 5000);
			Observatory.DDWUserPins = DDWInfo.UserPinStatus;
//			for (i=0; i<4; i++) 
//				Observatory.ACPower[i+4] = ((DDWInfo.UserPinStatus & (0x01<<i)) != 0);
			success = true;
			break;
		case DDW_GET_DOME_STATUS:
			if (! DDWInfo.LinkOpen) break;
			ntries = 0;
			do {
				SendDDWText("GINF");
				usleep(100000,false);
				success = GetDDWGinfResponse(&DDWInfo,10);
				if (success)
					break;
				ntries++;
			} while (ntries < 6);
			if (! success) {
				Form1::StatusPrint("*** Warning - Can't get response to GINF (DDW_GET_DOME_STATUS)\n");
				break;
			}
			success = true;
			break;
	}

	if (!success) {
		sprintf_s(message, sizeof(message), "*** Warning - Failed completing Dome function: %hi (DoDomeFunction)\n", function);
		Form1::StatusPrint(message);
	}

	DDWBusy = false;
	return success;

}


bool SendScopeCommand(char *Command, char *Response, short timeout) {

	String ^buffer;
	char ch;
	bool success;
	int i, wait;

	success = false;
	if (! Form1::ScopeComPortPtr->IsOpen) {
		Form1::StatusPrint("*** Warning - Trying to write to unopened com port (SendScopeCommand)\n");
	} else {
		if (Form1::ScopeComPortPtr->BytesToRead > 0) {  // Flush read buffer
			do {
				ch = Form1::ScopeComPortPtr->ReadChar();
			} while (Form1::ScopeComPortPtr->BytesToRead > 0);
		}
		buffer = gcnew String(Command);                 // Send command
		Form1::ScopeComPortPtr->Write(buffer);
		
		if (Command[0] == '\006') {  // Get response from "ACK" command
			do {
				usleep(500000, true);
				timeout--;
			} while ((Form1::ScopeComPortPtr->BytesToRead <= 0) && (timeout > 0));
			if (timeout <= 0) {
				Form1::StatusPrint("*** Warning - Timed-out waiting for ACK response (SendScopeCommand)\n");
			} else {
				Response[0] = Form1::ScopeComPortPtr->ReadChar();
				Response[1] = '\000';
				success = true;
			}
		} else if (strcmp(Command,":gT#") == 0) {  // Get response from GPS fix command
			do {
				usleep(500000, true);
				timeout--;
			} while ((Form1::ScopeComPortPtr->BytesToRead <= 0) && (timeout > 0));
			if (timeout <= 0) {
				Form1::StatusPrint("*** Warning - Timed-out waiting for GPS Fix (SendScopeCommand)\n");
			} else {
				Response[0] = Form1::ScopeComPortPtr->ReadChar();
				Response[1] = '\000';
				success = true;
			}
		} else if (strcmp(Command,":hP#") == 0) {  // Park command has no response...
			success = true;
		} else if (Command[1] == 'R') { // Set slew rate command, no response...
			success = true;
		} else if (Command[1] == 'F') { // Focus commands, no response...
			success = true;
		} else if (Command[1] == 'M') { // Move command, only slew to target has response
			if (Command[2] != 'S')
				success = true;
		} else if (Command[1] == 'Q') { // Stop slew command has no response
			success = true;
		} else if (Command[1] == 'G') { // Get response for "Get" command
			i = 0;
			do {
				wait = 0;
				while ((Form1::ScopeComPortPtr->BytesToRead <= 0) && (wait < 1000)) {
					wait++;
					usleep(1000,true);
				}
				if (wait >= 1000) {
					Form1::StatusPrint("*** Warning - timed-out getting scope GET command response.\n");
					break;
				}
				ch = Form1::ScopeComPortPtr->ReadChar();
				Response[i++] = ch;
				success = (ch == '#');
			} while (! success);
			Response[i] = '\000';
		}
	}

	return success;

}

bool PowerOnScope(void) {

	float val1, val2;
	int i;
	//char buffer[160];

	if (!PowerOnOff(ACPOWER_PORT_SCOPE, ACPOWER_ON)) {
		Form1::StatusPrint("*** Warning - failed turning on scope (PowerOnScope)\n");
		return false;
	}
	Form1::StatusPrint("*** Info - Turning on scope, wait for 1-2 minutes to initialize...\n");
	Form1::StatusPrint("*** Info - I will let you know when its ready...\n");
	for (i=0; i<70; i++) {
		//sprintf_s(buffer, sizeof(buffer), "*** Info - Seconds to wait: %d\r", 70-i);
		// Form1::StatusPrint(buffer);
		usleep(1000000, true);
	}
	Form1::StatusPrint("*** Info - It should be up by now.\n");
	Form1::StatusPrint("*** Info - Linking to Scope...\n");
	val1 = val2 = 1.0;
	DontUpdateNow(true);
	DoScopeFunction(SCOPE_INIT, &val1, &val2, true);
	usleep(1000000, true);
	Form1::StatusPrint("*** Info - Now having scope do GPS fix.\n");
	usleep(1000000, true);
	DoScopeFunction(SCOPE_GPS_INIT, &val1, &val2, true);
	Form1::StatusPrint("**** Info - Scope should be all ready to go.\n");
	DontUpdateNow(false);

	return true;
}

bool PowerOffScope(void) {

	int answer;
	float nTries;
	bool state=false;

	if (! ScopeInfo.Parked) {
		answer = MessageBox("Has scope been parked?", YESNO);
		if (answer == CANCEL) {
			return false;
		} else if (answer == NO) {
			answer = MessageBox("Sure you want to turn off scope without parking?", YESNO);
			if ((answer == CANCEL) || (answer == NO))
				return false;
		}
	}
	if (ScopeInfo.LinkOpen) {
		DontUpdateNow(true);
		DoScopeFunction(SCOPE_CLOSE, &nTries, &nTries, state);
		DontUpdateNow(false);
	}
	PowerOnOff(ACPOWER_PORT_SCOPE, ACPOWER_OFF);
	usleep(2000000, true);
	Form1::StatusPrint("*** Info - Scope should be off.\n");
	return true;

}


bool DoScopeFunction(short function, float *value1, float *value2, bool state) {

	static bool ScopeBusy=false, First=true;
	int ntries;
	float dec, ra;
	double delra, deldec;
	bool success;
	char Ack[2]={6,0}, Response[80], Message[160], command[10];
	int delay;
	double radouble, decdouble, azdouble, altdouble;

	if (function == SCOPE_CLEAR_BUSY) {
		ScopeBusy = false;
		return true;
	}

	if (ScopeBusy) {
		sprintf_s(Message, sizeof(Message), "*** Info - scope busy for function: %d...\n", function);
		Form1::StatusPrint(Message);
		return false;
	}
	ScopeBusy = true;

	if (First) {
		ScopeInfo.LinkOpen = false;
		First = false;
	}

	success = false;
	switch (function) {

		case SCOPE_INIT: // Initialize connection to scope
			if (ScopeInfo.LinkOpen) {
				Form1::StatusPrint("*** Warning - Link to scope already open.\n");
				success = true;
				break;
			}
			Form1::StatusPrint("*** Info - Initializing connection to scope...\n");
			success = Scope_EstablishLink();
			if (success) {
				Form1::StatusPrint("*** Info - Connection established to scope.\n");
				ScopeInfo.LinkOpen = true;
			} else {
				Form1::StatusPrint("*** Warning - Connection to scope failed.\n");
			}
			break;

		case SCOPE_CLOSE: // Close connection to scope
			if (! ScopeInfo.LinkOpen) {
				Form1::StatusPrint("*** Warning - Can't close link to scope, its not open.\n");
				break;
			}
			success = Scope_UnLink();
			if (success) {
				Form1::StatusPrint("*** Info - Connection to scope is closed.\n");
				ScopeInfo.LinkOpen = false;
			} else {
				Form1::StatusPrint("*** Warning - Can't close connection to scope.\n");
			}
			break;

		case SCOPE_GPS_INIT:
			if (! ScopeInfo.LinkOpen) {
				Form1::StatusPrint("*** Warning - Can't init GPS, open link to scope first.\n");
				break;
			}
			Form1::StatusPrint("*** INFO - Not doing init GPS's until know why it doesn't work...\n");
			success = true;
			break;
			Form1::StatusPrint("*** Info - Doing GPS fix should take < 30 secs.  I'll wait...\n");
			usleep(1000000, true);
			Scope_SendCommandBlind(":gT#");
			usleep(30000000,true);
			Form1::StatusPrint("*** Info - Should be done.\n");
			success = true;
			break;

		case SCOPE_PARK:
			if (! ScopeInfo.LinkOpen) {
				Form1::StatusPrint("*** Warning - Can't park scope, open link to scope first.\n");
				break;
			}
			success = Scope_Park();
			Form1::StatusPrint("*** Warning - Be sure to wait at least 60 seconds\n"
							   "              before turning off scope power after parking scope.\n");
			break;

		case SCOPE_UNPARK:
			if (! ScopeInfo.LinkOpen) break;
			success = false;
			break;

		case SCOPE_MOVE:
			success = false;
			if (! ScopeInfo.LinkOpen) {
				Form1::StatusPrint("*** Can't move scope to coordinates. Link to scope first...\n");
				break;
			}
			ra = *value1;
			dec = *value2;

			Scope_SlewToCoordinates(ra, dec, true);
			break;

		case SCOPE_JOG_NORTH:
		case SCOPE_JOG_SOUTH:
		case SCOPE_JOG_EAST:
		case SCOPE_JOG_WEST:
			success = false;
			if (! ScopeInfo.LinkOpen) {
				Form1::StatusPrint("*** Can't jog scope, link to scope first...\n");
				break;
			}
			if ((*value2 < 0.0) || (*value2 > 60.0)) {
				sprintf_s(Message, "*** Warning - Scope jog time too big: %f (doScopeFunction)\n", *value2);
				Form1::StatusPrint(Message);
				break;
			}
			delay = (int) (*value2 * 1000000.0); // convert from secs to microsecs
			Scope_Jog(function-SCOPE_JOG_NORTH+1, *value1, true);
			usleep(delay, true);
			Scope_Jog(function-SCOPE_JOG_NORTH+1, *value1, false);
			success = true;
			break;

		case SCOPE_BUMP:
			success = false;
			if (! ScopeInfo.LinkOpen) {
				Form1::StatusPrint("*** Can't bump scope, link to scope first...\n");
				break;
			}

			delra = *value1/Math::Cos(ScopeInfo.DEC*DEG2RAD);  // convert to arcminutes
			deldec = ((float) (*value2));
			success = Scope_BumpArcMin(delra, deldec);
			if (success) {
				sprintf_s(Message, sizeof(Message), "*** Info - Bumped scope by %7.2lf, %7.2lf arcmin.\n",
					delra, deldec);
				Form1::StatusPrint(Message);
			} else {
				sprintf_s(Message, sizeof(Message), "*** Warning - Failed to bumped scope by %7.2lf, %7.2lf arcmin.\n",
					delra, deldec);
				Form1::StatusPrint(Message);
			}
			break;

		case SCOPE_FOCUS:
			if (! ScopeInfo.LinkOpen) {
				Form1::StatusPrint("*** Can't step focus, link to scope first...\n");
				break;
			}
			success = false;

			ntries = 0;
			do {
				success = SendScopeCommand(":F2#", Response, 20); // Set Focuser speed to 2nd slowest
				ntries++;
			} while ((! success) && (ntries < 5));
			if (! success) {
				Form1::StatusPrint("*** Warning - Can't set focuser speed (DoScopeFunction)\n");
				break;
			}
			if (*value1 > 0) {
				strcpy_s(command, sizeof(command), ":F+#");
			} else {
				strcpy_s(command, sizeof(command), ":F-#");
			}
			delay = ((int) (fabs(*value1)*1000000));
			ntries = 0;
			do {
				success = SendScopeCommand(command, Response, 20); // Start focuser moving
				ntries++;
			} while ((! success) || (ntries < 5));
			if (! success) {
				Form1::StatusPrint("*** Warning - Can't start focuser (DoScopeFunction)\n");
				break;
			}
			usleep(delay,true);
			ntries = 0;
			do {
				success = SendScopeCommand(":FQ#", Response, 20); // Stop focuser
				ntries++;
			} while ((! success) || (ntries < 5));
			if (! success) {
				Form1::StatusPrint("*** WARNING! - Can't stop focuser (DoScopeFunction)\n");
				break;
			}
			break;

		case SCOPE_GET_POSITION:
			if (! ScopeInfo.LinkOpen) break;
			success = false;

			// Get RA & DEC

			success = Scope_GetRADEC(&radouble, &decdouble);
			ScopeInfo.RA = (float) radouble;
			ScopeInfo.DEC = (float) decdouble;

			// Get Altitude and Azimuth

			success = Scope_GetAltAz(&altdouble, &azdouble);
			ScopeInfo.Az = (float) azdouble;
			ScopeInfo.Alt = (float) altdouble;
			break;
	}

	ScopeBusy = false;
	return success;

}

void SyncDomeScope(void) {

	float TransformedAz, DiffAz;
	short targetAz;
	static float OldRA, OldDEC, DiffRA, DiffDEC;
	static bool First=true;

	if (ScopeInfo.RA < 0.0)  // Scope position unknown
		return;

	if (First) {
		OldRA = ScopeInfo.RA;
		OldDEC = ScopeInfo.DEC;
		First = false;
	}
	DiffRA = ((float) fabs(ScopeInfo.RA - OldRA));
	DiffDEC = ((float) fabs(ScopeInfo.DEC - OldDEC));
	OldRA = ScopeInfo.RA;
	OldDEC = ScopeInfo.DEC;
	if ((DiffRA*Math::Cos(ScopeInfo.DEC) > 0.1) || (DiffDEC > 1.5))
		return;
	if ((ScopeInfo.Az >= 0.0) && (ScopeInfo.Az <= 360.0)) {
		TransformedAz = TransformAz(ScopeInfo.Az, ScopeInfo.Alt);
		DiffAz = ((float) (fabs(((double) Observatory.DomeCurrentAzimuth)-((double) TransformedAz))));
		if (DiffAz > 5.0) {
			targetAz = ((short) TransformedAz);
			DoDomeFunction(DDW_ROTATE_DOME, &targetAz, true);
		}
	}

}

float TransformAz(float Az, float Alt) {

	double Phi_t, Theta_t, SinTht, CosTht, SinPht, CosPht, Rho_t1, Rho_t2, Rho_t;
	double newAz, delta, Theta_d, Xd, Yd;

	Phi_t = 90.0 - Alt;
	Theta_t = 360.0 - Az;
	SinTht = Math::Sin(Theta_t*DEG2RAD);  CosTht = Math::Cos(Theta_t*DEG2RAD);
	SinPht = Math::Sin(Phi_t*DEG2RAD);    CosPht = Math::Cos(Phi_t*DEG2RAD);
	Rho_t1 = - (Math::Sqrt(-36*SinPht*SinPht*SinTht*SinTht + 48*CosPht*SinPht*CosTht + 20*SinPht*SinPht + 189) +
				6*SinPht*CosTht + 4*CosPht)/2;
	Rho_t2 = (Math::Sqrt(-36*SinPht*SinPht*SinTht*SinTht + 48*CosPht*SinPht*CosTht + 20*SinPht*SinPht + 189) -
				6*SinPht*CosTht - 4*CosPht)/2;
//	Rho_t1 = - Rho_t1;
//	Rho_t2 = - Rho_t2;
	if (Rho_t1 > 0.0)
		Rho_t = Rho_t1;
	else if (Rho_t2 > 0.0)
		Rho_t = Rho_t2;
	else {
		Form1::StatusPrint("*** Warning - No valid solution in TransformAz.\n");
		delta = 1.6*Math::Atan(SCOPEDOMEOFFSET/DOMERADIUS*fabs(Math::Sin(((double) Az)*3.14159/180.0)))*180.0/3.14159;
		if (Az < 180) {
			newAz = Az - delta;
		} else {
			newAz = Az + delta;
		}
		return ((float) newAz);
	}
	Xd = Rho_t*SinPht*CosTht + 3.0;
	Yd = Rho_t*SinPht*SinTht;
	Theta_d = Math::Acos(Xd/Math::Sqrt(Xd*Xd+Yd*Yd))*RAD2DEG + 5.0;  // 5 deg added after checking ALS
//	newAz = 360.0 - Theta_d;
	delta = 1.6*Math::Atan(SCOPEDOMEOFFSET/DOMERADIUS*fabs(Math::Sin(((double) Az)*3.14159/180.0)))*180.0/3.14159;
	if (Az <= 180.0)
		newAz = Theta_d;
	else
		newAz = 360.0 - Theta_d;

	return ((float) newAz);
}

bool ProcessMessages(void) {

	FILE *fptr;
	char request[80], command, Message[160], RA[80], DEC[80];
	char response[80];
	int DelRATime, DelDECTime, dir;
	int nItems, FWPosition;
	int NumSteps, CurrentFocusPosition, NewFocusPosition;
	double delra, deldec;
	float DelRAMin, DelDECMin, dummy;
	bool success;
	short dum;
	static bool Busy=false;

	if (Busy) {
		if (GlobalDebug)
			Form1::StatusPrint("*** Debug - ProcessMessages busy...\n");
		return true;
	}

	Busy = true;

	fopen_s(&fptr, MESSAGEFILENAME, "r");
	if (fptr == NULL) {
		Busy = false;
		return true;
	}

	if (fgets(request, sizeof(request), fptr) == NULL) {
		fclose(fptr);
		Busy = false;
		return true;
	}
	fclose(fptr);
	_unlink(MESSAGEFILENAME);

	success = false;
	command = request[0];
	switch(command) {
		case 'C':  // close observatory command

				// Home the dome if not already there

			if (! Observatory.DomeHome) {
				Form1::StatusPrint("*** Info - Sending dome to home position\n");
				success = DoDomeFunction(DDW_HOME_DOME, &dum, true);
				if (! success) {
					Form1::StatusPrint("WARNING - Can't home dome, can't close shutter."
						"PLEASE MANUALLY CLOSE!");
				}
			} 
				// Close the shutter

			if (Observatory.DomeHome) {
				Form1::StatusPrint("*** Info - Closing shutter, will take about 2 minutes.\n");
				success = DoDomeFunction(DDW_CLOSE_SHUTTER, &dum, true);
				if (! success) {
					Form1::StatusPrint("WARNING - Can't close shutter. PLEASE MANUALLY CLOSE! Click okay when done");
				}
			}
				// Park the scope

			if (! ScopeInfo.LinkOpen) {
				success = DoScopeFunction(SCOPE_INIT, &dummy, &dummy, true);
				if (! success) {
					Form1::StatusPrint("*** WARNING - can't link to scope, can't park it.");
				}
			}
			if (ScopeInfo.LinkOpen) {
				success = DoScopeFunction(SCOPE_PARK, &dummy, &dummy, true);
				if (! success) {
					Form1::StatusPrint("*** WARNING - can't park scope, will lose alignment.");
				}
			} else {
				Form1::StatusPrint("*** WARNING - can't park scope, will lose alignment.");
			}

			Form1::StatusPrint("*** Info - Turning off scope & ccds\n");
			PowerOnOff(ACPOWER_PORT_CCD, ACPOWER_OFF);
			PowerOffScope();
			Form1::StatusPrint("*** Info - Observatory is closed\n");
			Form1::CloseObservatory();
			WriteResponse("Success");

			// Exit OSUrob so if anything failed, at least dome hardware will close observatory.

			Busy = false;
			Application::Exit();
			break;
		case 'F': // Move filter wheel command
			sscanf_s(request, "F %d", &FWPosition);
			sprintf_s(Message, "$FW_MOV %d#", FWPosition);
			SendObsCon(Message, response, sizeof(response));
			if (strcmp(response, "$SUCCESS#") == 0) {
				WriteResponse("Success");
				sprintf_s(Message, "%d", FWPosition);
				Form1::OSUrobForm->SetFWTextBox(Message);
				sprintf_s(Message, sizeof(Message), "%c", Observatory.FWPositions[FWPosition-1]);
				Form1::OSUrobForm->SetFWTextBox(Message);
				success = true;
			} else {
				sprintf_s(Message, sizeof(Message), "*** Warning - Error moving filter wheel: %s\n", response);
				Form1::StatusPrint(Message);
				WriteResponse(Message);
				Form1::OSUrobForm->SetFWTextBox("UNK");
				success = false;
			}
			break;
		case 'g': // Get current filter wheel position command
			SendObsCon("$FW_GET#", response, sizeof(response));
			nItems = sscanf_s(response, "$FW_AT %d#", &FWPosition);
			if (nItems == 1) {
				sprintf_s(Message, sizeof(Message), "Success: %d\n", FWPosition);
				WriteResponse(Message);
				sprintf_s(Message, sizeof(Message), "%c", Observatory.FWPositions[FWPosition-1]);
				Form1::OSUrobForm->SetFWTextBox(Message);
				success = true;
			} else {
				sprintf_s(Message, sizeof(Message), "*** Warning - Error getting filter wheel position: %s\n", response);
				Form1::StatusPrint(Message);
				WriteResponse(Message);
				Form1::OSUrobForm->SetFWTextBox("UNK");
				success = false;
			}
			break;

		case 'B': // Bump scope position command
			sscanf_s(request, "B %lf %lf", &delra, &deldec); // in degrees
			if ((fabs(delra) > 1.0) || (fabs(deldec) > 1.0)) {
				sprintf_s(Message, sizeof(Message), "*** Warning - Bump Scope size too large: (%lf,%lf) (ProcessMessages)\n",
					delra, deldec);
				Form1::StatusPrint(Message);
				WriteResponse(Message);
				break;
			}
			DelRAMin = (float) (delra*60.0);
			DelDECMin = (float) (deldec*60.0);
			success = DoScopeFunction(SCOPE_BUMP, &DelRAMin, &DelDECMin, true);
			if (success) {
				WriteResponse("Success");
			}
			break;
		case 'f': // Bump focuser command
			sscanf_s(request, "f %d", &NumSteps);
			if (abs(NumSteps) > 2000) {
				sprintf_s(Message, sizeof(Message), "*** Warning - Focuser # of steps too large: %i\n", NumSteps);
				Form1::StatusPrint(Message);
			} else {
				DontUpdateNow(true);
				CurrentFocusPosition = RoboFocuser::Ptr->GetPosition();
				NewFocusPosition = CurrentFocusPosition + NumSteps;
				success = RoboFocuser::Ptr->GoToPosition(NewFocusPosition);
				DontUpdateNow(false);
				if (! success) {
					Form1::StatusPrint("*** Warning - Can't step focuser\n");
					WriteResponse("*** Warning - Can't step focuser");
				} else {
					WriteResponse("Success");
				}
			}
			break;
		case 'G': // Get scope position command
			Form1::OSUrobForm->GetRATextBox(RA);
			Form1::OSUrobForm->GetDECTextBox(DEC);
			sprintf_s(Message, sizeof(Message), "Success: %s %s", RA, DEC);
			WriteResponse(Message);
			success = true;
			break;
		case 'A': // Autoguide scope using autoguider port (via USB1024 DIO)
			sscanf_s(request, "A %lf %lf", &delra, &deldec); // delra & deldec in arcsec.
			if ((fabs(delra) > 60.0) || (fabs(deldec) > 60.0)) {
				sprintf_s(Message, sizeof(Message), "*** Warning - Guiding size too large: (%lf,%lf) (ProcessMessages)\n",
					delra, deldec);
				Form1::StatusPrint(Message);
				WriteResponse(Message);
			} else {
				delra = delra*Math::Cos(ScopeInfo.DEC*DEG2RAD);
				DelRATime = (int) (fabs(delra) / GUIDINGRATE * 1000000);  // in microseconds
				DelDECTime = (int) (deldec / GUIDINGRATE * 1000000); // in microseconds
				DontUpdateNow(true);
				if (delra > 0.0) {
					dir = EAST;
				} else {
					dir = WEST;
				}
				OnOffGuiding(dir, ON);
				usleep(DelRATime, false); // don't do anything but wait.
				OnOffGuiding(dir, OFF);

				if (deldec < 0.0) {
					dir = NORTH;
				} else {
					dir = SOUTH;
				}
				OnOffGuiding(dir, ON);
				usleep(DelDECTime, false); // don't do anything but wait.
				OnOffGuiding(dir, OFF);
				DontUpdateNow(false);
				WriteResponse("Success");
				success = true;
			}
			break;
		default:
			sprintf_s(Message, sizeof(Message), "*** Warning - Invalid request from CCDAuto: %s\n", request);
			Form1::StatusPrint(Message);
			break;
	}

	Busy = false;
	return success;
}

void WriteResponse(char *Message) {

	FILE *fptr;

	fopen_s(&fptr, RESPONSEFILENAME, "w");
	if (fptr == NULL) {
		Form1::StatusPrint("*** Warning - can't send response to CCDAuto\n");
		return;
	}
	fprintf(fptr, "%s", Message);
	fclose(fptr);
	return;
}

void DontUpdateNow(bool state) {

	Form1::DontUpdate = state;

}

bool ConvertDECtoDMS(double dec, int *degs, int *mins, float *secs) {

	bool south;

	if ((dec < -90.0) || (dec > 90.0))
		return false;
	south = (dec < 0.0);
	dec = fabs(dec);
	*degs = (int) (Math::Floor(dec));
	*mins = (int) (Math::Floor((dec-*degs)*60.0));
	*secs = (float) ((dec - *degs - *mins/60.0)*3600.0);
	if (south) *degs = -*degs;

	return true;
}

bool ConvertRAtoHMS(double ra, int *hours, int *mins, float *secs) {

	if ((ra < 0.0) || (ra > 24.0))
		return false;
	*hours = (int) Math::Floor(ra);
	*mins = (int) (Math::Floor((ra-*hours)*60.0));
	*secs = (float) ((ra - *hours - *mins/60.0)*3600.0);

	return true;
}

bool ConvertDMStoDEC(int degs, int mins, float secs, double *dec) {

	bool valid;

	*dec = ((double) (abs(degs) + mins/60.0 + secs/3600.0));
	if (degs < 0) *dec = - *dec;

	valid = ((*dec >= -90.0) && (*dec <= 90.0));
	return valid;
}
bool ConvertHMStoRA(int hours, int mins, float secs, double *ra) {

	bool valid;

	*ra = ((double) (hours + mins/60.0 + secs/3600.0));

	valid = ((*ra >=0.0) && (*ra < 24.0));
	return valid;
}

void PrintStatus(char *text) {

	Form1::StatusPrint(text);
}

void GetLSTTextBox(char *text) {

	Form1::OSUrobForm->GetLSTTextBox(text);
	return;
}

void ShowMoveScopeDialog(void) {

	static bool Exists=false;

	if (! Exists) {
		gcnew MoveScopeDialog();
	}
	MoveScopeDialog::FormPtr->ShowTheDialog();
}



bool OnOffGuiding(int direction, bool On) {

	if ((direction < 1) || (direction > 4))
		return false;
	switch (direction) {
		case 1: // North
			if (On) {
				if (GlobalDebug)
					Form1::StatusPrint("*** Debug - Turning ON North guide slewing...\n");
//				cbDBitOut(USB1024BOARD0, FIRSTPORTA, GUIDESLEWINGNORTHBIT, 0); // ACTIVE LOW
			} else {
				if (GlobalDebug)
					Form1::StatusPrint("*** Debug - Turning OFF North guide slewing...\n");
//				cbDBitOut(USB1024BOARD0, FIRSTPORTA, GUIDESLEWINGNORTHBIT, 1); // ACTIVE LOW
				ScopeInfo.LastDECMoveWasNorth = true;
			}
			break;
		case 2: // South
			if (On) {
				if (GlobalDebug)
					Form1::StatusPrint("*** Debug - Turning ON South guide slewing...\n");
//				cbDBitOut(USB1024BOARD0, FIRSTPORTA, GUIDESLEWINGSOUTHBIT, 0); // ACTIVE LOW
			} else {
				if (GlobalDebug)
					Form1::StatusPrint("*** Debug - Turning OFF South guide slewing...\n");
//				cbDBitOut(USB1024BOARD0, FIRSTPORTA, GUIDESLEWINGSOUTHBIT, 1); // ACTIVE LOW
				ScopeInfo.LastDECMoveWasNorth = false;
			}
			break;
		case 3: // East
			if (On) {
				if (GlobalDebug)
					Form1::StatusPrint("*** Debug - Turning ON East guide slewing...\n");
//				cbDBitOut(USB1024BOARD0, FIRSTPORTA, GUIDESLEWINGEASTBIT, 0); // ACTIVE LOW
			} else {
				if (GlobalDebug)
					Form1::StatusPrint("*** Debug - Turning OFF East guide slewing...\n");
//				cbDBitOut(USB1024BOARD0, FIRSTPORTA, GUIDESLEWINGEASTBIT, 1); // ACTIVE LOW
				ScopeInfo.LastRAMoveWasEast = true;
			}
			break;
		case 4: // West
			if (On) {
				if (GlobalDebug)
					Form1::StatusPrint("*** Debug - Turning ON West guide slewing...\n");
//				cbDBitOut(USB1024BOARD0, FIRSTPORTA, GUIDESLEWINGWESTBIT, 0); // ACTIVE LOW
			} else {
				if (GlobalDebug)
					Form1::StatusPrint("*** Debug - Turning OFF West guide slewing...\n");
//				cbDBitOut(USB1024BOARD0, FIRSTPORTA, GUIDESLEWINGWESTBIT, 1); // ACTIVE LOW
				ScopeInfo.LastRAMoveWasEast = false;
			}
			break;
	}
	return true;
}


}
