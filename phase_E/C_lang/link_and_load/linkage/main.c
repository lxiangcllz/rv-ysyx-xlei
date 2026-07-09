#include <stdio.h>
#include "stack.h"

//extern int top; // 'extern' cannot be omitted.


int main() {
	push('a');
	push('b');
	push('c');
	//printf("top = %d\n", top);
	while (!is_empty()) {
		putchar(pop());
	}
	putchar('\n');
	//printf("top = %d\n", top);
	return 0;
}
