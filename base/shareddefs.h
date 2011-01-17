#pragma once

#include "keys.h" // Key Definitions

/* 
 * Set to 0 use payload classes directly or 1 to use the
 * functions in psyduk_main.cpp
 */
#define USE_DUCKY_FUNCTIONS 0
// Sets the initial payload class run
#define PAYLOAD_CLASS PHelloWorld

/*
 * These define the device's name as seen by the computer.
 * This defaults to the Apple Aluminum Keyboard to stop Mac OS X
 * prompting the user for a keyboard layout.
 */
#define STR_MANUFACTURER L"Apple Inc."
#define STR_PRODUCT      L"Aluminum Keyboard"

/*
 * From the USB keyboard example code:
 * 
 * Mac OS-X and Linux automatically load the correct drivers.  On
 * Windows, even though the driver is supplied by Microsoft, an
 * INF file is needed to load the driver.  These numbers need to
 * match the INF file.
 */
#define VENDOR_ID        0x05ac
#define PRODUCT_ID       0x0220


/*
 * From the USB keyboard example code:
 * 
 * USB devices are supposed to implment a halt feature, which is
 * rarely (if ever) used.  If you comment this line out, the halt
 * code will be removed, saving 102 bytes of space (gcc 4.3.0).
 * This is not strictly USB compliant, but works with all major
 * operating systems.
 */
#define SUPPORT_ENDPOINT_HALT

/*
 * Used for OS-dependent payloads. The Teensy cannot detect the host OS,
 * it must either be hardcoded or chosen at runtime via DIP switches, etc.
 */
typedef enum OS {
	Windows	= 0x01,
	MacOSX	= 0x02,
	Linux	= 0x04,
	ALL		= 0x08 - 1,
} OS;

#define KEY_MENU 127 // Can't remember if this works or not.

#define KEY_WINDOWS KEY_GUI
#define KEY_COMMAND KEY_GUI
#define KEY_SUPER   KEY_GUI

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