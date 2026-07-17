ifneq ($(words $(CURDIR)),1)
	$(error Unsupported: build in directories containing spaces)
endif

ifeq ($(VERILATOR_ROOT),)
	VERILATOR = verilator
	VERILATOR_COVERAGE = verilator_coverage
else
	export VERILATOR_ROOT
	VERILATOR = $(VERILATOR_ROOT)/bin/verilator
	VERILATOR_COVERAGE = $(VERILATOR_ROOT)/bin/verilator_coverage
endif

VERILATOR_FLAGS += -cc --exe
VERILATOR_FLAGS += -x-assign fast
VERILATOR_FLAGS += -Wall
VERILATOR_FLAGS += --trace-vcd # equal to --trace
VERILATOR_FLAGS += --assert
VERILATOR_FLAGS += --coverage
#VERILATOR_FLAGS += --gdbbt

VERILATOR_INPUT = -f input.vc top.sv sim_main.cpp

default: run

run:
	@echo "-- VERILATE --------------"
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INPUT)
	@echo "-- BUILD -----------------"
	# 1, Pass --build to Verilator by editing VERILATOR_FLAGS above.
	# 2, Or, run the make rules Verilator does: $(MAKE) -C obj_dir -f Vtop.mk -j
	# 3, Or, call a submakefile where we can override the rules ourselves:
	$(MAKE) -C obj_dir -f ../Makefile_obj -j

	@echo "-- RUN -------------------"
	@rm -rf logs
	@mkdir -p logs
	obj_dir/Vtop +trace

	@echo "-- COVERAGE --------------"
	@rm -rf logs/annotated
	$(VERILATOR_COVERAGE) --annotate logs/annotated logs/coverage.dat

	@echo "-- DONE ------------------"
	@echo "To see waveforms, open vlt_dump.vcd in a waveform viewer"

show-wave: run
	@echo "-- WAVEFORM --------------"
	gtkwave logs/vlt_dump.vcd

show-config:
	$(VERILATOR) -V

maintainer-copy::
clean mostlyclean distclean maintainer-clean::
	-rm -rf obj_dir logs *.log *.dmp *.vpd coverage.dat core

