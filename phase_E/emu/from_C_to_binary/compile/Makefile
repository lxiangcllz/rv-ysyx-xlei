lexical_analysis:
	clang -fsyntax-only -Xclang -dump-tokens a.c 2> lex_tokens.txt

syntax_analysis:
	clang -fsyntax-only -Xclang -ast-dump a.c

static_analysis:
	clang use_after_free.c --analyze -Xanalyzer -analyzer-output=text

IR_dump:
	clang -S -emit-llvm a.c

optimize:
	#clang -S -foptimization-record-file=- a.c
	clang -S -foptimization-record-file=- a.c -O1

obj_dump:
	clang -S a.c --target=riscv64-linux-gnu
	#riscv64-linux-gnu-gcc -S a.c

time_report:
	clang -S a.c -ftime-report

asm:
	riscv64-linux-gnu-gcc -c a.c
	#alias rv32gcc="riscv64-linux-gnu-gcc -march=rv32g -mabi=ilp32"
	#gcc -c a.c

disasm:
	#objdump -d a.o
	#riscv64-linux-gnu-objdump -d a.o
	#alias rvobjdump="riscv64-linux-gnu-objdump"
	llvm-objdump-14 -d a.o

link:
	#gcc a.c
	#gcc a.c --verbose
	#gcc a.c --verbose 2>&1 | tail -n 2 | head -n 1 | tr ' ' '\n' | grep \.o$
	riscv64-linux-gnu-gcc a.c

exec:
	#mkdir -p /etc/qemu-binfmt
	#ln -s /usr/riscv64-linux-gnu/ /etc/qemu-binfmt/riscv64
	./a.out # it actually executes in qemu.
