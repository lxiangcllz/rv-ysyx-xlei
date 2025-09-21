#include <stdio.h>

#define MSG "Hello \
World!\n"

int main() {
	printf(MSG);
#ifdef __riscv
	printf("Hello RISC-V!\n");
#endif
	return 0;
}
