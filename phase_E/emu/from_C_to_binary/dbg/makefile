#CFLAGS = -DNDEBUG -Wall -g
CFLAGS = -Wall -g

all: main

main: main.cc
	$(CC) $(CFLAGS) -o $@ $^

run: ./main
	./$^

.PHONY: clean
clean:
	-rm -f ./main
