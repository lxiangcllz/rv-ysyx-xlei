all:
	as max.s -o max.o
	ld max.o -o max
	./max
	echo $?

read_elf:
	readelf -a max.o > obj.elf
	readelf -a max > exe.elf

obj_dump:
	objdump -d max.o > obj.dump
	objdump -d max > exe.dump

clean:
	rm -rf max.o max *.elf *.dump
