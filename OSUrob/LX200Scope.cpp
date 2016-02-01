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
		this->RAMaxRate = 2.0;    // deg/sec
		this->RAMinRate = 0.1;    // deg/sec
		this->DECMaxRate = 2.0;    // deg/sec
		this->DECMinRate = 0.1;    // deg/sec

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

	
	bool LX200Scope::InitScope() {

		char command[80], response[80];
		bool success;
		tm LocalTime;
		__time64_t CurrentSeconds;

		// Get current date/time

		_time64(&CurrentSeconds);
		_localtime64_s(&LocalTime, &CurrentSeconds);
		sprintf_s(command, sizeof(command), ":hI%02d%02d%02d%02d%02d%02d#", LocalTime.tm_year - 100, LocalTime.tm_mon + 1,
			LocalTime.tm_mday, LocalTime.tm_hour, LocalTime.tm_min, LocalTime.tm_sec);
		success = this->SendCommand(command, response);
		if ((!success) || (response[1] != '1')) {
			Form1::StatusPrint("*** Warning - Failed initializing scope (LX200Scope::InitScope)\n");
			return false;
		}
		this->Initialized = true;
		this->Parked = false;

		return true;

	}

	bool LX200Scope::ParkScope() {

		bool success;
		char response[80];

		success = this->SendCommand(":hP#", response);
		if ((!success) || (response[0] != '1')) {
			Form1::StatusPrint("*** Warning - Failed in parking scope.  (LX200Scope::ParkScope)");
			return false;
		}
		this->Parked = true;
		this->Initialized = false;

		return true;
	}


	bool LX200Scope::SlewToCoordinates(double ra, double dec) {


		return false;
	}


	bool LX200Scope::JogScope(int direction, double rate, bool Start) {

		if (! Start)
			rate = 0.0;

		switch (direction) {
			case NORTH:
				this->MoveAxis(1, rate);
				break;

			case SOUTH:
				this->MoveAxis(1, -rate);
				break;

			case EAST:
				this->MoveAxis(0, rate);
				break;

			case WEST:
				this->MoveAxis(0, -rate);
				break;
		}

		return true;
	}


	bool LX200Scope::MoveAxis(int axis, double rate) {

		char command[80], response[80];
		bool success;
		double absRate;

		success = false;
		absRate = fabs(rate);

		if (axis == 0) {
			if (absRate == 0.0) {
				success = this->SendCommand(":Q#", response);
			} else if ((absRate <= this->RAMaxRate) && (absRate >= this->RAMinRate)) {
				sprintf_s(command, sizeof(command), ":RA%04.1lf#", absRate);
				success = this->SendCommand(command, response);
				if (rate > 0.0)
					success = this->SendCommand(":Me#", response);
				else
				    success = this->SendCommand(":Mw#", response);
			} else {
				Form1::StatusPrint("*** Warning - Slew rate is outside RA slew rate range (MoveAxis).\n");
			}

		} else if (axis == 1) {
			if (absRate == 0.0) {
				success = this->SendCommand(":Q#", response);
			} else if ((absRate <= this->DECMaxRate) && (absRate >= this->DECMinRate)) {
				sprintf_s(command, sizeof(command), ":RE%04.1lf#", absRate);
				success = this->SendCommand(command, response);
				if (rate > 0.0)
					success = this->SendCommand(":Mn#", response);
				else
					success = this->SendCommand(":Ms#", response);
			} else {
				Form1::StatusPrint("*** Warning - Slew rate is outside DEC slew rate range (MoveAxis).\n");
			}
		}
		return success;
	}


	bool LX200Scope::BumpScopeArcmin(double delRA, double delDEC) {

		return false;
	}



	bool LX200Scope::SendCommand(char *Command, char *Response) {

		String ^buffer;
		char ch, Message[160];
		int TotalBytes, TimeOutCounts;
		bool GotF;

		DontUpdateNow(true);

		if (! this->ComPortPtr->IsOpen) {
//			if (this->ErrMessageCount < 10) {
				Form1::StatusPrint("*** Warning - LX200 Scope COM port not open (LX200Scope::SendCommand)\n");
//				this->ErrMessageCount++;
//			}
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
