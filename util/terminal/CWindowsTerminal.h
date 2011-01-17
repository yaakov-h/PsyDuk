#pragma once
#include "CBaseTerminal.h"

class CWindowsTerminal : public CBaseTerminal {
public:
	void Open();
	void OpenSneaky();
	void Close();
};