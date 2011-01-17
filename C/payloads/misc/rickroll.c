/*
 *  rickroll.c
 *  
 *
 *  Created by Psychosis on 25/05/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "psyduk/includes.h"
#include "payloads/includes.h"

void RRWindows()
{
	PDRunWindowsCommand_P("http://www.youtube.com/watch?v=EK2tWVj6lXw");
}

void RRMacOSX()
{
	PDRunMacOSXCommand_P("open http://www.youtube.com/watch?v=EK2tWVj6lXw");
}

void RRLinux()
{
	PDRunLinuxCommand_P("http://www.youtube.com/watch?v=EK2tWVj6lXw");
}