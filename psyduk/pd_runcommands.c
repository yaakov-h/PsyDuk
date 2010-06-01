#include "includes.h"

void PDRunWindowsCommand(const char* command)
{
	PDOpenWindowsRunBox();
	PDTypeString(command);
	PDKeypress(KEY_ENTER);
}

void PDOpenWindowsRunBox()
{
	PDKeypressWithModifier(KEY_R, KEY_WINDOWS);
	PDDelay(750);
}

void PDRunMacOSXCommand(const char* command)
{
	PDOpenMacOSXTerminal();
	PDTypeString(command);
	PDTypeString_P(" && killall Terminal\n");
}

void PDRunLinuxCommand(const char* command)
{
	PDOpenLinuxRunBox();
	PDTypeString(command);
	PDDelay(100);
	PDKeypress(KEY_ENTER);
}

void PDOpenLinuxRunBox()
{
	PDDelayedKeypressWithModifier(KEY_F2, KEY_ALT);
	PDDelay(500);
}

