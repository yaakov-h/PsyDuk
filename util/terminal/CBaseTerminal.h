#pragma once
#include "../../base/base.h"
#include "ITerminal.h"

class CBaseTerminal : public ITerminal {
public:
	CBaseTerminal();
	virtual void RunCommand(const char* command);
};