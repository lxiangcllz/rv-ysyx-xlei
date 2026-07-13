a.bin: a.txt
	grep -Eo "[01]{8}" a.txt | perl -ne 'chomp; print pack("B8", $$_)' > a.bin
hexdump: a.bin

logisim-bin/sum.bin: logisim-bin/sum.hex hex2bin.py
	python3 hex2bin.py logisim-bin/sum.hex logisim-bin/sum.bin

comp: hexdump sEMU.c
	gcc sEMU.c -g

comp_minirv: minirvEMU.c inst.c logisim-bin/sum.bin
	gcc minirvEMU.c inst.c -g

exe: a.out a.bin
	./a.out a.bin 10

.PHONY: clean
clean:
	rm -rf ./a.out a.bin
