#include <stdio.h>
#include "Vlight.h"

#define BITMASK(bits) ((1ull << (bits)) - 1)
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1))

static Vlight *top = NULL;
void cycle() { top->clk = 0; top->eval(); top->clk = 1; top->eval(); }
void reset() { top->rst = 1; cycle(); top->rst = 0; }

static void display() {
  static uint16_t last_led = 0;
  if (last_led != top->led) {
    for (int i = 0; i < 16; i ++) {
      putchar(BITS(top->led, i, i) ? 'o' : '.');
    }
    putchar('\r');
    fflush(stdout);
    last_led = top->led;
  }
}

int main() {
  top = new Vlight;
  reset();
  while (1) { cycle(); display(); }
  return 0;
}
