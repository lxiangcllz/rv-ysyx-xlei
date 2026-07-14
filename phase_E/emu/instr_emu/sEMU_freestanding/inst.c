#include "minirvEMU.h"
#include <stdint.h>

uint32_t R[16], PC;
uint8_t M[MSIZE];

void load_mem(const char *path) {
  FILE *fp = fopen(path, "rb");
  Perror(fp != NULL, "Fail to open %s", path);
  int ret = fseek(fp, 0, SEEK_END);
  Perror(ret != -1, "Fail to seek the end of the file");
  long fsize = ftell(fp);
  Perror(fsize != -1, "Fail to return the file position");
  rewind(fp);
  Assert(fsize <= MSIZE, "Program size %ld exceeds %d Bytes", fsize, MSIZE);
  ret = fread(M, 1, fsize, fp);
  Assert(ret == fsize, "Fail to load the whole program");
  fclose(fp);
}

#define HALT_ADDR 0x224
#define EBREAK_INST 0x00100073

void patch_halt_ebreak(void) {
  *(uint32_t *)&M[HALT_ADDR] = EBREAK_INST;
}
// simple test case for addi/jalr
//uint8_t M[MSIZE] = { 
//  0x13,0x05,0x40,0x01,
//  0xe7,0x00,0x00,0x01,
//  0xe7,0x00,0xc0,0x00,
//  0x67,0x00,0xc0,0x00,
//  0x13,0x05,0xa5,0x00,
//  0x67,0x80,0x00,0x00
//};

typedef union {
  struct {
    uint32_t opcode : 7;
    uint32_t rd : 5;
    uint32_t funct3 : 3;
    uint32_t rs1 : 5;
    uint32_t rs2 : 5;
    uint32_t funct7 : 7;
  } R; // add
  struct {
    uint32_t opcode : 7;
    uint32_t rd : 5;
    uint32_t funct3 : 3;
    uint32_t rs1 : 5;
    uint32_t imm : 12;
  } I; // addi/jalr/lw/lbu
  struct {
    uint32_t opcode : 7;
    uint32_t rd : 5;
    uint32_t imm : 20;
  } U; // lui
  struct {
    uint32_t opcode : 7;
    uint32_t imm4_0 : 5;
    uint32_t funct3 : 3;
    uint32_t rs1 : 5;
    uint32_t rs2 : 5;
    uint32_t imm11_5 : 7;
  } S; // sw/sb
  uint32_t bytes;
} inst_t;

int inst_cycle() {
  inst_t inst = *(inst_t *)&M[PC];
  int32_t I_imm = (int32_t)inst.bytes >> 20;
  uint32_t U_imm = inst.U.imm << 12;
  int32_t S_imm = (int32_t)(((inst.bytes >> 25) << 5) | ((inst.bytes >> 7) & 0x1f));
  S_imm = (S_imm << 20) >> 20;
  uint32_t I_addr = R[inst.I.rs1] + I_imm;
  uint32_t S_addr = R[inst.S.rs1] + S_imm;
  uint32_t* S_mem = (uint32_t*)&M[S_addr];
  switch (inst.bytes & 0x7f) {
    case 0b0110011: // add(R)
      if (inst.R.rd != 0)
        R[inst.R.rd] = R[inst.R.rs1] + R[inst.R.rs2];
      break;
    case 0b0010011: // addi(I)
      if (inst.R.rd != 0)
        R[inst.I.rd] = R[inst.I.rs1] + I_imm;
      break;
    case 0b1100111: { // jalr(I)
      uint32_t target = R[inst.I.rs1] + I_imm;
      if (inst.I.rd != 0)
        R[inst.I.rd] = PC + 4;
      PC = target;
      return 1;
    }
    case 0b0000011: // lw/lbu(I)
      switch (inst.I.funct3) {
        case 0b010: // lw
          R[inst.I.rd] = *(uint32_t*)&M[I_addr];
          break;
        case 0b100: // lbu
          R[inst.I.rd] = M[I_addr];
          break;
        default: printf("Unsupported instruction\n"); break;
      }
      break;
    case 0b0110111: // lui(U)
      R[inst.U.rd] = U_imm;
      break;
    case 0b0100011: // sw/sb(S)
      switch (inst.S.funct3) {
        case 0b010: // sw
          *S_mem = R[inst.S.rs2];
          break;
        case 0b000: // sb
          M[S_addr] = R[inst.S.rs2];
          break;
        default: printf("Unsupported instruction\n"); break;
      }
      break;
    case 0b1110011: // ebreak
      if (inst.bytes == EBREAK_INST)
        return 0;
      printf("Unsupported instruction\n");
      break;
    default: printf("Unsupported instruction\n"); break;
  }
  PC += 4;
  return 1;
}
