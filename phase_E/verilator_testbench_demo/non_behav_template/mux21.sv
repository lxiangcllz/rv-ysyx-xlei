module mux21(input a, b, s, output y);
  MuxKey #(2, 1, 1) i0(y, s, { 1'b0, a, 1'b1, b });
endmodule

module mux41(input [3:0] a, s, output y);
  MuxKeyWithDefault #(4, 2, 1) i0(y, s, 1'b0, { 2'b00, a[0], 2'b01, a[1], 2'b10, a[2], 2'b11, a[3] });
endmodule
