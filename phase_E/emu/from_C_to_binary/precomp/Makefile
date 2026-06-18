precom:
	gcc -E a.c > precomp.log

precom_verbose:
	gcc -E a.c --verbose > /dev/null

check_headers_search_order:
	mkdir aaa bbb
	echo '#warning I am wrong, too!' > bbb/stdio.h
	echo '#define printf(...)' >> bbb/stdio.h
	gcc -E a.c -Iaaa -Ibbb --verbose > /dev/null

riscv_precom:
	riscv64-linux-gnu-gcc -E a.c
