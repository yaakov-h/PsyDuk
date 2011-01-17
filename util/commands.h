#pragma once
#include "util.h"

#pragma mark Run Command

#define RunWindowsCommand_P( a, b )	RunWindowsCommand( PSTR( a ), PSTR( b ) )
#define RunMacCommand_P( a )		RunMacCommand( PSTR( a ) )
#define RunLinuxCommand_P( a )		RunLinuxCommand( PSTR( a ) )

void RunWindowsCommand( const char* command, bool asAdministrator);
DEPRECATED(void RunWindowsCommand( const char* command ));
void RunMacCommand( const char* command );
void RunLinuxCommand( const char* command );

#pragma mark Launch File

#define LaunchWindowsFile_P( a )	LaunchWindowsFile( PSTR( a ) )
#define	LaunchMacFile_P( a )		LaunchMacFile( PSTR( a ) )
#define LaunchLinuxFile_P( a )		LaunchLinuxFile( PSTR( a ) )

void LaunchWindowsFile( const char* file );
void LaunchMacFile( const char* file);
void LaunchLinuxFile( const char* file );

#pragma mark Launch File on volume

#define LaunchWindowsFileOnVolume_P( a, b )	LaunchWindowsFileOnVolume( PSTR( a ), PSTR( b ) )
#define LaunchMacFileOnVolume_P( a, b )		LaunchMacFileOnVolume( PSTR( a ), PSTR( b ) )
#define LaunchLinuxFileOnVolume_P( a, b )	LaunchLinuxFileOnVolume( PSTR( a ), PSTR( b ) )

void LaunchWindowsFileOnVolume( const char* file, const char* volume );
void LaunchMacFileOnVolume( const char* file, const char* volume );
void LaunchLinuxFileOnVolume( const char* file, const char* volume );