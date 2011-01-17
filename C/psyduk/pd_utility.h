#ifndef PD_UTILITY_H
#define PD_UTILITY_H

#include "includes.h"

void PDInitialise(void);
void PDKeypress(uint8_t key);
void PDKeypressRepeated(uint8_t key, uint8_t amountOfTimes);
void PDKeypressWithModifier(uint8_t key, uint8_t modifier);
void PDDelayedKeypressWithModifier(uint8_t key, uint8_t modifier);
void PDTypeString(const char* stringToType);
void PDTypeChar(char c);
void PDKeypressWithModifier(uint8_t key,uint8_t modifier);
void PDDelay(double delay);


#endif /* PD_UTILITY_H */
