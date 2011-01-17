#include "CMacTerminal.h"

void CMacTerminal::Open() {
	Keyboard.PressKey(KEY_SPACE, KEY_COMMAND);
	Delay(150);
	Keyboard.TypeString(PSTR("Terminal.app"));
	Delay(150);
	Keyboard.PressKey(KEY_ENTER);
	Delay(1000);
}

void CMacTerminal::Close() {
	/* There is no definite keycombo or terminal command to
	 * just close the active terminal tab without leaving the
	 * Terminal application open if we opened it in the first place.
	 */
	Keyboard.PressKey(KEY_W, KEY_COMMAND);
}