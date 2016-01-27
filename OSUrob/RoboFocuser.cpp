#include "StdAfx.h"
#include "RoboFocuser.h"
#include <stdio.h>
#include "doRoutines.h"
#include "Form1.h"

using namespace System;
using namespace System::IO::Ports;


namespace OSUrob {


RoboFocuser::RoboFocuser(void) {
	
	Ptr = this;
	char Message[160];

	if (!CheckIfComPortExists(ROBOFOCUSER_COM_PORT_NAME)) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Serial Port for RoboFocuser: %s does not exist (RoboFocuser::RoboFocuser)\n",
			ROBOFOCUSER_COM_PORT_NAME);
		Form1::StatusPrint(Message);
		return;
	}
	this->ComPortName = gcnew String(ROBOFOCUSER_COM_PORT_NAME);
	this->ComPortPtr = gcnew SerialPort(ComPortName);
	this->ComPortPtr->Open();
	this->ComPortOpen = this->ComPortPtr->IsOpen;
	this->ErrMessageCount = 0;

	if (! this->ComPortOpen) {
		Form1::StatusPrint("*** Warning - Can't open RoboFocuser COM port (RoboFocuser)\n");
		return;
	}

	return;
}

RoboFocuser::~RoboFocuser(void)  {

	if (this->ComPortPtr != nullptr) {
		if (this->ComPortPtr->IsOpen)
			this->ComPortPtr->Close();
		this->ComPortOpen = false;
		delete this->ComPortPtr;
	}
	return;
}

bool RoboFocuser::SetUserButtonOnOff(short ButtonNum, bool On) {

	bool buttonState;
	char command[10] = "FP000000";
	char response[10], Message[160];

	if (!this->ComPortOpen) {
		Form1::StatusPrint("*** Warning - Com port to focuser not open.\n");
		return false;
	}

	// Get current state of all buttons

	this->AddCheckSum(command);
	if (!this->SendCommand(command, response))
		return false;

	// Check valid response

	if (strncmp(response, "FP", 2) != 0)
		return false;

	// Change only the user button requested

	if (On)
		response[ButtonNum + 3] = '2';
	else
		response[ButtonNum + 3] = '1';

	// Send new command to turn button on/off

	strcpy_s(command, sizeof(command), response);
	this->AddCheckSum(command);
	if (!this->SendCommand(command, response))
		return false;

	// Double check that it was set on/off

	if (strncmp(response, "FP", 2) != 0)
		return false;

	buttonState = (response[ButtonNum + 3] == '2');
	if ((On && (!buttonState)) || ((!On) && buttonState)) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Wasn't able to turn On/Off AC Power #%d\n", ButtonNum);
		return false;
	}

	return true;
}

bool RoboFocuser::GetUserButtonState(short Button) {

	bool buttonState;
	char command[10] = "FP000000";
	char response[10];
	char Message[160];

	this->AddCheckSum(command);

	if (!this->SendCommand(command, response))
		return false;  // if not success, return false;

	if (strncmp(response, "FP", 2) != 0) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Bad response from RoboFocuser: %s  (RoboFocuser::GetUserButtonState)\n", response);
		Form1::StatusPrint(Message);
		return false;
	}

	buttonState = (response[5-Button] == '2');
	return buttonState;
}


bool RoboFocuser::SendCommand(char *Command, char *Response) {

	String ^buffer;
	char ch, Message[160];
	int TotalBytes, TimeOutCounts;

	if (!this->ComPortOpen) {
		if (this->ErrMessageCount < 10) {
			Form1::StatusPrint("*** Warning - RoboFocuser COM port not open (RoboFocuser::SendCommand)\n");
			this->ErrMessageCount++;
		}
		return false;
	}

	// Clear off any waiting "responses"

	while (this->ComPortPtr->BytesToRead > 0)
		this->ComPortPtr->ReadChar();

	// Send command to RoboFocuser

	buffer = gcnew String(Command);
	this->ComPortPtr->Write(buffer);

	// Check for any characters waiting

	TotalBytes = 0;
	Response[0] = '\0';
	TimeOutCounts = 5000;
	do {
		if (this->ComPortPtr->BytesToRead > 0) {
			ch = this->ComPortPtr->ReadChar();
			Response[TotalBytes++] = ch;
			if (TotalBytes == 8) {
				Response[TotalBytes] = '\0';
				break;
			}
		} else {
			usleep(10000, false); // 0.01 sec
			TimeOutCounts--;
		}
	} while (TimeOutCounts > 0);

	if (TimeOutCounts <= 0) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Timed Out waiting for RoboFocuser response to command: %s  (RoboFocuser::SendCommand)\n", Command);
		Form1::StatusPrint(Message);
		return false;
	}
	return true;
}

