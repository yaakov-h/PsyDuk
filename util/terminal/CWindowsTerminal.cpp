#include "CWindowsTerminal.h"
#include "../util.h"

void CWindowsTerminal::Open() {
	Open(false);
}

void CWindowsTerminal::Open(bool asAdministrator) {
	RunWindowsCommand( PSTR("cmd.exe"), asAdministrator);
}

void CWindowsTerminal::OpenSneaky(bool asAdministrator) {
	RunWindowsCommand( PSTR("cmd.exe /Q /D /T:7F /F:OFF /V:OFF /K \"@echo off && mode con:RATE=31 DELAY=0 && mode con:COLS=15 LINES=1 && title . && cls"),
					  asAdministrator);
}

void CWindowsTerminal::Close() {
	RunCommand(PSTR("exit"));
}