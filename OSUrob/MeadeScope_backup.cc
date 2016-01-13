#include "StdAfx.h"
#include "MeadeScope.h"
#include <stdio.h>
#include "doRoutines.h"
#include "Form1.h"


namespace OSUrob {


MeadeScope::MeadeScope(void)
{
	Ptr = this;

	this->Scope = gcnew TelescopeClass();
	MeadeScope::RAMaxRate  = 2.0;    // deg/sec
	MeadeScope::RAMinRate  = 0.1;    // deg/sec
	MeadeScope::DECMaxRate = 2.0;    // deg/sec
	MeadeScope::DECMinRate = 0.1;    // deg/sec
	return;
}

MeadeScope::~MeadeScope(void)  {

	delete Scope;
	return;
}

bool MeadeScope::MoveAxis(TelescopeAxes axis, double rate) {

	char buffer[80];
	String ^command;
	bool success;
	double absRate;

	success = false;
	absRate = fabs(rate);
	if (axis == TelescopeAxes::axisPrimary) {
		if (absRate == 0.0) {
			MeadeScope::Scope->CommandBlind(L":Q#", true);
		} else if ((absRate <= MeadeScope::RAMaxRate) && (absRate >= MeadeScope::RAMinRate)) {
			sprintf_s(buffer, sizeof(buffer), ":RA%04.1lf#", absRate);
			command = gcnew String(buffer);
			MeadeScope::Scope->CommandBlind(command, true);
			if (rate > 0.0)
				MeadeScope::Scope->CommandBlind(L":Me#", true);
			else
				MeadeScope::Scope->CommandBlind(L":Mw#", true);
			success = true;
		} else {
			Form1::StatusPrint("*** Warning - Slew rate is outside RA slew rate range (MoveAxis).\n");
		}
	} else if (axis == TelescopeAxes::axisSecondary) {
		if (absRate == 0.0) {
			MeadeScope::Scope->CommandBlind(L":Q#", true);
		} else if ((absRate <= MeadeScope::DECMaxRate) && (absRate >= MeadeScope::DECMinRate)) {
			sprintf_s(buffer, sizeof(buffer), ":RE%04.1lf#", absRate);
			command = gcnew String(buffer);
			MeadeScope::Scope->CommandBlind(command, true);
			if (rate > 0.0)
				MeadeScope::Scope->CommandBlind(L":Mn#", true);
			else
				MeadeScope::Scope->CommandBlind(L":Ms#", true);
			success = true;
		} else {
			Form1::StatusPrint("*** Warning - Slew rate is outside DEC slew rate range (MoveAxis).\n");
		}
	}
	return success;
}

bool Scope_EstablishLink(void) {

	bool success;
	gcnew MeadeScope();
//	MeadeScope::Scope->SetupDialog();
	MeadeScope::Scope->Connected = true;
	success = MeadeScope::Scope->Connected;
//	MeadeScope::RARates = (RateClass ^) MeadeScope::Scope->AxisRates(TelescopeAxes::axisPrimary);
//	MeadeScope::DECRates = (RateClass ^) MeadeScope::Scope->AxisRates(TelescopeAxes::axisSecondary);
	return success;
}

bool Scope_UnLink(void) {

	MeadeScope::Scope->Connected = false;
	delete MeadeScope::Ptr;
	return true;
}

void Scope_SendCommandBlind(char *command) {

	String ^string = gcnew String(command);
	MeadeScope::Scope->CommandBlind(string, true);
	return;
}

bool Scope_SendCommand(char *command, char *response) {

	int i;
	String ^string = gcnew String(command);
	String ^responseString;
	responseString = MeadeScope::Scope->CommandString(string, true);
	for (i=0; i<responseString->Length; i++) response[i] = (char) responseString[i];
	response[i] = 0;

	return true;

}

bool Scope_Park(void) {

	MeadeScope::Scope->Park();
	return true;
}

bool Scope_GetRADEC(double *ra, double *dec) {

	*ra = MeadeScope::Scope->RightAscension;
	*dec = MeadeScope::Scope->Declination;

	return true;
}

bool Scope_GetAltAz(double *alt, double *az) {

	*alt = MeadeScope::Scope->Altitude;
	*az = MeadeScope::Scope->Azimuth;

	return true;
}

bool Scope_SlewToCoordinates(double ra, double dec, bool async) {

	if (async) {
		MeadeScope::Scope->SlewToCoordinatesAsync(ra, dec);
	} else {
		MeadeScope::Scope->SlewToCoordinates(ra, dec);
	}
	
	return true;
}

bool Scope_BumpArcMin(double delra, double deldec) {

	double slewTime, slewRate, delramin, deldecmin;
	int slewTimeInMicroSecs;		

	// Do RA first

	if (fabs(delra) > 0.0) {
		delramin = fabs(delra)/60.0;
		slewTime = 2.0;
		slewRate = delramin / slewTime;
		if (slewRate > MeadeScope::RAMaxRate) {
			slewRate = MeadeScope::RAMaxRate;
			slewTime = fabs(delramin) / slewRate;
		} else if (slewRate < MeadeScope::RAMinRate) {
			slewRate = MeadeScope::RAMinRate;
			slewTime = fabs(delramin) / slewRate;
		}
		if (delra < 0.0) slewRate = - slewRate;
		slewTimeInMicroSecs = (int) (slewTime * 1000000.0);
		MeadeScope::Ptr->MoveAxis(TelescopeAxes::axisPrimary, slewRate);
		usleep(slewTimeInMicroSecs, false);
		MeadeScope::Ptr->MoveAxis(TelescopeAxes::axisPrimary, 0.0);
	}

	// Do DEC next

	if (fabs(deldec) > 0.0) {
		deldecmin = fabs(deldec)/60.0;
		slewTime = 2.0;
		slewRate = deldecmin / slewTime;
		if (slewRate > MeadeScope::DECMaxRate) {
			slewRate = MeadeScope::DECMaxRate;
			slewTime = fabs(deldecmin) / slewRate;
		} else if (slewRate < MeadeScope::DECMinRate) {
			slewRate = MeadeScope::DECMinRate;
			slewTime = fabs(deldecmin) / slewRate;
		}
		if (deldec < 0.0) slewRate = - slewRate;
		slewTimeInMicroSecs = (int) (slewTime * 1000000.0);
		MeadeScope::Ptr->MoveAxis(TelescopeAxes::axisSecondary, slewRate);
		usleep(slewTimeInMicroSecs, false);
		MeadeScope::Ptr->MoveAxis(TelescopeAxes::axisSecondary, 0.0);
	}

	return true;
}

bool Scope_Jog(int direction, double rate, bool Start) {

	switch (direction) {
		case NORTH:
			if (Start) {
				MeadeScope::Scope->MoveAxis(TelescopeAxes::axisSecondary, rate);
			} else {
				MeadeScope::Scope->MoveAxis(TelescopeAxes::axisSecondary, 0.0);
			}
			break;
		case SOUTH:
			if (Start) {
				MeadeScope::Scope->MoveAxis(TelescopeAxes::axisSecondary, -rate);
			} else {
				MeadeScope::Scope->MoveAxis(TelescopeAxes::axisSecondary, 0.0);
			}
			break;
		case EAST:
			if (Start) {
				MeadeScope::Scope->MoveAxis(TelescopeAxes::axisPrimary, rate);
			} else {
				MeadeScope::Scope->MoveAxis(TelescopeAxes::axisPrimary, 0.0);
			}
			break;
		case WEST:
			if (Start) {
				MeadeScope::Scope->MoveAxis(TelescopeAxes::axisPrimary, -rate);
			} else {
				MeadeScope::Scope->MoveAxis(TelescopeAxes::axisPrimary, 0.0);
			}
			break;
	}

	return true;
}

}