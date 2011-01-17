#include "avr.h"

void * operator new(size_t size) {
	return malloc(size);
}

void operator delete(void * ptr) {
	free(ptr);
}

void __cxa_pure_virtual(void) {
}