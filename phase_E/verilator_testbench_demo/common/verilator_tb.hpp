#pragma once

#include <cstdlib>
#include <ctime>
#include <memory>
#include <verilated.h>
#include <verilated_vcd_c.h>


template <typename TDut>
class VerilatorTb {
public:
  VerilatorTb(int argc, char** argv,
              const char* vcd_path = "waveform.vcd",
              int trace_depth = 5) 
    : context_{new VerilatedContext}
    , dut_{new TDut{context_.get()}}
    , trace_{new VerilatedVcdC} 
  {
    srand(time(nullptr));
    context_->commandArgs(argc, argv);
    context_->traceEverOn(true);
    dut_->trace(trace_.get(), trace_depth);
    trace_->open(vcd_path);
  }

  ~VerilatorTb() {
    if (trace_)
      trace_->close();
  }

  VerilatorTb(const VerilatorTb&) = delete;
  VerilatorTb& operator=(const VerilatorTb&) = delete;

  VerilatedContext* context() const { return context_.get(); }
  TDut* dut() const { return dut_.get(); }
  VerilatedVcdC* trace() const { return trace_.get(); }

private:
  std::unique_ptr<VerilatedContext> context_;
  std::unique_ptr<TDut> dut_;
  std::unique_ptr<VerilatedVcdC> trace_;
};
