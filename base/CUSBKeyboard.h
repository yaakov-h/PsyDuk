#pragma once

#include <stdint.h>
#include <stdlib.h>
#include "IKeyboard.h"

class CUSBKeyboard : public IKeyboard {
public:
	// Singleton
	static CUSBKeyboard * Instance();
	
	// IKeyboard
	bool IsConfigured();
	void PressKey(uint8_t key);
	void PressKey(uint8_t key, uint8_t modifier);
	void PressKey(uint8_t key, uint8_t modifier, uint8_t repeatCount);
	void PressKey(uint8_t key, uint8_t modifier, uint8_t repeatCount, uint8_t modifierDelay);
	void TypeString(const char* string);
	void TypeChar(char c);
	
	CUSBKeyboard();
	~CUSBKeyboard();
};

static CUSBKeyboard gpUSBKeyboard;