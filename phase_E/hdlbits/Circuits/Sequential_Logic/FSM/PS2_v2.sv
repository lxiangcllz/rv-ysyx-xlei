module PS2_v2(
  input clk,
  input [7:0] in,
  input reset,
  output [23:0] out_bytes,
  output done
);

  logic load_byte1, load_byte2, load_byte3;
  Controller G1(clk, reset, in[3], load_byte1, load_byte2, load_byte3, done);
  Datapath G2(clk, load_byte1, load_byte2, load_byte3, done, in, out_bytes);

endmodule


module Controller(
  input clk, reset, in3,
  output logic load_byte1, load_byte2, load_byte3, done
);

  typedef enum logic [1:0] { S_idle = 2'b00, S1 = 2'b01, S2 = 2'b10 } State;
  State state, next_state;
  reg done_tmp;

  always @(posedge clk, posedge reset) begin
    if (reset)
      state <= S_idle;
    else
      state <= next_state;
  end

  always_comb begin
    next_state = S_idle;
    case (state)
      S_idle: if (in3) next_state = S1; else next_state = S_idle;
      S1:     next_state = S2;
      S2:     next_state = S_idle;
    endcase
  end

  always_comb begin
    load_byte1 = 1'b0; load_byte2 = 1'b0; load_byte3 = 1'b0;
    case (state)
      S_idle: if (in3) load_byte1 = 1'b1;
      S1:     load_byte2 = 1'b1;
      S2:     load_byte3 = 1'b1;
    endcase
  end

  always_ff @(posedge clk)
    if (state == S2)
      done_tmp <= 1'b1;
    else
      done_tmp <= 1'b0;

  assign done = done_tmp;

endmodule


module Datapath(
  input clk, 
  input load_byte1, load_byte2, load_byte3, done,
  input [7:0] in,
  output [23:0] out_bytes
);

  reg [7:0] byte1, byte2, byte3;

  always @(posedge clk) begin
    if (load_byte1) begin
      byte1 <= in;
    end
    if (load_byte2) begin
      byte2 <= byte1;
      byte1 <= in;
    end
    if (load_byte3) begin
      byte3 <= byte2;
      byte2 <= byte1;
      byte1 <= in;
    end
  end

  assign out_bytes = done ? { byte3, byte2, byte1 } : 24'd0;
  
endmodule
