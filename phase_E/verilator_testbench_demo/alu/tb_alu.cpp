#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Valu.h"
#include "Valu___024unit.h"

#define MAX_SIM_TIME 300
#define VERIF_START_TIME 7

void dut_reset(Valu *dut, const uint64_t &sim_time) {
	dut->rst = 0;
	if (sim_time >= 3 && sim_time < 6) {
		dut->rst = 1;
		dut->a_in = 0;
		dut->b_in = 0;
		dut->op_in = 0;
		dut->in_valid = 0;
	}
}

void set_rnd_out_valid(Valu *dut, const uint64_t &sim_time) {
	if (sim_time >= VERIF_START_TIME) {
		dut->in_valid = rand() & 1;
	}
}

void check_out_valid(Valu *dut, const uint64_t &sim_time) {
	static unsigned char in_valid = 0;
	static unsigned char in_valid_d = 0;
	static unsigned char out_valid_exp = 0;

	if (sim_time >= VERIF_START_TIME) {
		out_valid_exp = in_valid_d;
		in_valid_d = in_valid;
		in_valid = dut->in_valid;
		if (out_valid_exp != dut->out_valid) {
			std::cout << "ERROR: out_valid mismatch, "
					<< "exp: " << (int)(out_valid_exp)
					<< " recv: " << (int)(dut->out_valid)
					<< " simtime: " << sim_time << std::endl;
		}
	}
}

int main(int argc, char** argv, char** env) {
	srand(time(NULL));
	const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
	contextp->commandArgs(argc, argv);
	contextp->traceEverOn(true);
	const std::unique_ptr<Valu> dut{new Valu{contextp.get()}};

	const std::unique_ptr<VerilatedVcdC> m_trace{new VerilatedVcdC};
	dut->trace(m_trace.get(), 5);
	m_trace->open("waveform.vcd");

	uint64_t posedge_cnt = 0;
	uint64_t curtime = contextp->time();
	while (curtime < MAX_SIM_TIME) {
		dut_reset(dut.get(), curtime);

		dut->clk ^= 1;
		dut->eval();

		if (dut->clk == 1) {
			dut->in_valid = 0;
			posedge_cnt ++;
			//set_rnd_out_valid(dut.get(), curtime);
			switch (posedge_cnt) {
				case 10:
					dut->in_valid = 1;
					dut->a_in = 5;
					dut->b_in = 3;
					dut->op_in = Valu___024unit::operation_t::add;
					break;
				case 12:
					if (dut->out != 8) 
						std::cout << "Addition failed @ " << curtime << std::endl;
					break;
				case 20:
					dut->in_valid = 1;
					dut->a_in = 5;
					dut->b_in = 3;
					dut->op_in = Valu___024unit::operation_t::sub;
					break;
				case 22:
					if (dut->out != 2) 
						std::cout << "Subtraction failed @ " << curtime << std::endl;
					break;
			}
			check_out_valid(dut.get(), curtime);
		}
		m_trace->dump(curtime);
		contextp->timeInc(1);
		curtime = contextp->time();
	}

	m_trace->close();
	return 0;
}
