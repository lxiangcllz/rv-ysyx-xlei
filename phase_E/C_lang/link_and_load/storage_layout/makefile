CC = gcc
CFLAGS = -O0 -g -Wall

.PHONY: all run inspect read_elf clean

all: a.out

a.out: main.c
	$(CC) $(CFLAGS) $< -o $@

run: a.out
	./a.out

# 对照源码看段、符号和段内容
inspect: a.out
	@echo "======== size ========"
	size -A a.out
	@echo
	@echo "======== nm (our objects) ========"
	nm -n a.out | grep -E ' (const_global|init_global|file_static|uninit_global|uninit_static|func_static)'
	@echo
	@echo "======== .rodata / .data contents ========"
	objdump -s -j .rodata -j .data a.out
	@echo
	@echo "======== section headers ========"
	readelf -S a.out | grep -E '\[Nr\]|\.text|\.rodata|\.data|\.bss'

read_elf: a.out
	readelf -a a.out > main.elf

clean:
	rm -f a.out main.elf
