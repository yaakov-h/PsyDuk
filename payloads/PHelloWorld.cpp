#include "payloads.h"

class PHelloWorld : public CBasePayload {
public:
	PHelloWorld();
	
	void LEDsChanged(uint8_t LEDs) {
		
	}
	
	void Initialise() {
		Keyboard.TypeString(PSTR("Hello, World!"));
	};
	
	bool MainLoop() {
		return true; // Continue
	}
	
	void Cleanup() {
		
	}
};