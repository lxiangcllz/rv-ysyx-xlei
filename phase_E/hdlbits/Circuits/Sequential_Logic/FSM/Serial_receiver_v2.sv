module Serial_receiver(
  input clk, in, reset,
  output done
);
  typedef enum logic [1:0] { S_idle = 2'b00, S1 = 2'b01, S_err = 2'b11 } State;
  State state, next_state;
  reg [3:0] cnt;
  wire in0 = (in == 1'b0);
  wire in1 = (in == 1'b1);
  wire cnt_less_8 = (cnt < 4'd8);
  reg clr_cnt, incr_cnt, done_tmp;

  always_ff @(posedge clk)
    if (reset)
      state <= S_idle;
    else
      state <= next_state;

  always_comb begin
    next_state = S_idle; clr_cnt = 1'b0; incr_cnt = 1'b0;
    case (state)
      S_idle: begin
        clr_cnt = 1'b1;
        if (in0)
          next_state = S1;
        else
          next_state = S_idle;
      end
      S1: begin
        if (cnt_less_8) begin
          next_state = S1;
          incr_cnt = 1'b1;
        end
        else if (in1) begin
          next_state = S_idle;
        end
        else 
          next_state = S_err;
      end
      S_err: begin
        clr_cnt = 1'b1;
        if (in1)
          next_state = S_idle;
        else
          next_state = S_err;
      end
    endcase
  end

  always @(posedge clk)
    done_tmp <= (state == S1) && !cnt_less_8 && in1;
  assign done = done_tmp;


  always_ff @(posedge clk) begin
    if (reset) begin
      cnt <= 4'd0;
    end
    else begin
      if (incr_cnt)
        cnt <= cnt + 4'd1;
      else if (clr_cnt)
        cnt <= 4'd0;
    end
  end

endmodule
