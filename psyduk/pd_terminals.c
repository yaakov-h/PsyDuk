#include "pd_defs.h"
#include "pd_utility.h"
#include "pd_terminals.h"
#include "pd_runcommands.h"
#include <avr/pgmspace.h>

/*
 * Open a Windows Terminal as current user.
 * (Not an elevated terminal)
 */
void PDOpenWindowsTerminal()
{
	//PDRunWindowsCommand_P("cmd");
	
	// Courtesy of Vile
	PDRunWindowsCommand_P("cmd /Q /D /T:7F /F:OFF /V:OFF /K \"@echo off && mode con:RATE=31 DELAY=0 && mode con:COLS=15 LINES=1 && title . && cls");
}

void PDOpenMacOSXTerminal()
{ 
	PDKeypressWithModifier(KEY_SPACE, KEY_COMMAND);
	PDDelay(150);
	PDTypeString_P("Terminal.app");
	PDDelay(50);
	PDKeypress(KEY_ENTER);
	PDDelay(1000);
}

void PDOpenLinuxTerminal()
{
	PDRunLinuxCommand_P("xterm");
}