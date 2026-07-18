VERILATOR = verilator

VERILATOR_FLAGS += --cc --exe
VERILATOR_FLAGS += --build
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += -j 0
VERILATOR_FLAGS += -Wall
VERILATOR_FLAGS += -CFLAGS -ggdb -LDFLAGS -ggdb

VERILATOR_INPUT = vsrc/switch.sv csrc/sim_main.cpp

default: run

run:
	@echo "-- VERILATE --------------"
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INPUT)	
	@echo "-- RUN -------------------"
	@rm -rf logs
	@mkdir -p logs
	obj_dir/Vswitch +trace

show-wave: run
	gtkwave logs/waveform.vcd	

clean:
	-rm -rf ./obj_dir ./logs
