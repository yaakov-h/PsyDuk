/*
 *  backdoor.h
 *  
 *
 *  Created by Psychosis on 25/05/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PL_BACKDOOR_H
#define PL_BACKDOOR_H

#include <stdint.h>

#define WACreateBackdoor_P(a,b,c) WACreateBackdoor(PSTR(a),PSTR(b),c)
void WACreateBackdoor(const char* name, const char* password, uint8_t realm);

#endif