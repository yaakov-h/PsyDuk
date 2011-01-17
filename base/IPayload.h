#pragma once
#include "base.h"

class IPayload {
public:	
	// Not yet implemented
	virtual void LEDsChanged(uint8_t LEDs) = 0;
	
	virtual void Initialise() = 0;
	virtual bool MainLoop() = 0;
};