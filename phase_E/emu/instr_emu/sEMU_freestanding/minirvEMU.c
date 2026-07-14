#include "minirvEMU.h"

int main(int argc, char *argv[]) {
  const char *prog = (argc >= 2) ? argv[1] : "logisim-bin/sum.bin";
  load_mem(prog);
  patch_halt_ebreak();
  while (inst_cycle())
    ;
  if (R[10] == 0)
    printf("HIT GOOD TRAP\n");
  else
    printf("HIT BAD TRAP\n");
  return 0;
}
