module Edge_capture_register(
  output reg [31:0] out,
  input [31:0] in, 
  input clk, reset
);
  reg [31:0] tmp;
  always @(posedge clk) begin
    tmp <= in;
    if (reset) 
      out <= 32'b0;
    else begin
      for (int i = 0; i < 32; i++) begin
        if (tmp[i] == 1'b1 && in[i] == 1'b0)
          out[i] <= 1'b1;
      end
    end
  end
endmodule
