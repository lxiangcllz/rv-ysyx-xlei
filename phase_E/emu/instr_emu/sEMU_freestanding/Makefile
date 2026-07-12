a.bin: a.txt
	grep -Eo "[01]{8}" a.txt | perl -ne 'chomp; print pack("B8", $$_)' > a.bin
hexdump: a.bin

comp: hexdump sEMU.c
	gcc sEMU.c -g

comp_minirv: hexdump minirvEMU.c inst.c
	gcc minirvEMU.c inst.c -g

exe: a.out a.bin
	./a.out a.bin

.PHONY: clean
clean:
	rm -rf ./a.out a.bin
