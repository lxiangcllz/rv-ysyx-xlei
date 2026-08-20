#include "Vsync_data_hs.h"
#include "verilator_tb.hpp"
#include <cstdint>
#include <cstdio>

const int MAX_SIM_TIME = 2000;
const int SRC_CLK_PERIOD = 10;    // 100MHz (10ns)  source
const int DST_CLK_PERIOD = 50;    // 20MHz  (50ns)  destination
const int TIME_STEP = SRC_CLK_PERIOD / 2;

const uint8_t WORDS[] = {0xA5, 0x3C, 0x12};
const int NWORDS = 3;

int main(int argc, char *argv[]) {
  VerilatorTb<TOP_NAME> sim(argc, argv);
  TOP_NAME* dut = sim.dut();

  dut->clk_src = 0; dut->clk_dst = 0;
  dut->rst_n = 0; dut->send = 0; dut->data_in = 0;

  int wr_idx = 0;
  uint64_t curtime = 0;
  while (curtime < MAX_SIM_TIME) {
    const bool src_edge =
        (curtime != 0) && (curtime % (SRC_CLK_PERIOD / 2) == 0);
    const bool dst_edge =
        (curtime != 0) && (curtime % (DST_CLK_PERIOD / 2) == 0);

    if (src_edge)
      dut->clk_src ^= 1;
    if (dst_edge)
      dut->clk_dst ^= 1;

    if (curtime >= 40)
      dut->rst_n = 1;

    const bool src_posedge = src_edge && dut->clk_src;
    const bool dst_posedge = dst_edge && dut->clk_dst;

    if (src_posedge) {
      if (dut->rst_n && curtime >= 80 && !dut->busy && wr_idx < NWORDS) {
        dut->data_in = WORDS[wr_idx];
        dut->send = 1;
        wr_idx++;
      } else {
        dut->send = 0;
      }
    }

    dut->eval();
    if (VerilatedVcdC* t = sim.trace()) {
      t->dump(curtime);
    }

    if (src_posedge && dut->send) {
      std::printf("Time: %luns, [src] send data=0x%02x\n",
                  (unsigned long)curtime, (unsigned)dut->data_in);
    }
    if (dst_posedge && dut->recv) {
      std::printf("Time: %luns, [dst] recv data=0x%02x\n",
                  (unsigned long)curtime, (unsigned)dut->data_out);
    }

    curtime += TIME_STEP;
  }
  return 0;
}
