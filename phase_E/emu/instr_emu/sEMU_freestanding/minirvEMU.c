#include "minirvEMU.h"
#include <am.h>
#include <klib-macros.h>
#include <string.h>

// halt addr: from sum/vga.txt
#define SUM_HALT_ADDR 0x224u
#define VGA_HALT_ADDR 0xdb0u
#define VGA_W 256
#define VGA_H 256

static uint32_t halt_addr_for(const char *prog) {
  if (strstr(prog, "vga")) return VGA_HALT_ADDR;
  return SUM_HALT_ADDR;
}

// use AM api to show vga_fb pixels
static void show_framebuffer(void) {
  ioe_init();
  io_write(AM_GPU_FBDRAW, 0, 0, vga_fb, VGA_W, VGA_H, true);
  while (1) {
  }
}

int main(int argc, char *argv[]) {
  const char *prog = (argc >= 2) ? argv[1] : "logisim-bin/sum.bin";
  load_mem(prog);
  patch_halt_ebreak(halt_addr_for(prog));
  while (inst_cycle())
    ;

  if (strstr(prog, "vga")) {
    if (R[10] != 0) {
      printf("HIT BAD TRAP\n");
      return 1;
    }
    printf("Emulation finished, displaying framebuffer...\n");
    show_framebuffer();
  }

  if (R[10] == 0)
    printf("HIT GOOD TRAP\n");
  else
    printf("HIT BAD TRAP\n");
  return 0;
}
