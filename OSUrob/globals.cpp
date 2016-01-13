
#include "stdafx.h"
#include "defines.h"

using namespace System;

namespace OSUrob {

	// global flags if forms/dialogs exist

bool OkayDialogExists=false;
bool OSUrobFormExists=false;
bool ProgressDialogExists=false;
bool YesNoDialogExists=false;
bool CalibrateISDialogExists=false;
bool AdjustFocusDialogExists=false;
bool CalibrateSlewingDialogExists=false;
bool SpectrographWavelengthsDialogExists=false;
bool GlobalDebug=false;
bool RoboFocuserExists=false;

	// Misc. items

bool DIOOPEN=false;
bool DDWOPEN=false;
bool ExitMenuItemClicked=false;
int MessageBoxAnswer;

	// Global Structures

OBSERVATORY Observatory;
SCOPEINFO ScopeInfo;
INSTRUMENTSELECTORSETTINGS ISSettings;
SPECTROGRAPHSETTINGS SpSettings;
}
