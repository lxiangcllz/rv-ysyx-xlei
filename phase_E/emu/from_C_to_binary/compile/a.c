#include <stdio.h>

int main() {
	volatile int x = 10, y = 20;
	int z = x + y;
	printf("z = %d\n", z);
	return 0;
}
