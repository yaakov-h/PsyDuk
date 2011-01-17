#pragma once
#include "IKeyboard.h"
#include "IPayload.h"

#include "CUSBKeyboard.h"

/*
 * This class handles the operation of the Teensy.
 * Currently it handles initialisation and the run loop.
 * (If you can call it that.)
 */

class CPsydukCore {

public:
	CPsydukCore();
	~CPsydukCore();
	
	void Initialise();
	void Run();
	void Shutdown();	
private:
	void Loop();
	
	bool m_bIsInitialised;
};

void DuckyStart		(CPsydukCore * core);
bool DuckyRunLoop	(CPsydukCore * core);

void Delay(uint16_t ms);