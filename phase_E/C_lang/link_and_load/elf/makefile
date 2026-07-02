default: run

max.o: max.s
	as $^ -o $@
asm: max.o

max: max.o
	ld $^ -o $@
link: max

run: max
	./$^
	echo $?

read_elf: obj.elf exe.elf
obj.elf: max.o
	readelf -a $^ > $@
exe.elf: max
	readelf -a $^ > $@

obj_dump: obj.dump exe.dump
obj.dump: max.o
	objdump -d $^ > $@
exe.dump: max
	objdump -d $^ > $@

.PHONY: clean
clean:
	rm -f max.o max *.elf *.dump
