/*
 * minirvEMU is a guest program with main(argc, argv) running in
 * Linux hosted environment. But AM's platform.o has
 * init_platform()  __attribute__((constructor)), it will run
 * first when bootup and conflict with minirvEMU's main, which
 * leads to crash.
 * So we need just link related objects(AM_A of Makefile) of AM,
 * not others especailly platform.o.
 * But some symbols used in objects of $AM_A  are defined in 
 * platform.o, so minimal stub need provided to do successful
 * linking and run.
 * Then we can run minirvEMU's main and call AM's GPU related
 * APIs(ioe_init/io_write).
 */
#include <stdlib.h>
#include <stdint.h>

// make sure symbols won't be changed when linking with g++
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  void *vm_head;
  uintptr_t ksp;
  int cpuid;
  struct {
    int event;
    uintptr_t cause, ref;
    const char *msg;
  } ev;
  uint8_t sigstack[32768];
} __am_cpu_t;

// stub symbols
// AM multicore/interrupt code need per-CPU
__am_cpu_t *__am_cpu_struct;
static __am_cpu_t boot_cpu;
// declare single CPU
int __am_ncpu = 1;

__attribute__((constructor(101)))
static void am_host_boot(void) {
  // __am_cpu_struct just point to static variable and return,
  // no mmap or calling main or trapping is needed.
  __am_cpu_struct = &boot_cpu;
  boot_cpu.cpuid = 0;
}

void __am_platform_dummy(void) {
}

// halt calls exit eventually
void __am_exit_platform(int code) {
  exit(code);
}

void __am_init_timer_irq(void) {
}

void __am_send_kbd_intr(void) {
}

#ifdef __cplusplus
}
#endif
