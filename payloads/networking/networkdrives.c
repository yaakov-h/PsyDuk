#include "psyduk/pd_utility.h"
#include "psyduk/usb_keyboard.h"
#include "psyduk/pd_runcommands.h"
#include "networkdrives.h"
#include <avr/pgmspace.h>

void MapNetworkDrive(const char* driveLetter, const char* UNCpath, uint8_t persistent)
{
	PDOpenWindowsRunBox();
	PDTypeString_P("net use ");
	PDTypeString(driveLetter);
	PDTypeString_P(" ");
	PDTypeString(UNCpath);
	
	if ( persistent == MAPPING_PERSISTENT )
	{
		PDTypeString_P(" /PERSISTENT:YES");
	}
	
	PDKeypress(KEY_ENTER);
}

void MapNetworkDriveWithCredentials(const char* driveLetter, const char* UNCpath,
						uint8_t persistent, const char* username, const char* password)
{
	PDOpenWindowsRunBox();
	PDTypeString_P("net use ");
	PDTypeString(driveLetter);
	PDTypeString_P(" ");
	PDTypeString(UNCpath);
	
	PDTypeString_P(" /USER:");
	PDTypeString(username);
	
	if ( persistent == MAPPING_PERSISTENT )
	{
		PDTypeString_P(" /PERSISTENT:YES");
	}
	
	PDKeypress(KEY_ENTER);
	
	PDDelay(200);
	PDTypeString(password);
	PDKeypress(KEY_ENTER);
}

void RemoveDriveMapping(const char* driveLetter)
{
	PDOpenWindowsRunBox();
	PDTypeString_P("net use ");
	PDTypeString(driveLetter);
	PDTypeString_P(" /DELETE");
	
	PDKeypress(KEY_ENTER);
				 
}


