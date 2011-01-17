#include "CUSBKeyboard.h"


#include "usb_keyboard.h"
#include "Keys.h"
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "CPsydukCore.h"

IKeyboard * _Keyboard() {
	return CUSBKeyboard::Instance();
}

CUSBKeyboard * CUSBKeyboard::Instance() {
	return &gpUSBKeyboard;
}

bool CUSBKeyboard::IsConfigured() {
	return !!usb_configured();
}

void CUSBKeyboard::PressKey(uint8_t key) {
	PressKey(key, 0);
}

void CUSBKeyboard::PressKey(uint8_t key, uint8_t modifier) {
	PressKey(key, modifier, 1);
}

void CUSBKeyboard::PressKey(uint8_t key, uint8_t modifier, uint8_t repeatCount) {
	PressKey(key, modifier, repeatCount, 0);
}

void CUSBKeyboard::PressKey(uint8_t key, uint8_t modifier, uint8_t repeatCount, uint8_t modifierDelay) {
	for ( uint16_t i = 0; i < repeatCount; i++ ) {
		keyboard_modifier_keys = modifier;
		usb_keyboard_send();
		
		if ( modifierDelay > 0 )
			Delay( modifierDelay / 2 );
		
		keyboard_keys[0] = key;
		usb_keyboard_send();
		
		if ( modifierDelay > 0 )
			Delay( modifierDelay / 2 );
		
		keyboard_modifier_keys = 0;
		keyboard_keys[0] = 0;
		usb_keyboard_send();	
	}
}

void CUSBKeyboard::TypeString(const char* string) {
	char c;
	while (( c = pgm_read_byte(string++) ))
	{
		TypeChar(c);
	}
}

void CUSBKeyboard::TypeChar(char c) {
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
		PressKey(keycode, KEY_SHIFT);
	} else {
		PressKey(keycode);
	}
}

CUSBKeyboard::CUSBKeyboard() {
	usb_init();
}

CUSBKeyboard::~CUSBKeyboard() {

}
