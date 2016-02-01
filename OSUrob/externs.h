#pragma once

#include "defines.h"


namespace OSUrob {

	// global flags if forms/dialogs exist

extern bool OkayDialogExists;
extern bool OSUrobFormExists;
extern bool ProgressDialogExists;
extern bool YesNoDialogExists;
extern bool CalibrateISDialogExists;
extern bool AdjustTelescopeFocusDialogExists;
extern bool CalibrateSlewingDialogExists;
extern bool SpectrographWavelengthsDialogExists;
extern bool GlobalDebug;
extern bool RoboFocuserExists;
extern bool LX200ScopeExists;

	// Misc. items

extern bool DIOOPEN;
extern bool DDWOPEN;
extern bool ExitMenuItemClicked;
extern int MessageBoxAnswer;

	// Global Structures

extern OBSERVATORY Observatory;
extern INSTRUMENTSELECTORSETTINGS ISSettings;
extern SPECTROGRAPHSETTINGS SpSettings;
extern FOCUSERSETTINGS FocuserSettings;

}