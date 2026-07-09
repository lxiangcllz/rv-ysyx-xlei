module Serial_receiver_parity(
  input clk, in, reset, 
  output [7:0] out_byte,
  output done
);

  typedef enum logic [3:0] { idle = 4'd0, start = 4'd1, trans0 = 4'd2, trans1 = 4'd3,
                             trans2 = 4'd4, trans3 = 4'd5, trans4 = 4'd6, trans5 = 4'd7,
                             trans6 = 4'd8, trans7 = 4'd9, stop = 4'd10, err = 4'd11, pari = 4'd12 
                             } State;
  State state, next_state;
  reg [7:0] data;
  reg odd, reset_p;
  reg done_reg;

  always @(*) begin
    case (state)
      idle:   next_state <= in ? idle : start;
      start:  next_state <= trans0;
      trans0: next_state <= trans1;
      trans1: next_state <= trans2;
      trans2: next_state <= trans3;
      trans3: next_state <= trans4;
      trans4: next_state <= trans5;
      trans5: next_state <= trans6;
      trans6: next_state <= trans7;
      trans7: next_state <= pari;
      pari:   next_state <= in ? idle : err;
      err:    next_state <= in ? idle : err;
    endcase
  end

  always @(posedge clk) begin
    if (reset)
      state <= idle;
    else
      state <= next_state;
  end

  // New: Add parity checking.
  always @(posedge clk) begin
    if (reset) begin
      data <= 8'd0;
      reset_p <= 1'b1;
      done_reg <= 1'b0;
    end
    else begin
      if (next_state == trans0 || 
          next_state == trans1 || 
          next_state == trans2 || 
          next_state == trans3 ||
          next_state == trans4 ||
          next_state == trans5 ||
          next_state == trans6 || 
          next_state == trans7
          ) begin
            data <= {in, data[7:1]};
      end
      else if (next_state == start) begin
        data <= 8'd0;
        reset_p <= 1'b0;
        done_reg <= 1'b0;
      end
      else if (next_state == idle) begin
        done_reg <= odd;
      end
      else if (next_state == pari) begin
        reset_p <= 1'b1;
      end
    end
  end

  assign done = done_reg;
  assign out_byte = done ? data : 8'd0;
  parity par_mod(clk, reset | reset_p, in, odd);

endmodule


module parity(
  input clk, reset, in,
  output reg odd
);
  always @(posedge clk)
    if (reset)
      odd <= 1'b0;
    else if (in)
      odd <= ~odd;
endmodule
