a.bin: a.txt
	grep -Eo "[01]{8}" a.txt | perl -ne 'chomp; print pack("B8", $$_)' > a.bin
hexdump: a.bin

logisim-bin/sum.bin: logisim-bin/sum.hex hex2bin.py
	python3 hex2bin.py logisim-bin/sum.hex logisim-bin/sum.bin

logisim-bin/vga.bin: logisim-bin/vga.hex hex2bin.py
	python3 hex2bin.py logisim-bin/vga.hex logisim-bin/vga.bin

AM_HOME ?= $(HOME)/mywork/digital_design/ysyx/ysyx-workbench/abstract-machine
AM_A    = $(AM_HOME)/am/build/am-native.a
# only these objects of AM are needed by minirvEMU
AM_OBJS = trm.o ioe.o mpe.o gpu.o input.o timer.o uart.o audio.o disk.o
AM_INC  = -I$(AM_HOME)/am/include -I$(AM_HOME)/klib/include
AM_CFLAGS = -fpie $(shell sdl2-config --cflags) $(AM_INC) -DARCH_H=\"arch/native.h\"
AM_LDFLAGS = -pie -ldl $(shell sdl2-config --libs) -g

comp: hexdump sEMU.c
	gcc sEMU.c -g

$(AM_HOME)/am/build/am-native.a:
	$(MAKE) -s -C $(AM_HOME)/am archive ARCH=native

AM_BUILD = build/am
AM_LINK  = $(addprefix $(AM_BUILD)/,$(AM_OBJS))

$(AM_BUILD)/%.o: $(AM_A)
	@mkdir -p $(AM_BUILD)
	cd $(AM_BUILD) && ar x $< $(notdir $@)

minirvEMU: minirvEMU.c inst.c am_host_stubs.c $(AM_LINK)
	g++ -o minirvEMU minirvEMU.c inst.c am_host_stubs.c $(AM_CFLAGS) $(AM_LINK) $(AM_LDFLAGS)

comp_minirv: minirvEMU logisim-bin/sum.bin

run_sum: minirvEMU logisim-bin/sum.bin
	./minirvEMU logisim-bin/sum.bin

run_vga: minirvEMU logisim-bin/vga.bin
	./minirvEMU logisim-bin/vga.bin

exe: a.out a.bin
	./a.out a.bin 10

.PHONY: clean run_sum run_vga comp_minirv
clean:
	rm -rf ./a.out ./minirvEMU a.bin build logisim-bin/sum.bin logisim-bin/vga.bin
