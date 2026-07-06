module Detect_an_edge(
  output reg [7:0] pedge,
  input [7:0] in,
  input clk
);
  reg [7:0] tmp;
  always @(posedge clk) begin
    tmp <= in;
    for (int i = 0; i < 8; i++) begin
      pedge[i] <= tmp[i] == 0 && in[i] == 1'b1;
    end
  end
endmodule
