#include "CWindowsTerminal.h"
#include "../util.h"

void CWindowsTerminal::Open() {
	RunWindowsCommand_P( "cmd" );
}

void CWindowsTerminal::OpenSneaky() {
	RunWindowsCommand_P( "cmd /Q /D /T:7F /F:OFF /V:OFF /K \"@echo off && mode con:RATE=31 DELAY=0 && mode con:COLS=15 LINES=1 && title . && cls" );
}

void CWindowsTerminal::Close() {
	RunCommand(PSTR("exit"));
}