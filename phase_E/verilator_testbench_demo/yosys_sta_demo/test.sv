module test(
  input clk, rst, in,
  output out
);

  wire t0, t1;
  Reg r1(clk, rst, in, t0, 1'b1);
  Reg r2(clk, rst, t0, t1, 1'b1);
  Reg r3(clk, rst, t1, out, 1'b1);

endmodule
