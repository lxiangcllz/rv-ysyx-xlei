#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint32_t R[32], PC;
uint8_t M[1024]; // memory buffer for generated instructions
bool halt = false;

void inst_cycle() {
	// fetch
	uint32_t inst = *(uint32_t *)&M[PC];
	// decode & execute
	if (((inst & 0x7f) == 0x13) && ((inst >> 12) & 0x7) == 0) { // addi
		if (((inst >> 7) & 0x1f) != 0) {
			R[(inst >> 7) & 0x1f] = R[(inst >> 15) & 0x1f] +
				(((inst >> 20) & 0x7ff) - ((inst & 0x80000000) ? 4096 : 0));
		}
	} else if (inst == 0x00100073) { // ebreak
		if (R[10] == 0) { putchar(R[11] & 0xff); }
		else if (R[10] == 1) { halt = true; }
		else { printf("Unsupported ebreak command\n"); }
	} else { printf("Unsupported instuction\n"); }
	// update PC
	PC += 4;
}
int main(int argc, char** argv) {
	PC = 0; R[0] = 0; // can be omitted since uninitialized global variables are initialized with 0
	FILE* fp = fopen(argv[1], "r");
	fread(M, 1, 1024, fp);
	fclose(fp);
	while (!halt) { inst_cycle(); }
	return 0;
}
