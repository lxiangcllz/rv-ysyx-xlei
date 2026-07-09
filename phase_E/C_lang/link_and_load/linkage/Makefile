CFLAGS = -Wall

all: main

obj: stack/stack.c stack/push.c stack/pop.c stack/is_empty.c
	gcc -c $^

libstk.a: obj
	ar rs libstk.a stack.o push.o pop.o is_empty.o

#main: main.c libstk.a
	#$(CC) main.c -L. -lstk -Istack -o main


dyn_obj: stack/stack.c stack/push.c stack/pop.c stack/is_empty.c
	gcc -c -g -fPIC $^

libstk.so: dyn_obj
	gcc -shared -o libstk.so stack.o push.o pop.o is_empty.o

main: main.c libstk.so
	#$(CC) main.c -L. -lstk -Istack -o main -Wl,-rpath,.
	$(CC) main.c -g -L. -lstk -Istack -o main -Wl,-rpath,`pwd`


exe.elf: main
	readelf -a $^ > $@

exe.disasm: main
	objdump -d $^ > $@

%.objelf: %.o
	readelf -a $^ > $@

clean:
	rm -f *.o main *.a *.so exe.elf exe.disasm *.objelf
