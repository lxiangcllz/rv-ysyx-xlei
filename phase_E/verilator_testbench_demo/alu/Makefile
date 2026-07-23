MODULE = alu

VERILATOR = verilator
VERILATOR_FLAGS = --cc --exe
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += --x-assign unique --x-initial unique
VERILATOR_FLAGS += -Wall
VERILATOR_FLAGS += -CFLAGS -ggdb -LDFLAGS -ggdb

VSRCS = $(MODULE).sv
CSRCS = tb_$(MODULE).cpp
INPUT_FILES = $(VSRCS) $(CSRCS)

.PHONY:sim
sim: waveform.vcd

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:build
build: obj_dir/Valu

.PHONY:waves
waves: waveform.vcd
	@echo
	@echo "### WAVES ###"
	gtkwave $^

waveform.vcd: ./obj_dir/V$(MODULE)
	@echo
	@echo "### SIMULATING ###"
	@$^ +verilator+rand+reset+2

./obj_dir/V$(MODULE): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: $(INPUT_FILES)
	@echo
	@echo "### VERILATING ###"
	$(VERILATOR) $(VERILATOR_FLAGS) $(INPUT_FILES)
	@touch .stamp.verilate

.PHONY:lint
lint: $(VSRCS)
	verilator --lint-only $^

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd
