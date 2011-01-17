#include "psyduk.h"

/*
 * To change the USB identifiers, see base/shareddefs.h
 */

/*
 * This function gets called once after the device has initialised.
 */

void DuckyStart		(CPsydukCore * core) {
	CMacTerminal terminal;
	terminal.Open();
	terminal.RunCommand(PSTR("echo DuckyPwnd++!"));
	terminal.Close();
}

/*
 * This function will get called continuously until it either returns false or
 * the Teensy loses power (e.g. gets unplugged).
 */
bool DuckyRunLoop	(CPsydukCore * core) {
	return true;
}