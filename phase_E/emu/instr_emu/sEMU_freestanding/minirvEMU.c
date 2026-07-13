#include "minirvEMU.h"

void inst_cycle();

int main(int argc, char *argv[]) {
  const char *prog = (argc >= 2) ? argv[1] : "logisim-bin/sum.bin";
  load_mem(prog);
  for (int i = 0; i < 100; i ++) { 
    inst_cycle();
  }
  return 0;
}
