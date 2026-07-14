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

#define MSIZE 0x52000

extern uint32_t R[16], PC;
extern uint8_t M[MSIZE];

void load_mem(const char *path);
void patch_halt_ebreak(void);
int inst_cycle(void);

#endif
