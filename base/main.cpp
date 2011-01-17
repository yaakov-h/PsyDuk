#include "base/CPsydukCore.h"

int main() {
	CPsydukCore core;
	core.Initialise();
	core.Run();
	core.Shutdown();
}
