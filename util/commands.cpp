#include "commands.h"
#include "../base/base.h"

#pragma mark Run Command

void RunWindowsCommand( const char* command ) {
	Keyboard.PressKey( KEY_R, KEY_WINDOWS );
	Delay(750);
	Keyboard.TypeString( command );
	Keyboard.PressKey( KEY_ENTER );
}

void RunMacCommand( const char* command ) {
	/* Since Mac OS X has no equivalent of Start->Run,
	 * we have to run the command from a terminal.
	 */
	CMacTerminal terminal;
	terminal.Open();
	terminal.RunCommand(command);
	terminal.Close();
}

void RunLinuxCommand( const char* command ) {
	Keyboard.PressKey( KEY_F2, KEY_ALT );
	Delay(750);
	Keyboard.TypeString( command );
	Keyboard.PressKey( KEY_ENTER );
}

#pragma mark Launch File

void LaunchWindowsFile( const char* file ) {
	RunWindowsCommand(file);
}

void LaunchMacFile( const char* file) {
	CMacTerminal terminal;
	terminal.Open();
	Keyboard.TypeString(PSTR("open "));
	Keyboard.TypeString(file);
	Keyboard.PressKey(KEY_ENTER);
	terminal.Close();
}

#pragma mark Launch File on volume

void LaunchLinuxFile( const char* file ) {
	RunLinuxCommand(file);
}

void LaunchWindowsFileOnVolume( const char* file, const char* volume ) {
	CWindowsTerminal terminal;
	terminal.OpenSneaky();
}

void LaunchMacFileOnVolume( const char* file, const char* volume ) {
	/* Since Mac OS X has no equivalent of Start->Run,
	 * we have to run the command from a terminal.
	 */
	CMacTerminal terminal;
	terminal.Open();
	Keyboard.TypeString(PSTR("open /Volumes/"));
	Keyboard.TypeString(volume);
	Keyboard.TypeString(PSTR("/"));
	Keyboard.TypeString(file);
	Keyboard.PressKey(KEY_ENTER);
	terminal.Close();
}

void LaunchLinuxFileOnVolume( const char* file, const char* volume ) {
	Keyboard.PressKey( KEY_F2, KEY_ALT );
	Delay(750);
	Keyboard.TypeString(PSTR("/media/"));
	Keyboard.TypeString(volume);
	Keyboard.TypeString(PSTR("/"));
	Keyboard.TypeString(file);
	Keyboard.PressKey( KEY_ENTER );
}