#ifndef MINIRVEMU_H
#define MINIRVEMU_H

#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

#define Assert(cond, format, ...)                   \
  do {                                              \
    if (!(cond)) {                                  \
      fprintf(stderr, format "\n", ## __VA_ARGS__); \
      assert(cond);                                 \
    }                                               \
  } while (0)

#define Perror(cond, format, ...) \
  Assert(cond, format ": %s", ## __VA_ARGS__, strerror(errno))

// vga.bin is 569KB, sp=0x93000
#define MSIZE 0x100000

#define VGA_BASE 0x20000000u
// 256KB(256*256 pixels)
#define VGA_SIZE 0x40000u

extern uint32_t R[16], PC;
extern uint8_t M[MSIZE];
// vga memory: 256*256 pixels
extern uint32_t vga_fb[VGA_SIZE / 4];

void load_mem(const char *path);
void patch_halt_ebreak(uint32_t halt_addr);
int inst_cycle(void);

#endif
