#ifndef PD_RUNCOMMANDS_H
#define PD_RUNCOMMANDS_H

#include "includes.h"

void PDRunWindowsCommand(const char* command);
void PDOpenWindowsRunBox(void);
void PDRunMacOSXCommand(const char* command);
void PDRunLinuxCommand(const char* command);
void PDOpenLinuxRunBox(void);

#endif /* PD_RUNCOMMANDS_H */