void RoboFocuser::AddCheckSum(char *buffer) {

	int length, sum, i;

	length = strlen(buffer);
	sum = 0;
	for (i = 0; i < length; i++)
		sum += buffer[i];
	buffer[i] = sum;
}

int RoboFocuser::GetPosition() {

	char command[10] = "FG000000";
	char response[10];
	char Message[160];
	int position;

	this->AddCheckSum(command);

	if (!this->SendCommand(command, response))
		return -999;  // if not success, return false;

	if (strncmp(response, "FD", 2) != 0) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Bad response from RoboFocuser: %s  (RoboFocuser::GetPosition)\n", response);
		Form1::StatusPrint(Message);
		return -999;
	}

	sscanf_s(response, "FD%d", &position);
	if ((position < 0) || (position > MAX_ROBOFOCUSER_POSITION)) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Bad position from RoboFocuser: %s  (RoboFocuser::GetPosition)\n", response);
		Form1::StatusPrint(Message);
		return -999;
	}

	return position;
}

bool RoboFocuser::GoToPosition(int position) {

	int curPosition, delta;
	char command[10], response[10], Message[160];

	// Get current position

	curPosition = this->GetPosition();
	if (curPosition < 0)
		return false;

	// Check validity of new position

	if ((position < MIN_ROBOFOCUSER_POSITION) || (position > MAX_ROBOFOCUSER_POSITION)) {
		sprintf_s(Message, sizeof(Message), "*** Warning - New position for RoboFocuser is invalid: %d (RoboFocuser::GoToPosition)\n", position);
		Form1::OSUrobForm->StatusPrint(Message);
		return false;
	}

	// Send either FO (move out) or FI (move in) command

	delta = position - curPosition;
	if (delta == 0)
		return true;
	else if (delta > 0)
		sprintf_s(command, sizeof(command), "FO%06d", delta);
	else
		sprintf_s(command, sizeof(command), "FI%06d", abs(delta));

	this->AddCheckSum(command);

	if (!this->SendCommand(command, response)) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Failed to send command to RoboFocuser: %s (RoboFocuser::GoToPosition)\n", command);
		Form1::OSUrobForm->StatusPrint(Message);
		return false;  // if not success, return false
	}

	// Check if we are at the correct position

	curPosition = this->GetPosition();
	if (curPosition < 0)
		return false;

	if (curPosition != position) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Failed to move to RoboFocuser position: %d (RoboFocuser::GoToPosition)\n", position);
		Form1::OSUrobForm->StatusPrint(Message);
		return false;
	}

	return true;
}

int RoboFocuser::GetTemperature() {

	char command[10] = "FT000000";
	char response[10];
	char Message[160];
	int rawTemperature;

	this->AddCheckSum(command);

	if (!this->SendCommand(command, response))
		return -999;  // if not success, return false;

	if (strncmp(response, "FT", 2) != 0) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Bad response from RoboFocuser: %s  (RoboFocuser::GetTemperature)\n", response);
		Form1::StatusPrint(Message);
		return -999;
	}

	sscanf_s(response, "FT%d", &rawTemperature);
	if ((rawTemperature < MIN_ROBOFOCUSER_TEMPERATURE) || (rawTemperature > MAX_ROBOFOCUSER_TEMPERATURE)) {
		sprintf_s(Message, sizeof(Message), "*** Warning - Bad response from RoboFocuser: %s  (RoboFocuser::GetTemperature)\n", response);
		Form1::StatusPrint(Message);
		return -999;
	}

	return rawTemperature;

}


}