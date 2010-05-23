/*
 *  PsyDuk.c
 *  
 *
 *  Created by Psychosis on 29/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

// Comment out or remove the below line to disable the LED in PsyDuk functions
#define PD_USE_LED

#include "psyduk/includes.h"
#include "payloads/includes.h"

int main(void)
{
	PDInitialise();
	
	//PDRunMacOSXCommand(PSTR("open http://www.hak5.org"));
	//PDRunWindowsCommand(PSTR("http://www.hak5.org"));
	//PDRunLinuxCommand(PSTR("http://www.hak5.org"));
	
	//FBShareLink_windows_P("http://hak5.org/projects/doku.php?id=usb_rubber_ducky",
	//				  "I got pwned by the USB Rubber Ducky!");
	
	PDRunMacOSXCommand_P("open http://www.youtube.com/watch?v=EK2tWVj6lXw");
	
	//PDKeypressWithModifier(KEY_SPACE, KEY_ALT);
	//PDOpenWindowsRunBox();
	//PDRunWindowsCommand_P("http://www.youtube.com/watch?v=EK2tWVj6lXw");
	//PDDelay(200);
	
	//PDOpenWindowsTerminal();
	
	/*PDKeypressWithModifier(0x00, KEY_WINDOWS);
	PDDelay(500);
	PDTypeString_P("Command Prompt");
	PDDelay(1000);*/
	
	//PDRunLinuxCommand_P("http://www.youtube.com/watch?v=EK2tWVj6lXw");
	
	//MapNetworkDrive(PSTR("X:"), PSTR("\\\\10.10.0.4\\public"), MAPPING_NOTPERSISTENT);
	//PDDelay(500);
	//RemoveDriveMapping(PSTR("X:"));
}


