#pragma once

#include "IPayload.h"

class CBasePayload : public IPayload {
	
public:
	bool IsEnabled();
	virtual void Disable();
	virtual void Enable();
	virtual void Run();
	virtual void Cleanup();
	
private:
	bool m_bEnabled;
};