#ifndef PD_DEFS_H
#define PD_DEFS_H

#define OS_WINDOWS 0x01
#define OS_MACOSX  0x02
#define OS_LINUX   0x04
#define OS_ALL     0x08 - 1

#define KEY_MENU 127

#define KEY_WINDOWS KEY_GUI
#define KEY_COMMAND KEY_GUI
#define KEY_SUPER   KEY_GUI

#define PDTypeString_P(s) PDTypeString(PSTR(s))
#define PDRunWindowsCommand_P(s) PDRunWindowsCommand(PSTR(s))
#define PDRunMacOSXCommand_P(s) PDRunMacOSXCommand(PSTR(s))
#define PDRunLinuxCommand_P(s) PDRunLinuxCommand(PSTR(s))

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00
#define CPU_8MHz        0x01
#define CPU_4MHz        0x02
#define CPU_2MHz        0x03
#define CPU_1MHz        0x04
#define CPU_500kHz      0x05
#define CPU_250kHz      0x06
#define CPU_125kHz      0x07
#define CPU_62kHz       0x08

#endif