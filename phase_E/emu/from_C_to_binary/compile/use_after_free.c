#include <stdlib.h>

int main() {
	int *p = malloc(sizeof(*p) * 10);
	free(p);
	*p = 0;
	return 0;
}
