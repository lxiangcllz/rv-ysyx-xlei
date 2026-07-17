module sub(
  input clk, reset_l
);

  reg [31:0] count_c;
  always_ff @(posedge clk) begin
    if (!reset_l)
      count_c <= 32'b0;
    else begin
      count_c <= count_c + 1;
      if (count_c >= 3) begin
        $write("*-* All Finished *-*\n");
        $finish;
      end
    end
  end

  always_ff @(posedge clk) begin
    AssertionExample : assert (!reset_l || count_c < 100);
  end

  cover property (@(posedge clk) count_c == 3);

endmodule
