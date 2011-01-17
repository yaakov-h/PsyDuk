#include "PHelloWorld.h"

PHelloWorld::PHelloWorld() {

}

void PHelloWorld::LEDsChanged(uint8_t LEDs) {
	
}

void PHelloWorld::Initialise() {
	//Keyboard.TypeString(PSTR("Hello, World!\n"));
	CWindowsTerminal terminal;
	// Not working, unsure why
	terminal.Open(true);
}

bool PHelloWorld::MainLoop() {
	//Keyboard.TypeString(PSTR("LOL\n"));
	return false; // Continue
}

void PHelloWorld::Cleanup() {

}