#include "pd_utility.h"
#include "pd_defs.h"
#include "usb_keyboard.h"
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

/*
 * Initialise the Ducky
 */
void PDInitialise()
{
	/*
	 * Snippet via Paul Stoffregen
	 * Sets onboard CPU to 16MHz, allowing for
	 * slow power supplies.
	 */
	CPU_PRESCALE(CPU_125kHz);
	_delay_ms(1);           // allow slow power supply startup
	CPU_PRESCALE(CPU_16MHz); // set for 16 MHz clock
	
	LED_CONFIG;
	LED_OFF;
	
	usb_init();
	
	while (!usb_configured()){} // Wait for the host to configure itself
	
	PDDelay(2000); // Give the host extra time to load drivers and such
}
/*
 * Press and release a key
 */
void PDKeypress(uint8_t key)
{
	PDKeypressWithModifier(key, 0x00);
}

/*
 * Press and release a key, repeatedly
 */
void PDKeypressRepeated(uint8_t key, uint8_t amountOfTimes)
{
	for(uint8_t i=0; i < amountOfTimes; i++)
	{
		PDKeypress(key);
	}
}

/*
 * Press a key with modifier
 */
void PDKeypressWithModifier(uint8_t key, uint8_t modifier)
{
	usb_keyboard_press(key, modifier);
}

/*
 * Delays execution for the specified amount of milliseconds
 */
void PDDelay(double ms)
{
	_delay_ms(ms);
}

/*
 * Types a string
 */
void PDTypeString(const char* stringToType)
{
	char c;
	while ( c = pgm_read_byte(stringToType++) )
	{
		PDTypeChar(c);
	}
}

/*
 * Types a single character
 * Handles ASCII -> Keystroke conversion
 */
void PDTypeChar(char c)
{
	uint8_t keycode = 0;
	uint8_t pressShift = 0;
	
	char ascii = c;
	
	// Lowercase letters
	if ( ascii >= 97 && ascii <= 122 )
	{
		keycode = ascii - 93;
		
		// Uppercase letters
	} else if ( ascii >= 65 && ascii <= 90 ) {
		pressShift = 1;
		keycode = ascii - 61;
		
		// Numbers except 0
	} else if ( ascii >= 49 && ascii <= 57 ){
		keycode = ascii - 19;
		
		
		// Symbols
	} else {
		switch (ascii)
		{
			case 48: // 0
				keycode = KEY_0;
				break;
				
			case 10: // \n
				keycode = KEY_ENTER;
				break;
				
			case 32: // Space
				keycode = KEY_SPACE;
				break;
			case 33: // !
				keycode = KEY_1;
				pressShift = 1;
				break;
			case 34: // "
				keycode = KEY_QUOTE;
				pressShift = 1;
				break;
			case 35: // #
				keycode = KEY_3;
				pressShift = 1;
				break;
			case 36: // $
				keycode = KEY_4;
				pressShift = 1;
				break;
			case 37: // %
				keycode = KEY_5;
				pressShift = 1;
				break;
			case 38: // &
				keycode = KEY_7;
				pressShift = 1;
				break;
			case 39: // '
				keycode = KEY_QUOTE;
				break;
			case 40: // (
				keycode = KEY_9;
				pressShift = 1;
				break;
			case 41: // )
				keycode = KEY_0;
				pressShift = 1;
				break;
			case 42: // *
				keycode = KEY_8;
				pressShift = 1;
				break;
			case 43: // +
				keycode = KEY_EQUAL;
				pressShift = 1;
				break;
			case 44: // ,
				keycode = KEY_COMMA;
				break;
			case 45: // -
				keycode = KEY_MINUS;
				break;
			case 46: // .
				keycode = KEY_PERIOD;
				break;
			case 47: // /
				keycode = KEY_SLASH;
				break;
				
			case 58: // :
				keycode = KEY_SEMICOLON;
				pressShift = 1;
				break;
			case 59: // ;
				keycode = KEY_SEMICOLON;
				break;
			case 60: // <
				keycode = KEY_COMMA;
				pressShift = 1;
				break;
			case 61: // =
				keycode = KEY_EQUAL;
				break;
			case 62: // >
				keycode = KEY_PERIOD;
				pressShift = 1;
				break;
			case 63: // ?
				keycode = KEY_SLASH;
				pressShift = 1;
				break;
			case 64: // @
				keycode = KEY_2;
				pressShift = 1;
				break;
				
			case 91: // [
				keycode = KEY_LEFT_BRACE;
				break;
			case 92: // \\ (backslash)
				keycode = KEY_BACKSLASH;
				break;
			case 93: // ]
				keycode = KEY_RIGHT_BRACE;
				break;
			case 94: // ^
				keycode = KEY_6;
				pressShift = 1;
				break;
			case 95: // _
				keycode = KEY_MINUS;
				pressShift = 1;
				break;
			case 96: // `
				keycode = KEY_TILDE;
				break;
				
			case 123: // {
				keycode = KEY_LEFT_BRACE;
				pressShift = 1;
				break;
			case 124: // |
				keycode = KEY_BACKSLASH;
				pressShift = 1;
				break;
			case 125: // }
				keycode = KEY_RIGHT_BRACE;
				pressShift = 1;
				break;
			case 126: // ~
				keycode = KEY_TILDE;
				pressShift = 1;
				break;
			default:
				break;
				
		}
	}
	if ( pressShift == 1 )
	{
		PDKeypressWithModifier(keycode, KEY_SHIFT);
	} else {
		PDKeypress(keycode);
	}
}