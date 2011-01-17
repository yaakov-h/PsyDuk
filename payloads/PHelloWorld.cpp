#include "PHelloWorld.h"

PHelloWorld::PHelloWorld() {
	
}

void PHelloWorld::LEDsChanged(uint8_t LEDs) {
	
}

void PHelloWorld::Initialise() {
	Keyboard.TypeString(PSTR("Hello, World!\n"));
}

bool PHelloWorld::MainLoop() {
	Keyboard.TypeString(PSTR("LOL\n"));
	return true; // Continue
}

void PHelloWorld::Cleanup() {

}