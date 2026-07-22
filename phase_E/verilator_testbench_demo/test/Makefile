TEST_DIR      := /home/xl/mywork/digital_design/ysyx/rv-ysyx-xlei/phase_E/verilator_testbench_demo/test
REG_FILE      := /home/xl/mywork/digital_design/ysyx/rv-ysyx-xlei/phase_E/verilator_testbench_demo/non_behav_template/Reg.sv
RESULT_DIR    := $(TEST_DIR)/result
YOSYS_STA     := /home/xl/3rdparty/yosys-sta
CLK_FREQ_MHZ  ?= 500
CLK_PORT_NAME ?= clk
SDC_FILE      := $(YOSYS_STA)/scripts/default.sdc

RTL_FILES := $(TEST_DIR)/test.sv $(REG_FILE)

syn:
	make -C $(YOSYS_STA) syn \
		DESIGN=test \
		RTL_FILES="$(RTL_FILES)" \
		CLK_FREQ_MHZ=$(CLK_FREQ_MHZ) \
		O=$(RESULT_DIR)

sta: syn
	make -C $(YOSYS_STA) sta \
		DESIGN=test \
		SDC_FILE=$(SDC_FILE) \
		CLK_FREQ_MHZ=$(CLK_FREQ_MHZ) \
		CLK_PORT_NAME=$(CLK_PORT_NAME) \
		O=$(RESULT_DIR)


clean:
	rm -rf $(RESULT_DIR)
