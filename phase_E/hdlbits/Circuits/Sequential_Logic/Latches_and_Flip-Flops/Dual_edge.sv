module Dual_edge(
  input clk, d,
  output reg q
);
  reg [1:0] state;
  always @(posedge clk)
    state[0] <= d;
  always @(negedge clk)
    state[1] <= d;
  assign q = clk ? state[0] : state[1];
endmodule
