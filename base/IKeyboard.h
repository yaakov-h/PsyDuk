#pragma once

#include <stdint.h>
#include <avr/pgmspace.h>

class IKeyboard {
public:
	virtual bool IsConfigured() = 0;
	virtual void PressKey(uint8_t key) = 0;
	virtual void PressKey(uint8_t key, uint8_t modifier) = 0;
	virtual void PressKey(uint8_t key, uint8_t modifier, uint8_t repeatCount) = 0;
	virtual void PressKey(uint8_t key, uint8_t modifier, uint8_t repeatCount, uint16_t modifierDelay) = 0;
	virtual void TypeString(const char* string) = 0;
	virtual void TypeChar(char c) = 0;
};

/*
 * Convenience function. Internally this returns whatever keyboard implementation
 * we're using. Currently the only implementation is CUSBKeyboard based on the USB
 * keyboard example code, though this may change.
 *
 * Dunno why, but nonetheless I think it's useful.
 */
#define CURRENT_KEYBOARD CUSBKeyboard
IKeyboard * _Keyboard();
#define Keyboard (*( CURRENT_KEYBOARD * )(_Keyboard()))