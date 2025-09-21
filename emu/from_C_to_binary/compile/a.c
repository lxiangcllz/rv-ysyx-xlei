#include <stdio.h>

int main() {
	int x = 1, y = 2;
	volatile int z = x + y;
	printf("z = %d\n", z);
	return 0;
}
