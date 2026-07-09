module Sequence_recognition(
  input clk, reset, in,
  output disc, flag, err
);

  typedef enum logic [3:0] { S_idle = 4'd0, S0 = 4'd1, S1 = 4'd2, S2 = 4'd3,
                             S3 = 4'd4, S4 = 4'd5, S5 = 4'd6, S6 = 4'd7,
                             S_disc = 4'd8, S_flag = 4'd9, S_err = 4'd10 } State;
  State state, next_state;

  always @(posedge clk)
    if (reset)
      state <= S0;
    else
      state <= next_state;

  always @(*) begin
    next_state = S0;
    case (state)
      S_idle: next_state = in ? S_idle : S0;
      S0: next_state = in ? S1 : S0;
      S1: next_state = in ? S2 : S0;
      S2: next_state = in ? S3 : S0;
      S3: next_state = in ? S4 : S0;
      S4: next_state = in ? S5 : S0;
      S5: next_state = in ? S6 : S_disc;
      S6: next_state = in ? S_err : S_flag;
      S_disc: next_state = in ? S1 : S0;
      S_flag: next_state = in ? S1 : S0;
      S_err: next_state = in ? S_err : S0;
    endcase
  end
  assign disc = (state == S_disc);
  assign flag = (state == S_flag);
  assign err = (state == S_err);

endmodule
