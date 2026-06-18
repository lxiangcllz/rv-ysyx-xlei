#include <stdint.h>

void _start() {
	volatile uint8_t *p = (uint8_t *)(uintptr_t)0x10000000;
	*p = 'A';
	volatile uint32_t *exit = (uint32_t *)(uintptr_t)0x100000;
	*exit = 0x5555; // magic number
	_start();
}
