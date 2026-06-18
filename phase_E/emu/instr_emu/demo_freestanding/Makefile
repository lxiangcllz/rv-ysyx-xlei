comp_freestanding: b.c
	riscv64-linux-gnu-gcc -march=rv32g -mabi=ilp32 -ffreestanding -nostdlib -Wl,-Ttext=0x80000000 -O2 b.c

qemu_exec: comp_freestanding
	qemu-system-riscv32 -nographic -M virt -bios none -kernel a.out

.PHONY: clean
clean:
	rm ./a.out
