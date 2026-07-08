module PS2(
  input clk,
  input [7:0] in,
  input reset,
  output [23:0] out_bytes,
  output done
);
  
  PS2_Controller G1(clk, in[3], reset, done);
  PS2_Datapath G2(clk, reset, done, in, out_bytes);

endmodule


module PS2_Controller(
  input clk,
  input in3,
  input reset,
  output reg done
);
  typedef enum logic [1:0] { S_idle = 2'b00, S1 = 2'b01, S2 = 2'b10, S3 = 2'b11 } State;
  State state, next_state;

  always_ff @(posedge clk)
    if (reset)
      state <= S_idle;
    else
      state <= next_state;

  always_comb begin
    case (state)
      S_idle: if (in3) next_state = S1; else next_state = S_idle;
      S1: next_state = S2;
      S2: next_state = S3;
      S3: if (in3) next_state = S1; else next_state = S_idle;
    endcase
  end

  assign done = state == S3;

endmodule


module PS2_Datapath(
  input clk, reset,
  input done,
  input [7:0] in,
  output [23:0] out_bytes
);

  reg [23:0] data;
  always_ff @(posedge clk) begin
    if (reset)
      data <= 24'd0;
    else begin
      data[23:16] <= data[15:8];
      data[15:8] <= data[7:0];
      data[7:0] <= in;
    end
  end
  assign out_bytes = done ? data : 24'd0;

endmodule
