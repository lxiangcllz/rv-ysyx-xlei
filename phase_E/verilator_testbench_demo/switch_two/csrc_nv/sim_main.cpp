#include <nvboard.h>
#include "Vswitch.h"

void nvboard_bind_all_pins(TOP_NAME* top);

int main() {
  TOP_NAME* dut = new Vswitch;
  nvboard_bind_all_pins(dut);
  nvboard_init();

  while (1) {
    dut->eval();
    nvboard_update();
  }

  delete dut;
  return 0;
}
