MODULE = Serial_receiver_parity

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj_dir
SIM = $(OBJ_DIR)/V$(MODULE)
VCD = $(BUILD_DIR)/waveform.vcd
STAMP = $(BUILD_DIR)/.stamp.verilate

COMMON_DIR = $(abspath ../common)
VCD_ABS = $(abspath $(VCD))
VCD_HEADER = $(OBJ_DIR)/vcd_path.h

VERILATOR = verilator
VERILATOR_FLAGS = --cc --exe
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += --x-assign unique --x-initial unique
VERILATOR_FLAGS += -Wall
VERILATOR_FLAGS += -CFLAGS -ggdb -LDFLAGS -ggdb
VERILATOR_FLAGS += -CFLAGS -DTOP_NAME="\"V$(MODULE)\""
VERILATOR_FLAGS += -CFLAGS -I$(COMMON_DIR)
VERILATOR_FLAGS += -CFLAGS -I$(abspath $(OBJ_DIR))

# Disable -Os for GDB (Verilator defaults to OPT_FAST=-Os)
DEBUG_MAKE_FLAGS = OPT_FAST=-O0 OPT_GLOBAL=-O0


#SIMULATE_FLAGS = +verilator+rand+reset+2
SIMULATE_FLAGS = 

VSRCS = $(shell find $(abspath ./vsrc) -name "*.sv" -or -name ".v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.cpp" -or -name "*.cc" -or -name "*.c")
INPUT_FILES = $(VSRCS) $(CSRCS)

.PHONY:sim verilate compile waves lint clean debug gdb
sim: $(VCD)

compile: $(SIM)

# Rebuild with -O0 so GDB can print local variables (e.g. curtime)
debug:
	@$(MAKE) clean
	@$(MAKE) $(STAMP)
	@$(MAKE) $(SIM) $(DEBUG_MAKE_FLAGS)

# GDB with preloaded display script (see gdb/fsm.gdb)
gdb: $(SIM)
	@test -f $(SIM) || (echo "Run 'make debug' first for -O0 build." && exit 1)
	cgdb -x gdb/fsm.gdb --args $(abspath $(SIM))

waves: $(VCD)
	gtkwave $^

$(VCD): $(SIM)
	@echo
	@echo "### SIMULATING ###"
	@cd $(BUILD_DIR) && $(abspath $(SIM)) $(SIMULATE_FLAGS)

$(SIM): $(STAMP)
	@echo
	@echo "### BUILDING SIM ###"
	$(MAKE) -C $(OBJ_DIR) -f V$(MODULE).mk V$(MODULE)

$(STAMP): $(INPUT_FILES) $(VCD_HEADER)
	@mkdir -p $(OBJ_DIR)
	@echo
	@echo "### VERILATING ###"
	$(VERILATOR) $(VERILATOR_FLAGS) $(INPUT_FILES) --Mdir $(OBJ_DIR)
	@touch $(STAMP)

$(VCD_HEADER):
	@mkdir -p $(OBJ_DIR)
	@printf '#pragma once\n#define VCD_ABS_PATH "%s"\n' '$(VCD_ABS)' > $@

lint: $(VSRCS)
	verilator --lint-only $^

clean:
	rm -rf $(BUILD_DIR)
