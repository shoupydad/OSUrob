// 
// Using the magic of _com_ptr_t and _bstr_t in ActiveX Template Library (ATL)
// REQUIRES ATL - See Project Properties, General. I use Static Link to ATL so
// the whole giant DLL isn't loaded and avoiding a DLL dependency.
//
// Bob Denny <rdenny@dc3.com> 05-Jun-08
//

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <comutil.h>
#include <comip.h>

//
// Import the ASCOM Interfaces en masse
//
#import "file:f:\Program Files\Common Files\ASCOM\Interface\AscomMasterInterfaces.tlb"

//
// Required for IDictionaryPtr which is used by DriverHelper.Profile
//
#import "file:f:\\Windows\\System32\\ScrRun.dll" \
	no_namespace \
	rename("DeleteFile","DeleteFileItem") \
	rename("MoveFile","MoveFileItem") \
	rename("CopyFile","CopyFileItem") \
	rename("FreeSpace","FreeDriveSpace") \
	rename("Unknown","UnknownDiskType") \
	rename("Folder","DiskFolder") \
	rename("System","Systemm")

//
// Creates COM "smart pointer" _com_ptr_t named _ChooserPtr
//
#import "progid:DriverHelper.Chooser" \
	rename("Yield","ASCOMYield") \
	rename("MessageBox","ASCOMMessageBox")

//
// Eliminate need for namespace:: qualifiers on ASCOM stuff
//
using namespace AscomInterfacesLib;
using namespace DriverHelper;



namespace OSUrob {

bool Scope_EstablishLink(void) {

	CoInitialize(NULL);
	_ChooserPtr C = NULL;
// [sentinel] Using smart pointer (_com_ptr_t<>)
//	BSTR tele = SysAllocString(L"Telescope");
	C.CreateInstance("DriverHelper.Chooser");							// Little known fact: ProgID will work here
	C->DeviceTypeV = "Telescope";
//	_bstr_t nil = SysAllocString(L"");
	_bstr_t  drvrId = C->Choose("");
//	BSTR drvrID = SysAllocString(drvrId.GetBSTR());

	if (C != NULL) {
		C.Release();													// Chooser valid, release it now, we're done with it
////		printf("Selected %s\nloading...", (char *)drvrId);				// More _bstr_t magic, cast to convert BSTR to char *!!!
//
		ITelescopePtr T = NULL;											// [sentinel] Smart pointer again 
		T.CreateInstance((LPCSTR)drvrId);								// _bstr_t again...
		if(T != NULL) {
////			printf("...OK! Device name is %s\n", (char *)T->Name);		// ...and again.
			T.Release();
		} else {
////			printf("Failed to load driver %s\n", (char *)drvrId);
		}
	} else {
/////		printf("Failed to load Chooser\n");
	}

//	printf("Press enter to quit:");
//	fflush(stdout);
//	getchar();
	return false;
};

}