#include "VSerial_receiver_parity.h"
#include "VSerial_receiver_parity___024root.h"
#include "verilator_tb.hpp"
#include "vcd_path.h"
#include <cstdint>
#include <cstdio>

#ifndef VCD_ABS_PATH
#define VCD_ABS_PATH "waveform.vcd"
#endif

#define MAX_SIM_TIME 100
#define VERI_START_TIME 2

int main(int argc, char *argv[]) {
  VerilatorTb<TOP_NAME> sim(argc, argv, true, VCD_ABS_PATH);
  TOP_NAME* dut = sim.dut();
  VerilatedContext* contextp = sim.context();

  dut->in = 0b1;
  uint64_t posedge_cnt = 0;
  uint64_t curtime = contextp->time();
  while (curtime < MAX_SIM_TIME) {
    if (curtime < VERI_START_TIME) {
      dut->reset = 1;
    } else {
      dut->reset = 0;
    }
    dut->clk ^= 1; // toggle clock
    dut->eval();   // simulate
    if (dut->clk == 1) {
      posedge_cnt++;
      switch (posedge_cnt) {
        case 2: dut->in = 0b0; break; // start
        case 3: dut->in = 0b1; break; // data0
        case 5: dut->in = 0b0; break;
        case 6: dut->in = 0b1; break;
        case 7: dut->in = 0b0; break;
        case 9: dut->in = 0b1; break;
        case 10: dut->in = 0b0; break; // data7
        case 11: dut->in = 0b1; break; // parity and stop
        case 13: dut->in = 0b0; break; // another start
      }
    }
    if (VerilatedVcdC* t = sim.trace()) {
      t->dump(curtime);
    }
    contextp->timeInc(1);
    curtime = contextp->time();
  }
  return 0;
}
