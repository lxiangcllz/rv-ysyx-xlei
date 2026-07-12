comp_freestanding: b.c
	riscv64-linux-gnu-gcc -ffreestanding -nostdlib -Wl,-Ttext=0x80000000 -O2 a.c

rv64_disasm:
	riscv64-linux-gnu-objdump -d a.out

qemu_exec: comp_freestanding
	qemu-system-riscv64 -nographic -M virt -bios none -kernel a.out

.PHONY: clean
clean:
	rm ./a.out
