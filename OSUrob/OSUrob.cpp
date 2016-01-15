// OSUrob.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

using namespace System;
using namespace System::IO;
using namespace System::Threading;
using namespace OSUrob;

static void OnUnhandled(Object^ sender, ThreadExceptionEventArgs^ e)
   {
	  float dummy=0.0;
	  bool  state=false;

      MessageBox::Show(e->Exception->Message, "Global Exeception");
	  if (e->Exception->Message == "Access to the port 'COM5' is denied.") {
		  Form1::StatusPrint("*** Warning - Can't link to scope, close scope link in other program first.\n");
	  }
	  DoScopeFunction(SCOPE_CLEAR_BUSY, &dummy, &dummy, state);
	  DontUpdateNow(false);
	  return;
   }





[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	FILE *fptr;
	short nItems;

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Setup/Initialize various data

	ExitMenuItemClicked = false;
	Observatory.SiteLatitude = SITE_LATITUDE;
	Observatory.SiteLongitude = SITE_LONGITUDE;
	strcpy_s(Observatory.SiteName,sizeof(Observatory.SiteName),"OSU-Lima Student Observatory");
	Observatory.Open = false;
	Observatory.EnclosureType = 2;  // dome
	Observatory.Debug = 0;  // no debugging
	Observatory.DomeCountsPerDegreeCCW = Observatory.DomeCountsPerDegreeCW = ((float) 2.98);
	Observatory.DomeCurrentAzimuth = -999.0; // unknown
	Observatory.DomeHomeAzimuth = 1.0;  // in degrees
	Observatory.DomeInitialized = false;
	Observatory.DomeLinked = false;  // dome not linked to scope
	Observatory.DomeSecondsPerDegreeCCW = 0.0;
	Observatory.DomeSecondsPerDegreeCW = 0.0;
	Observatory.HomeToOperateShutter = true;
	Observatory.ShutterPercentOpen = 0; // shutter not open;
	Observatory.ShutterOpenCloseTime = 100.0; // seconds
	strcpy_s(Observatory.FWPositions, sizeof(Observatory.FWPositions), "BVRIGHC");

	ScopeInfo.LastDECMoveWasNorth = true;
	ScopeInfo.LastRAMoveWasEast = true;

	// Read in instrument selector settings

	ISSettings.Initialized = false;
	fopen_s(&fptr, INSTRUMENTSELECTORSETTINGSFILE, "r");
	if (fptr == NULL) {
		ISSettings.PortStepPositions[0] = 614; // default CCD
		ISSettings.PortStepPositions[1] = 1006; // default Eye1
		ISSettings.PortStepPositions[2] = 1393; // default Spectro
		ISSettings.PortStepPositions[3] = 217;  // default Fiber
		ISSettings.PortStepPositions[4] = 1500; // default Park;
	} else {
		nItems = fscanf_s(fptr, "%hd %hd %hd %hd %hd", &ISSettings.PortStepPositions[0], &ISSettings.PortStepPositions[1],
			&ISSettings.PortStepPositions[2], &ISSettings.PortStepPositions[3], &ISSettings.PortStepPositions[4]);
		if (nItems != 5) {
			ISSettings.PortStepPositions[0] = 614; // default CCD
			ISSettings.PortStepPositions[1] = 1006; // default Eye1
			ISSettings.PortStepPositions[2] = 1393; // default Spectro
			ISSettings.PortStepPositions[3] = 217;  // default Fiber
			ISSettings.PortStepPositions[4] = 1500; // default Park;
		}
		fclose(fptr);
	}

	// Read in spectrograph wavelength range settings

	fopen_s(&fptr, SPECTROGRAPHSETTINGSFILE, "r");
	if (fptr == NULL) {
		SpSettings.AngstromsPerPixel = (float) 0.188;
		SpSettings.AngstromsPerStep  = (float) 0.12;
		SpSettings.NumPixels = 1024;
		SpSettings.LowWavelength = -999;
		SpSettings.HighWavelength = -999; 
		SpSettings.MidWavelength = -999;
		SpSettings.Installed = true;
	} else {
		nItems = fscanf_s(fptr, "Low (A): %hd\n Mid (A): %hd\n High (A): %hd\n APerStep: %f\n APerPixel: %f\n # Pixels: %hd",
			&SpSettings.LowWavelength, &SpSettings.MidWavelength, &SpSettings.HighWavelength, &SpSettings.AngstromsPerStep,
			&SpSettings.AngstromsPerPixel, &SpSettings.NumPixels);
		if (nItems != 6) {
			SpSettings.LowWavelength        = -999; // Indicate unknown
			SpSettings.MidWavelength        = -999; // Indicate unknown
			SpSettings.HighWavelength       = -999; // Indicate unknown
			SpSettings.AngstromsPerStep     = (float) 0.12; // Best known value
			SpSettings.AngstromsPerPixel    = (float) 0.200; // Estimate (depends on wavelength region
			SpSettings.NumPixels            = 1024; // Ap-47p, 1x1 binning
		}
		fclose(fptr);
	}

	// Read in Focuser settings

	FocuserSettings.Installed = false;
	fopen_s(&fptr, FOCUSERSETTINGSFILE, "r");
	if (fptr == NULL) {
		FocuserSettings.currentPosition = -9999;
		FocuserSettings.currentPositionIndex = 0;
		FocuserSettings.rawTemperature = -9999;
		FocuserSettings.Temperature = -9999;
		strcpy_s(FocuserSettings.FocusPositionNames[0], MAX_FOCUS_POSITION_NAME_LENGTH, "40 mm Eyepice");
		FocuserSettings.FocusPositionValues[0] = 0;
		strcpy_s(FocuserSettings.FocusPositionNames[1], MAX_FOCUS_POSITION_NAME_LENGTH, "Orion Startshoot Pro");
		FocuserSettings.FocusPositionValues[1] = 0;
		strcpy_s(FocuserSettings.FocusPositionNames[2], MAX_FOCUS_POSITION_NAME_LENGTH, "Apogee U8300");
		FocuserSettings.FocusPositionValues[2] = 0;
		strcpy_s(FocuserSettings.FocusPositionNames[3], MAX_FOCUS_POSITION_NAME_LENGTH, "LHIRES III");
		FocuserSettings.FocusPositionValues[3] = 0;
		FocuserSettings.numFocusPositions = 4;
	} else {
		int i = 0;
		char line[80], *cptr;
		do {
			if (fgets(line, sizeof(line), fptr) == nullptr)  // Get line containing position & name, break if eof
				break;
			if ((cptr = strchr(line, '\n')) != nullptr)  // remove any newline char
				*cptr = 0;
			nItems = sscanf_s(line, "%4d", &FocuserSettings.FocusPositionValues[i]);
			if (nItems == 1) {
				strcpy_s(FocuserSettings.FocusPositionNames[i], MAX_FOCUS_POSITION_NAME_LENGTH, &line[5]);
				i++;
				if (i >= MAX_NUM_FOCUS_POSITIONS)
					break;
			} else
				break;
		} while (! feof(fptr));
		FocuserSettings.numFocusPositions = i;
		fclose(fptr);
	}

	Application::ThreadException += gcnew 
      ThreadExceptionEventHandler(OnUnhandled);

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
