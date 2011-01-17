#pragma once
#include "../base/base.h"
#include "../util/util.h"
#include "../base/CBasePayload.h" // This needs to be explicitly included

class PHelloWorld : public CBasePayload {
public:
	PHelloWorld();
	
	void LEDsChanged(uint8_t LEDs);
	
	void Initialise();	
	bool MainLoop();	
	void Cleanup();
};