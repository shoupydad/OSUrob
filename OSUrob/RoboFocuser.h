#pragma once

using namespace System;
using namespace System::IO::Ports;


namespace OSUrob {

#define MAX_ROBOFOCUSER_POSITION 100000
#define MIN_ROBOFOCUSER_POSITION 0
#define MAX_ROBOFOCUSER_TEMPERATURE 999999
#define MIN_ROBOFOCUSER_TEMPERATURE 0

	public ref class RoboFocuser : public System::Object {

	public:
		static RoboFocuser ^Ptr;
		SerialPort ^ComPortPtr;
		bool ComPortOpen;
		String ^ComPortName;
		int ErrMessageCount;
		RoboFocuser(void);
		~RoboFocuser(void);
		bool SetUserButtonOnOff(short Button, bool On);  // true -> On
		bool GetUserButtonState(short Button);  // true -> On
		bool SendCommand(char *Command, char *Response);
		void AddCheckSum(char *buffer);
		int GetPosition();
		bool GoToPosition(int position);
		int GetTemperature();
};

}
