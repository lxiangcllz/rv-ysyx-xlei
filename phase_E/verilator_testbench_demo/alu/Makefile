MODULE = alu

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj_dir
SIM = $(OBJ_DIR)/V$(MODULE)
VCD = $(BUILD_DIR)/waveform.vcd
STAMP = $(BUILD_DIR)/.stamp.verilate

VERILATOR = verilator
VERILATOR_FLAGS = --cc --exe
VERILATOR_FLAGS += --trace
VERILATOR_FLAGS += --x-assign unique --x-initial unique
VERILATOR_FLAGS += -Wall
VERILATOR_FLAGS += -CFLAGS -ggdb -LDFLAGS -ggdb

VSRCS = $(MODULE).sv
CSRCS = tb_$(MODULE).cpp
INPUT_FILES = $(VSRCS) $(CSRCS)

.PHONY:sim verilate compile waves lint clean
sim: $(VCD)

compile: $(SIM)

waves: $(VCD)
	gtkwave $^

$(VCD): $(SIM)
	@echo
	@echo "### SIMULATING ###"
	@cd $(BUILD_DIR) && $(abspath $(SIM)) +verilator+rand+reset+2

$(SIM): $(STAMP)
	@echo
	@echo "### BUILDING SIM ###"
	make -C $(OBJ_DIR) -f V$(MODULE).mk V$(MODULE)

$(STAMP): $(INPUT_FILES)
	@mkdir -p $(OBJ_DIR)
	@echo
	@echo "### VERILATING ###"
	$(VERILATOR) $(VERILATOR_FLAGS) --Mdir $(OBJ_DIR) $(INPUT_FILES)
	@touch $(STAMP)

lint: $(VSRCS)
	verilator --lint-only $^

clean:
	rm -rf $(BUILD_DIR)
