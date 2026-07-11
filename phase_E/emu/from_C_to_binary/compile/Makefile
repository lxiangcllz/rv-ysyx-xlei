lexical_analysis:
	clang -fsyntax-only -Xclang -dump-tokens a.c 2> lex_tokens.txt

syntax_analysis:
	clang -fsyntax-only -Xclang -ast-dump=json a.c > ast.json

static_analysis:
	clang use_after_free.c --analyze -Xanalyzer -analyzer-output=text

llvmIR:
	clang -S -emit-llvm a.c > a.ll 2>&1
IR_dump: llvmIR

optimize:
	#clang -S -foptimization-record-file=- a.c -O1
	clang -S -emit-llvm -O1 a.c > a.ll 2>&1 -ftime-report

optimize_report:
	clang -S -emit-llvm -O1 a.c -ftime-report

rv_asm:
	clang -S a.c --target=riscv64-linux-gnu
	#riscv64-linux-gnu-gcc -S a.c
codegen: rv_asm

codegen_opt:
	clang -S -O1 a.c --target=riscv64-linux-gnu

rv_obj:
	clang -c --target=riscv64-linux-gnu a.c
	#riscv64-linux-gnu-gcc -c a.c

disasm:
	riscv64-linux-gnu-objdump -d a.o
	#llvm-objdump-14 -d a.o

rv_exe:
	riscv64-linux-gnu-gcc a.c --verbose
	# clang a.c --target=riscv64-linux-gnu
	#gcc a.c --verbose 2>&1 | tail -n 2 | head -n 1 | tr ' ' '\n' | grep \.o$

exec:
	#apt-get install qemu-user qemu-user-binfmt
	#mkdir -p /etc/qemu-binfmt
	#ln -s /usr/riscv64-linux-gnu/ /etc/qemu-binfmt/riscv64
	./a.out # it actually executes in qemu.

running_trace:
	strace ./a.out

.PHONY: clean
clean:
	rm -rf lex_tokens.txt ast.json a.ll a.s a.o a.out
