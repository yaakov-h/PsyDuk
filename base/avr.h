#include <stdlib.h>

// Taken from AVRFreaks. Untested.

void * operator new(size_t size);
void operator delete(void * ptr);
extern "C" void __cxa_pure_virtual(void);