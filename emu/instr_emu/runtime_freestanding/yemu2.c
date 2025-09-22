// This is optimized version of yemu.c
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "yemu.h"


uint32_t R[32], PC;
uint8_t M[MSIZE]; // memory buffer for generated instructions
bool halt = false;

typedef union {
	struct {
		uint32_t opcode : 7;
		uint32_t rd     : 5;
		uint32_t funct3 : 3;
		uint32_t rs1    : 5;
		int32_t imm11_0 : 12;
	} I;
	//struct { /*...*/ } R;
	uint32_t bytes;
} inst_t;

#define panic(format, ...) \
	fprintf(stderr, format "\n", ## __VA_ARGS__)

void inst_cycle() {
	// fetch
	inst_t* inst = (inst_t*)&M[PC];
	uint32_t rd = inst->I.rd;
	uint32_t rs1 = inst->I.rs1;
	uint32_t imm = (int32_t)inst->I.imm11_0;
	// decode & execute
	if (inst->I.opcode == 0b0010011) {
		switch (inst->I.funct3) {
			case 0b000: R[rd] = R[rs1] + imm; break; // addi
			case 0b100: R[rd] = R[rs1] ^ imm; break; // xori
			case 0b110: R[rd] = R[rs1] | imm; break; // ori
			case 0b111: R[rd] = R[rs1] & imm; break; // andi
			default: panic("Unsupported funct3 = %d", inst->I.funct3);
		}
		R[0] = 0; // if instr is miswritten into R[0], reset it
	} else if (inst->bytes == 0x00100073) { // ebreak
		if (R[10] == 0) { putchar(R[11] & 0xff); }
		else if (R[10] == 1) { halt = true; }
		else { printf("Unsupported ebreak command\n"); }
	} else { printf("Unsupported instuction\n"); }
	// update PC
	PC += 4;
}

#define Assert(cond, format, ...) \
	do { \
		if (!(cond)) { \
			fprintf(stderr, format "\n", ## __VA_ARGS__); \
			assert(cond); \
		} \
	} while (0)

#define Perror(cond, format, ...) \
	Assert(cond, format ": %s", ## __VA_ARGS__, strerror(errno))

int main(int argc, char** argv) {
	PC = 0; R[0] = 0;
	Assert(argc >= 2, "Program is not given");
	FILE* fp = fopen(argv[1], "r");
	Perror(fp != NULL, "Fail to open %s", argv[1]);
	int ret = fseek(fp, 0, SEEK_END); // sets file position indicator to the end-of-file
	Perror(ret != -1, "Fail to seek the end of the file");
	long fsize = ftell(fp); // gets current value of file position indicator(now it's the eof)
	Perror(fsize != -1, "Fail to return the file position");
	rewind(fp); // sets file position indicator to the beginning of file
	Assert(fsize < MSIZE, "Program size exceeds %d Bytes", MSIZE);
	ret = fread(M, 1, MSIZE, fp);
	Assert(ret == fsize, "Fail to load the whole program"); // read the total contents of file
	fclose(fp);
	while (!halt) { inst_cycle(); }
	return 0;
}
