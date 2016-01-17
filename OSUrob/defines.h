#pragma once

namespace OSUrob {

	// Constants

#define RELEASE_VERSION 2.10  // 1st version to use ASCOM POTH.Telescope driver (MeadeGPS)

#define NOANSWER 0
#define YESNO 1
#define CANCEL 2
#define YES 3
#define NO 4
#define OKAY 5
#define SITE_LATITUDE 40.73498
#define SITE_LONGITUDE -84.02741
#define SCOPEDOMEOFFSET 3.0  // feet to north
#define DOMERADIUS 7.5 // feet
#define DEG2RAD 0.0174533
#define RAD2DEG 57.29583
#define SLEWRATE_BUMP 0.188e-6 // slew rate for bumping scope in arcmin/microsec
#define MAX_FOCUS_POSITION_NAME_LENGTH 80
#define MAX_NUM_FOCUS_POSITIONS 16

	// COM port definitions/assignements

#define ROBOFOCUSER_COM_PORT_NAME "COM2"
#define DDW_COM_PORT_NAME "COM1"
#define SCOPE_COM_PORT_NAME "COM3"
#define OBSCON_COM_PORT_NAME "COM5"

	// RoboFocus definitions


	// Instrument selector port assignments

#define HOMEPORT 0    // Position of home sensor
#define EYEPORT 4    // Instrument selector eyepiece port 1
#define COLORCCDPORT 2   // Color ccd port
#define CCDPORT  1    // ccd port
#define SPECTROPORT 3 // spectrograph port
#define PARKINGPORT 5 // Place to set selector on powerdown for fastest init

	// File name definitions

		// Main Directory to reach most configure/information files

#define MAINPATH "C:\\Users\\Public\\Observatory\\"

#define INSTRUMENTSELECTORSETTINGSFILE MAINPATH "OSUrob\\InstrumentSelectorSettings.txt"
#define MESSAGEFILENAME MAINPATH "OSUrob\\MessageFile.txt"
#define RESPONSEFILENAME MAINPATH "OSUrob\\ResponseFile.txt"
#define SPECTROGRAPHSETTINGSFILE MAINPATH "OSUrob\\SpectrographSettings.txt"
#define THESKYSCOPEPOSITIONFILE MAINPATH "OSUrob\\Telescope Position.txt"
#define FOCUSERSETTINGSFILE MAINPATH "OSUrob\\FocuserSettings.txt"

	// Slewing constants

#define GUIDINGRATE 2.0   // autoguiding rate in "/s
#define NORTH 1
#define SOUTH 2
#define EAST  3
#define WEST  4
#define ON    true
#define OFF   false
#define MAXSLEWSTEPSIZE 60.0 // in degrees

	// AC Power outlet port assignments

#define ACPOWER_PORT_SCOPE 1
#define ACPOWER_PORT_FLATS   2
#define ACPOWER_PORT_LIGHT 3
#define ACPOWER_PORT_AUX1 4
#define ACPOWER_PORT_CCD 5
#define ACPOWER_PORT_COLOR 6
#define ACPOWER_PORT_SPECTRO 7
#define ACPOWER_PORT_AUX2 8
#define ACPOWER_ON true
#define ACPOWER_OFF false

	// Digital Dome Works constants

#define DDW_INIT					0
#define DDW_CLOSE					1
#define DDW_OPEN_SHUTTER			2
#define DDW_CLOSE_SHUTTER			3
#define DDW_ROTATE_DOME				5
#define DDW_HOME_DOME				6
#define DDW_GET_DOME_POSITION		7
#define DDW_TRAIN_DOME				8
#define DDW_STOP					9
#define DDW_SET_USER_PINS		   10
#define DDW_GET_DOME_STATUS		   11
#define DDW_DSR_INDET 0
#define DDW_DSR_CLOSED 1
#define DDW_DSR_OPEN 2

	// OSUrob Scope Functions

#define SCOPE_INIT			0
#define SCOPE_CLOSE			1
#define SCOPE_GPS_INIT		2
#define SCOPE_PARK			3
#define SCOPE_UNPARK		4
#define SCOPE_MOVE			5
#define SCOPE_BUMP			6
#define SCOPE_GET_POSITION	7
#define SCOPE_POWERON		8
#define SCOPE_POWEROFF		9
#define SCOPE_CLEAR_BUSY   10
#define SCOPE_FOCUS		   11
#define SCOPE_JOG_NORTH    12
#define SCOPE_JOG_SOUTH    13
#define SCOPE_JOG_EAST     14
#define SCOPE_JOG_WEST     15

