precom:
	gcc -E a.c > precomp.log

precom_verbose:
	gcc -E a.c --verbose > /dev/null

check_headers_search_order:
	mkdir aaa bbb
	echo '#warning I am wrong, too!' > bbb/stdio.h
	echo '#define printf(...)' >> bbb/stdio.h
	gcc -E a.c -Iaaa -Ibbb --verbose > /dev/null

list_gcc_macros:
	gcc -dM -E - < /dev/null

riscv_precom:
	riscv64-linux-gnu-gcc -E a.c

list_rvgcc64_macros:
	riscv64-linux-gnu-gcc -dM -E - < /dev/null

.PHONY: clean
clean:
	rm -rf aaa bbb precomp.log
