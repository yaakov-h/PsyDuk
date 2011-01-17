#pragma once

class ITerminal {
	virtual void Open() = 0;
	virtual void RunCommand(const char* command) = 0;
	virtual void Close() = 0;
};