#include "CLinuxTerminal.h"
#include "../util.h"

void CLinuxTerminal::Open() {
	RunLinuxCommand_P("xterm");
}