#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <verilated.h>
#include "Vswitch.h"
#include <memory>
#include <time.h>

#define MAX_SIM_TIME 10

int main(int argc, char* argv[]) {
  Verilated::mkdir("logs");
  const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
  contextp->traceEverOn(true);
  contextp->commandArgs(argc, argv);
  const std::unique_ptr<Vswitch> top{new Vswitch{contextp.get(), "TOP"}};

  srand(time(NULL));

  uint64_t cur_time = 0;
  while (cur_time <= MAX_SIM_TIME) {
    int a = rand() & 1;
    int b = rand() & 1;
    top->a = a;
    top->b = b;
    top->eval();
    printf("[%lu] a = %d, b = %d, f = %d\n", cur_time, a, b, top->f);
    assert(top->f == (a ^ b));
    contextp->timeInc(1);
    cur_time = contextp->time();
  }
  top->final();
  contextp->statsPrintSummary();
  return 0;
}
