#pragma once

using namespace System;
//using namespace ASCOM::DriverAccess;
using namespace ASCOM::Interface;
using namespace MeadeLX200GPS;


namespace OSUrob {

typedef struct _RATELIMITS {
	double Min;
	double Max;
} RATELIMITS;

	public ref class MeadeScope : public System::Object {

	public:
		static MeadeScope ^Ptr;
		static TelescopeClass ^Scope;
		static double RAMaxRate, RAMinRate;
		static double DECMaxRate, DECMinRate;
		MeadeScope(void);
		~MeadeScope(void);
		bool MoveAxis(TelescopeAxes axis, double rate);

};

}
