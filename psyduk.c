/*
 *  PsyDuk.c
 *  
 *
 *  Created by Psychosis on 29/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "psyduk/includes.h"
#include "payloads/includes.h"

int main(void)
{
	PDInitialise();

	//FBShareLink_windows_P("http://hak5.org/projects/doku.php?id=usb_rubber_ducky",
	//				  "I got pwned by the USB Rubber Ducky!");
	
	//PDRunMacOSXCommand_P("open http://www.youtube.com/watch?v=EK2tWVj6lXw")
	//PDRunWindowsCommand_P("http://www.youtube.com/watch?v=EK2tWVj6lXw");
	//PDRunLinuxCommand_P("http://www.youtube.com/watch?v=EK2tWVj6lXw");
	
	PDOpenWindowsTerminalAsAdministrator();
}


