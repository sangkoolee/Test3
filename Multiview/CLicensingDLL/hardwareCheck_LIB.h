//extern "C" {
#ifndef __essai_H__
#define __essai_H__

	//#ifdef __cplusplus
	//    extern "C" {
	//#endif

	//==============================================================================
	// Include files

//#include "cvidef.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables

//==============================================================================
// Global functions

extern "C" __declspec(dllexport) int __stdcall GetMACaddress(char * license_PATH, char * errorString);

	//#ifdef __cplusplus
	//    }
	//#endif

#endif  /* ndef __essai_H__ */
//}
