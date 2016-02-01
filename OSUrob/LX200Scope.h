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


		LX200Scope(void);
		~LX200Scope(void);
		bool EstablishLink();
		bool CloseLink();
		bool SendCommand(char *Command, char *Response);
	};

}
