#include <windows.h> //MAC addition
#include <stdio.h>
#include <string.h>
#include "hardwareCheck_LIB.h"

#include <Iphlpapi.h>   //MAC addition
#include <Assert.h>		//MAC addition
#pragma comment(lib, "iphlpapi.lib")  //MAC addition

__declspec(dllexport) int __stdcall GetMACaddress(char * license_PATH, char * errorString)
{
	IP_ADAPTER_INFO AdapterInfo[16];			// Allocate information for up to 16 NICs
	PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;// Contains pointer to current adapter info
	FILE * in;
 	int errorMAC=0;
	int x;
	char string[13];

	char pcMAC[13];
	char currentMAC[13];
	char key[]="rdcqalpogbmw";

	DWORD dwBufLen = sizeof(AdapterInfo);		// Save the memory size of buffer

	DWORD dwStatus = GetAdaptersInfo(			// Call GetAdapterInfo
		AdapterInfo,							// [out] buffer to receive data
		&dwBufLen);								// [in] size of receive data buffer
	assert(dwStatus == ERROR_SUCCESS);			// Verify return value is valid, no buffer overflow

	if (fopen_s(&in, (char *)license_PATH, "rb" ) == 0)
	{
		fread(pcMAC,sizeof pcMAC,1,in);
		fclose(in);
	}
	else
	{
		strcpy_s(errorString, 50, "license.dat does not exist\n");
		fclose(in);
		return 2;
	}
	strcpy_s(string, 13, "");

	for(x = 0; x < 12; x++)
	{
		string[x] = pcMAC[x] ^ key[x];
	}
	string[12] = '\0';

	do
	{
		sprintf_s(currentMAC, 13, "%02X%02X%02X%02X%02X%02X",
		pAdapterInfo->Address[0], pAdapterInfo->Address[1], pAdapterInfo->Address[2], pAdapterInfo->Address[3], pAdapterInfo->Address[4], pAdapterInfo->Address[5]);

		for(x = 0; x < 12; x++)
		{
			currentMAC[x]=tolower(currentMAC[x]);
		}


		currentMAC[12]='\0';
		if(strcmp(currentMAC,string) == 0)
		{
			errorMAC = 1;
		}
		pAdapterInfo = pAdapterInfo->Next;		// Progress through linked list
	}while(pAdapterInfo);						// Terminate if last adapter

	if (errorMAC)
	{
		strcpy_s(errorString, 50, "License is valid\n");
	}
	else
	{
		strcpy_s(errorString, 50, "License is invalid\n");
	}
	return errorMAC;
}
