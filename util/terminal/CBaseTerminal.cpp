/*
 *  CBaseTerminal.cpp
 *  Psyduk++
 *
 *  Created by Psychosis on 16/01/11.
 *  Copyright 2011 Netshroud. All rights reserved.
 *
 */

#include "CBaseTerminal.h"

CBaseTerminal::CBaseTerminal() {
}

void CBaseTerminal::RunCommand(const char* command) {
	Keyboard.TypeString(command);
	Keyboard.PressKey(KEY_ENTER);
}

