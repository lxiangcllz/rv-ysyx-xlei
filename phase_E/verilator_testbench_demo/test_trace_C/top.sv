module top(
  input clk, reset_l,
  input [1:0] in_small,
  input [39:0] in_quad,
  input [69:0] in_wide,
  output [1:0] out_small,
  output [39:0] out_quad,
  output [69:0] out_wide
);

  assign out_small = ~reset_l ? '0 : (in_small + 2'b1);
  assign out_quad = ~reset_l ? '0 : (in_quad + 40'b1);
  assign out_wide = ~reset_l ? '0 : (in_wide + 70'b1);

  sub sub(.clk(clk), .reset_l(reset_l));

  initial begin
    if ($test$plusargs("trace") != 0) begin
      $display("[%0t] Tracing to logs/vlt_dump.vcd...\n", $time);
      $dumpfile("logs/vlt_dump.vcd");
      $dumpvars();
    end
    $display("[%0t] Model running...\n", $time);
  end
endmodule
