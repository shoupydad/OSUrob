#pragma once
using namespace System;
using namespace System::IO::Ports;


namespace OSUrob {


	public ref class LX200Scope : public System::Object {

	public:
		static LX200Scope ^Ptr;
		SerialPort ^ComPortPtr;
		bool LinkOpen;
		bool ComPortOpen;
		String ^ComPortName;
		int ErrMessageCount;
		bool Parked;
		bool Initialized;
		bool LastRAMoveWasEast;
		bool LastDECMoveWasNorth;
		double RA;
		double DEC;
		double Alt;
	    double Az;
		double RAMaxRate;    // deg/sec
		double RAMinRate;    // deg/sec
		double DECMaxRate;    // deg/sec
		double DECMinRate;    // deg/sec

		LX200Scope(void);
		~LX200Scope(void);
		bool EstablishLink();
		bool CloseLink();
		bool SendCommand(char *Command, char *Response);
		bool InitScope();
		bool ParkScope();
		bool SlewToCoordinates(double ra, double dec);
		bool JogScope(int direction, double rate, bool start);
		bool MoveAxis(int whichAxis, double rate);
		bool BumpScopeArcmin(double delRA, double delDEC);
	};

}
