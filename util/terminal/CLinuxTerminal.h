#pragma once
#include "CBaseTerminal.h"

class CLinuxTerminal : public CBaseTerminal {
public:
	void Open();
	void Close();
};