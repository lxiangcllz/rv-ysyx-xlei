#include <memory>
#include <verilated.h>
#include "Vtop.h"

int main(int argc, char* argv[]) {
  Verilated::mkdir("logs");
  const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
  contextp->debug(0);
  contextp->threads(1);
  contextp->randReset(2);
  contextp->traceEverOn(true);
  contextp->commandArgs(argc, argv);
  const std::unique_ptr<Vtop> top{new Vtop{contextp.get(), "TOP"}};

  // set Vtop's input signals
  top->reset_l = 1;
  top->clk = 0;
  top->in_small = 1;
  top->in_quad = 0x1234;
  top->in_wide[0] = 0x11111111;
  top->in_wide[1] = 0x22222222;
  top->in_wide[2] = 0x3;

  while (!contextp->gotFinish()) {
    contextp->timeInc(1);
    top->clk = !top->clk;
    if (!top->clk) {
      if (contextp->time() > 1 && contextp->time() < 10) {
        top->reset_l = 0;
      } else {
        top->reset_l = 1;
      }
      top->in_quad += 0x12;
    }
    top->eval();
    VL_PRINTF("[%" PRId64 "] clk=%x rstl=%x iquad=%" PRIx64 " -> oquad=%" PRIx64
              " owide=%x_%08x_%08x\n",
              contextp->time(), top->clk, top->reset_l, top->in_quad, top->out_quad,
              top->out_wide[2], top->out_wide[1], top->out_wide[0]);
  }
  top->final();
#if VM_COVERAGE
  Verilated::mkdir("logs");
  contextp->coveragep()->write("logs/coverage.dat");
#endif
  
  contextp->statsPrintSummary();
  return 0;
}
