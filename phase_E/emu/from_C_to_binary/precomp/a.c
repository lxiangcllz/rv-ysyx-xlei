#include <stdio.h>

#define MSG "Hello \
World!\n"

#define _str(x) #x
#define _concat(a, b) a##b

int main() {
	printf(MSG);
#ifdef __riscv
	printf("Hello RISC-V!\n");
#endif
  _concat(pr, intf)(_str(RISC-V));
	return 0;
}
