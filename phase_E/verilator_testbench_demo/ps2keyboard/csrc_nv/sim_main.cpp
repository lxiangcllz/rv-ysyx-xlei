#include "verilator_tb.hpp"
#include "Vkeyboard_top.h"
#include <nvboard.h>

void nvboard_bind_all_pins(TOP_NAME* top);

static void single_cycle(TOP_NAME* dut) {
  dut->clk = 0;
  dut->eval();
  dut->clk = 1;
  dut->eval();
}

int main(int argc, char** argv) {
  VerilatorTb<TOP_NAME> sim(argc, argv, false);
  TOP_NAME* dut = sim.dut();

  nvboard_bind_all_pins(dut);
  nvboard_init();

  dut->rst_n = 0;
  for (int i = 0; i < 10; ++i) {
    single_cycle(dut);
  }
  dut->rst_n = 1;

  while (1) {
    nvboard_update();
    single_cycle(dut);
  }

  return 0;
}
