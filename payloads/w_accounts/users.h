/*
 *  users.h
 *  
 *
 *  Created by Psychosis on 25/05/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef PL_USERS_H
#define PL_USERS_H

#include <stdint.h>

#define WAAddUser_P(a,b,c) WAAddUser(PSTR(a),PSTR(b),c)
#define WAHideUserFromLogonScreen_P(a) WAHideUserFromLogonScreen(PSTR(a))
#define WAAddUserToGroup_P(a,b,c) WAAddUserToGroup(PSTR(a),PSTR(b),c)

#define REALM_LOCAL 0
#define REALM_DOMAIN 1

void WAAddUser(const char* name, const char* password, uint8_t realm);
void WAHideUserFromLogonScreen(const char* name);
void WAAddUserToGroup(const char* user, const char* group, uint8_t realm);

#endif