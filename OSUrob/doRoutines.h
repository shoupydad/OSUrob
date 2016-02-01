#pragma once

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "externs.h"

//using namespace TIDigitalDomeWorks;

namespace OSUrob {

bool Scope_EstablishLink(void);
bool Scope_UnLink(void);
bool Scope_SendCommand(char *command, char *response);
void Scope_SendCommandBlind(char *command);
bool Scope_Park(void);
bool Scope_GetRADEC(double *ra, double *dec);
bool Scope_GetAltAz(double *alt, double *az);
bool Scope_SlewToCoordinates(double ra, double dec, bool async);
bool Scope_BumpArcMin(double delra, double deldec);
bool Scope_Jog(int direction, double rate, bool Start);
bool CheckIfComPortExists(char *name);
bool ConvertDECtoDMS(double dec, int *degs, int *mins, float *secs);
bool ConvertDMStoDEC(int degs, int mins, float secs, double *dec);
bool ConvertHMStoRA(int hours, int mins, float secs, double *ra);
bool ConvertRAtoHMS(double ra, int *hours, int *mins, float *secs);
void DecimalDay(int day, int hour, int minute, int second, int sec100, double *DecDay);
bool DoDomeFunction(short function, short *value, bool state);
void DoMainEvents(void);
void DontUpdateNow(bool state);
bool DoScopeFunction(short function, float *value1, float *value2, bool state);
bool GetDDWGinfResponse(DDW_INFO *DDWInfo, int timeout);
int GetDDWText(char *buffer, short MaxNBytes, short timeout);
void GetLSTTextBox(char *text);
bool GetFWStatus(void);
void InitDDW(void);
void JulianDay(int year, int month, int day, int hour, int minute, int second,
			   int sec100, double *jd);
void lmst(double julian_date, double *lst);
int MessageBox(char *prompt, int buttons);
void OnOffMicrometerMotor(bool TurnOn);
void OnOffSelectorMotor(bool TurnOn);
bool PowerOnOff(short OutletNum, bool On);
bool PowerOnScope(void);
bool PowerOffScope(void);
bool ProcessMessages(void);
bool SelectPort(int port);
bool SendDDWText(char *text);
bool SendObsCon(char *command, char *response, int MaxNumBytes);
bool SendScopeCommand(char *Command, char *Response, short timeout);
void ShowMoveScopeDialog(void);
bool SpectroLampOnOff(bool On);
bool StepMicrometerMotor(short numSteps);
bool StepSelectorMotor(short numSteps);
void SyncDomeScope();
float TransformAz(float Az, float Alt);
void usleep(int usecs, bool DoEvents);
void WriteResponse(char *Message);
void PrintStatus(char *text);
//bool OnOffGuiding(int direction, bool state);
}
