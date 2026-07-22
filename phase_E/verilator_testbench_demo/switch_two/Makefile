VERILATOR = verilator

VERILATOR_FLAGS += --cc --exe
VERILATOR_FLAGS += --build
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += -j 0
VERILATOR_FLAGS += -Wall
VERILATOR_FLAGS += -CFLAGS -ggdb -LDFLAGS -ggdb

VSRC = vsrc/switch.sv
CSRC = csrc/sim_main.cpp
VERILATOR_INPUT = $(VSRC) $(CSRC)

default: run

run: $(VERILATOR_INPUT)
	@echo "-- VERILATE --------------"
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INPUT)	
	@echo "-- RUN -------------------"
	@rm -rf logs
	@mkdir -p logs
	obj_dir/Vswitch +trace

show-wave: run
	gtkwave logs/waveform.vcd	

lint: $(VSRC)
	$(VERILATOR) --lint-only -Wall $(VSRC)

clean:
	-rm -rf ./obj_dir ./logs
