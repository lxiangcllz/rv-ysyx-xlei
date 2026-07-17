module switch(
  input a, b, 
  output f
);

  assign f = a ^ b;

  initial begin
    if ($test$plusargs("trace") != 0) begin
      $display("[%0t] Tracing to logs/waveform.vcd...", $time);
      $dumpfile("logs/waveform.vcd");
      $dumpvars();
    end
  end

endmodule
