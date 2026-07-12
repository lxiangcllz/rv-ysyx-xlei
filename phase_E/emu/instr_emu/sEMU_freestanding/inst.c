#include "minirvEMU.h"

uint32_t R[16], PC;
uint8_t M[MSIZE];

void inst_cycle() {
  uint32_t inst = *(uint32_t *)&M[PC];
  if (((inst & 0x7f) == 0x13) && ((inst >> 12) & 0x7) == 0) { // addi
    if (((inst >> 7) & 0x1f) != 0) {
      R[(inst >> 7) & 0x1f] = R[(inst >> 15) & 0x1f] +
        (((inst >> 20) & 0x7ff) - ((inst & 0x80000000) ? 4096 : 0));
    }
  }
  /* else if (...) { ... } */
  else { printf("Unsupported instuction\n"); }
  PC += 4;
}
