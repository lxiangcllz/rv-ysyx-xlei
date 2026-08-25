MODULE = ps2_keyboard

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj_dir
SIM = $(OBJ_DIR)/V$(MODULE)
VCD = $(BUILD_DIR)/waveform.vcd
STAMP = $(BUILD_DIR)/.stamp.verilate

COMMON_DIR = $(abspath ../common)

VERILATOR = verilator
VERILATOR_FLAGS = --cc --exe
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += --top-module $(MODULE)
VERILATOR_FLAGS += --x-assign unique --x-initial unique
VERILATOR_FLAGS += -Wall
VERILATOR_FLAGS += -CFLAGS -ggdb -LDFLAGS -ggdb
VERILATOR_FLAGS += -CFLAGS -DTOP_NAME="\"V$(MODULE)\""
VERILATOR_FLAGS += -CFLAGS -I$(COMMON_DIR)
VERILATOR_FLAGS += -CFLAGS -I$(abspath $(OBJ_DIR))

VSRCS = $(shell find $(abspath ./vsrc) -name "*.sv" -or -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.cpp" -or -name "*.cc" -or -name "*.c")
INPUT_FILES = $(VSRCS) $(CSRCS)

.PHONY: sim verilate compile waves lint clean

sim: $(VCD)

compile: $(SIM)

waves: $(VCD)
	gtkwave $^

$(VCD): $(SIM)
	@echo
	@echo "### SIMULATING ###"
	@cd $(BUILD_DIR) && $(abspath $(SIM))

$(SIM): $(STAMP)
	@echo
	@echo "### BUILDING SIM ###"
	$(MAKE) -C $(OBJ_DIR) -f V$(MODULE).mk V$(MODULE)

$(STAMP): $(INPUT_FILES)
	@mkdir -p $(OBJ_DIR)
	@echo
	@echo "### VERILATING ###"
	$(VERILATOR) $(VERILATOR_FLAGS) $(INPUT_FILES) --Mdir $(OBJ_DIR)
	@touch $(STAMP)

lint: $(VSRCS)
	$(VERILATOR) --lint-only -Wall --top-module $(MODULE) $^

clean:
	rm -rf $(BUILD_DIR)
