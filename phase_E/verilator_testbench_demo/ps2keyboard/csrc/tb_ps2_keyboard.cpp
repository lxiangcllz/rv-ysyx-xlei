#include "Vps2_keyboard.h"
#include "verilator_tb.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>

namespace {

constexpr int kSysHalfPeriod = 5;      // clk 周期 10ns
constexpr int kKbdClkPeriod = 60;      // 键盘时钟 60ns，加速仿真
constexpr int kKbdHalfTicks = (kKbdClkPeriod / 2) / (kSysHalfPeriod * 2);

struct Sim {
  VerilatorTb<TOP_NAME> tb;
  TOP_NAME* dut;
  int errors = 0;

  explicit Sim(int argc, char** argv)
      : tb(argc, argv, true, "waveform.vcd"), dut(tb.dut()) {}

  void eval_dump() {
    dut->eval();
    if (VerilatedVcdC* t = tb.trace()) {
      t->dump(tb.context()->time());
    }
  }

  void tick() {
    dut->clk = 0;
    eval_dump();
    tb.context()->timeInc(kSysHalfPeriod);
    dut->clk = 1;
    eval_dump();
    tb.context()->timeInc(kSysHalfPeriod);
  }

  void wait_cycles(int n) {
    while (n-- > 0) {
      tick();
    }
  }

  void reset() {
    dut->clrn = 0;
    dut->nextdata_n = 1;
    dut->ps2_clk = 1;
    dut->ps2_data = 1;
    wait_cycles(4);
    dut->clrn = 1;
    wait_cycles(2);
  }

  // 等价于讲义 ps2_keyboard_model.kbd_sendcode
  void kbd_sendcode(uint8_t code) {
    const int start = 0;
    const int stop = 1;
    const int parity = !__builtin_parity(code);
    const int frame[11] = {
        start,
        (code >> 0) & 1, (code >> 1) & 1, (code >> 2) & 1, (code >> 3) & 1,
        (code >> 4) & 1, (code >> 5) & 1, (code >> 6) & 1, (code >> 7) & 1,
        parity,
        stop,
    };

    std::printf("  send 0x%02X  frame=", code);
    for (int bit : frame) {
      std::putchar('0' + bit);
    }
    std::putchar('\n');

    for (int i = 0; i < 11; ++i) {
      dut->ps2_data = frame[i];
      wait_cycles(kKbdHalfTicks);
      dut->ps2_clk = 0;
      wait_cycles(kKbdHalfTicks);
      dut->ps2_clk = 1;
    }
    wait_cycles(4);
  }

  bool read_byte(uint8_t* out, int timeout = 40) {
    for (int i = 0; i < timeout && !dut->ready; ++i) {
      tick();
    }
    if (!dut->ready) {
      std::printf("  ERROR: timeout waiting for ready\n");
      ++errors;
      return false;
    }

    *out = static_cast<uint8_t>(dut->data);
    std::printf("  recv 0x%02X  ready=%d overflow=%d\n",
                *out, dut->ready, dut->overflow);

    dut->nextdata_n = 0;
    tick();
    dut->nextdata_n = 1;
    tick();
    return true;
  }

  void expect_eq(uint8_t got, uint8_t exp, const char* what) {
    if (got != exp) {
      std::printf("  FAIL %s: got 0x%02X, expect 0x%02X\n", what, got, exp);
      ++errors;
    }
  }
};

}  // namespace

int main(int argc, char** argv) {
  Sim sim(argc, argv);
  sim.reset();

  std::printf("=== press 'A' then release: 1C F0 1C ===\n");
  uint8_t b = 0;

  sim.kbd_sendcode(0x1C);
  if (sim.read_byte(&b)) {
    sim.expect_eq(b, 0x1C, "press A");
  }

  sim.kbd_sendcode(0xF0);
  if (sim.read_byte(&b)) {
    sim.expect_eq(b, 0xF0, "break prefix");
  }

  sim.kbd_sendcode(0x1C);
  if (sim.read_byte(&b)) {
    sim.expect_eq(b, 0x1C, "release A");
  }

  std::printf("=== hold 'S': 1B 1B 1B F0 1B ===\n");
  sim.kbd_sendcode(0x1B);
  sim.kbd_sendcode(0x1B);
  sim.kbd_sendcode(0x1B);
  sim.kbd_sendcode(0xF0);
  sim.kbd_sendcode(0x1B);

  const uint8_t expect_s[] = {0x1B, 0x1B, 0x1B, 0xF0, 0x1B};
  for (uint8_t exp : expect_s) {
    if (!sim.read_byte(&b)) {
      break;
    }
    sim.expect_eq(b, exp, "hold S stream");
  }

  sim.wait_cycles(10);
  sim.dut->final();

  if (sim.errors) {
    std::printf("=== FAILED with %d error(s) ===\n", sim.errors);
    return 1;
  }
  std::printf("=== PASS ===\n");
  std::printf("waveform: waveform.vcd\n");
  return 0;
}
