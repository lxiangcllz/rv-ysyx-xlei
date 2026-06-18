prog: a.c
	 riscv64-linux-gnu-gcc -march=rv32g -mabi=ilp32 -ffreestanding -nostdlib -Wl,-Ttext=0x80000000 -O2 -o $@ $^

prog.bin: prog
	riscv64-linux-gnu-objcopy -j .text -O binary $^ $@

emu: prog.bin yemu.c
	gcc -o yemu yemu.c && ./yemu prog.bin

emu2: prog.bin yemu2.c
	gcc -o yemu2 yemu2.c && ./yemu2 prog.bin

disasm:
	riscv64-linux-gnu-objdump -M no-aliases -d prog

clean:
	-rm prog prog.bin yemu yemu2