	// Observatory Control constants

	// Types

typedef struct _SCOPEINFO {
  bool LinkOpen;
  bool Parked;
  bool Initialized;
  bool LastRAMoveWasEast;
  bool LastDECMoveWasNorth;
  float RA;
  float DEC;
  float Alt;
  float Az;
} SCOPEINFO;

typedef struct _OBSERVATORY {
  int Debug;
  char SiteName[80];
  double SiteLatitude;
  double SiteLongitude;
  bool Open;
  unsigned int EnclosureType;	// 0 = non-automated, 1 = roll off, 2 = dome
  double ShutterOpenCloseTime;
  int ShutterPercentOpen;  // 100 - Full open, 0 - Full close, -999 - unknown
  bool DomeInitialized;
  float DomeHomeAzimuth;
  float DomeCurrentAzimuth;
  bool  DomeLinked;
  bool  DomeHome;
  short DSRInterlock;  // 0 - indeterminate, 1 - closed, 2 - open
  short DDWUserPins;
  short ROBOUserPins;
  float ScopeAzimuth;  // For use to link dome to scope, in degrees
  float DomeSecondsPerDegreeCW;
  float DomeSecondsPerDegreeCCW;
  float DomeCountsPerDegreeCW;
  float DomeCountsPerDegreeCCW;
  bool ACPower[8];  // true - power on to that port;  1-4 via robofocus, 5-8 via ObsCon
  char FWPositions[8];
  bool HomeToOperateShutter;
  bool WeatherStationInstalled;
  bool UPSInstalled;
  bool PrecipitationDetectorInstalled;
  bool WatchDogInstalled;
  unsigned int ShutSpeed;	// Observatory shutdown parameters
  unsigned int ShutHumidity;
  unsigned int ShutIntLowTemp;
  unsigned int ShutIntHighTemp;
  unsigned int MaxWSFailures;
  long int TimeIncWeather;
  long int TimeIncChkSensors;
  char WeatherCom;		// Weather station/ups com port
} OBSERVATORY;

typedef struct _DDW_INFO {
	bool LinkOpen;
	unsigned short version;
	unsigned short TicksPerRotation;
	unsigned short HomePosition;  // in ticks
	unsigned short CoastDistance; // in ticks
	unsigned short CurrentDomeAzimuth; // in ticks
	bool Slaved;  // true - dome slaved to scope, false - not
	unsigned short ShutterState;  // 0 - indeterminate, 1 - closed, 2 - open
	unsigned short DSRState;  // 0 - indet., 1 - closed, 2 - open
	bool Home;  // true - dome at home, false, not
	unsigned short HomePositionCCWEdge; // in ticks
	unsigned short HomePositionCWEdge;  // in ticks
	unsigned short UserPinStatus; // bit-array, low 4 bits, 0 - off, 1 - on
	unsigned short ScopeAzimuth; // in degrees
} DDW_INFO;

typedef struct _INSTRUMENTSELECTORSETTINGS {
	bool Initialized;
	short CurrentDirection;  // 0: unknown, -1: CCW, +1: CW
	short CurrentStepPosition;
	short CurrentPort;
	short PortStepPositions[5];  // 0: Eye1, 1: Eye1, 2: Spectro, 3: CCD, 4: Park
} INSTRUMENTSELECTORSETTINGS;

typedef struct _SPECTROGRAPHSETTINGS {
	bool Installed;
	short LowWavelength;
	short MidWavelength;
	short HighWavelength;
	float AngstromsPerStep;
	float AngstromsPerPixel;
	short NumPixels;
} SPECTROGRAPHSETTINGS;

typedef struct _FOCUSERSETTINGS {
	bool Installed;
	double TempCalSlope;
	double TempCalZeroPoint;
	int currentPosition;
	int rawTemperature;
	double Temperature;
	char FocusPositionNames[MAX_NUM_FOCUS_POSITIONS][MAX_FOCUS_POSITION_NAME_LENGTH];
	int FocusPositionValues[MAX_NUM_FOCUS_POSITIONS];
	double FocusPositionTemps[MAX_NUM_FOCUS_POSITIONS];
	int numFocusPositions;
	unsigned int currentPositionIndex;
} FOCUSERSETTINGS;


}