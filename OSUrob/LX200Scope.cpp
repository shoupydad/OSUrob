#include "StdAfx.h"
#include <stdio.h>
#include "doRoutines.h"
#include "Form1.h"
#include "LX200Scope.h"

using namespace System;
using namespace System::IO::Ports;


namespace OSUrob {


	LX200Scope::LX200Scope(void) {

		Ptr = this;
		char message[160];

		if (!CheckIfComPortExists(LX200_COM_PORT_NAME)) {
			sprintf_s(message, sizeof(message), "*** Warning - Serial Port for LX200: %s does not exist (RoboFocuser::RoboFocuser)\n",
				LX200_COM_PORT_NAME);
			Form1::StatusPrint(message);
			return;
		}
		this->ComPortName = gcnew String(LX200_COM_PORT_NAME);
		this->ComPortPtr = gcnew SerialPort(ComPortName);
		this->ComPortOpen = this->LinkOpen = false;
		this->ErrMessageCount = 0;

		return;


	}

	LX200Scope::~LX200Scope(void) {

		if (this->ComPortPtr != nullptr) {
			if (this->ComPortPtr->IsOpen)
				this->ComPortPtr->Close();
			this->ComPortOpen = false;
			this->LinkOpen = false;
			delete this->ComPortPtr;
		}
		return;

	}

	bool LX200Scope::EstablishLink() {

		char message[160], Response[80];
		int nTries;
		bool success;

		// Check to make sure com port available

		if (this->ComPortPtr == nullptr) {
			sprintf_s(message, sizeof(message), "*** Warning - Com port %s is not available (LX200Scope::EstablishLink)\n",
				LX200_COM_PORT_NAME);
			Form1::StatusPrint(message);
			return false;
		}

		// Open com port

		if (!this->ComPortPtr->IsOpen) {
			this->ComPortPtr->Open();
			if (!this->ComPortPtr->IsOpen) {
				sprintf_s(message, sizeof(message), "*** Warning - Com port %s is not available (LX200Scope::EstablishLink)\n",
					LX200_COM_PORT_NAME);
				Form1::StatusPrint(message);
				return false;
			}
		}

		// Communicate with scope to make sure it's there...

		nTries = 0;
		do {
			success = this->SendCommand(":GVN#", Response);
			if (success)
				break;
			usleep(1000000, true);  // sleep for a second
			nTries++;			
		} while (nTries < 10);

		if (nTries >= 10) {
			sprintf_s(message, sizeof(message), "*** Warning - Can't communicate with LX200 scope.  (LX200Scope::EstablishLink)\n");
			Form1::StatusPrint(message);
			return false;
		}

		this->LinkOpen = true;
		return true;
	}


	bool LX200Scope::CloseLink() {

		if (this->ComPortPtr->IsOpen) {
			this->ComPortPtr->Close();
			this->ComPortOpen = false;
			this->LinkOpen = false;
		}

		return true;
	}


	bool LX200Scope::SendCommand(char *Command, char *Response) {

		String ^buffer;
		char ch, Message[160];
		int TotalBytes, TimeOutCounts;
		bool GotF;

		DontUpdateNow(true);

		if (!this->ComPortOpen) {
			if (this->ErrMessageCount < 10) {
				Form1::StatusPrint("*** Warning - LX200 Scope COM port not open (LX200Scope::SendCommand)\n");
				this->ErrMessageCount++;
			}
			DontUpdateNow(false);
			return false;
		}

		// Clear off any waiting "responses"

		while (this->ComPortPtr->BytesToRead > 0)
			this->ComPortPtr->ReadChar();

		// Send command to LX200

		buffer = gcnew String(Command);
		this->ComPortPtr->Write(buffer);
		delete buffer;

		// Check for any characters waiting

		TotalBytes = 0;
		Response[0] = '\0';
		TimeOutCounts = 3000;
		GotF = false;
		do {
			if (this->ComPortPtr->BytesToRead > 0) {
				ch = this->ComPortPtr->ReadChar();
				Response[TotalBytes++] = ch;
				if (ch == '#') {
					Response[TotalBytes] = '\0';
					break;
				}
			} else {
				usleep(10000, true); // 0.01 sec
				TimeOutCounts--;
			}
		} while (TimeOutCounts > 0);

		if (TimeOutCounts <= 0) {
			sprintf_s(Message, sizeof(Message), "*** Warning - Timed Out waiting for LX200 scope response to command: %s  (LX200Scope::SendCommand)\n", Command);
			Form1::StatusPrint(Message);
			DontUpdateNow(false);
			return false;
		}

		DontUpdateNow(false);
		return true;
	}


};
