#include <stdint.h>

void _start() {
	volatile uint8_t *p = (uint8_t*)(uintptr_t)0x10000000;
	*p = 'A';
	while (1);
}
