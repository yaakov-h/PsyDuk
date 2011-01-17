#pragma once
#include "CBaseTerminal.h"

class CWindowsTerminal : public CBaseTerminal {
public:
	void Open();
	void Open(bool asAdministrator);
	void OpenSneaky(bool asAdministrator);
	void Close();
};