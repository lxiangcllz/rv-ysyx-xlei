module Serial_receiver(
  input  clk,
  input  in,
  input  reset,   // synchronous reset
  output done,
  output [7:0] out_byte
);

  typedef enum logic [1:0] {
    S_idle = 2'd0, S_recv = 2'd1,
    S_stop = 2'd2, S_err = 2'd3
  } State;

  State state, next_state;
  reg [7:0] data;
  reg load_bit, clr_cnt, done_r;
  reg [3:0] bit_cnt;

  always_ff @(posedge clk) begin
    if (reset)
      state <= S_idle;
    else
      state <= next_state;
  end

  always_comb begin
    load_bit = 1'b0; clr_cnt = 1'b0; done_r = 1'b0;
    next_state = S_idle;
    case (state)
      S_idle: begin
        clr_cnt = 1'b1;
        if (in) 
          next_state = S_idle;
        else
          next_state = S_recv;
      end
      S_recv: begin
        if (bit_cnt != 8) begin
          load_bit = 1'b1;
          next_state = S_recv;
        end
        else if (in)
          next_state = S_stop;
        else
          next_state = S_err;
      end
      S_stop: begin 
        done_r = 1'b1;
        clr_cnt = 1'b1;
        next_state = in ? S_idle : S_recv;
      end
      S_err: next_state = in ? S_idle : S_err;
    endcase
  end
  
  always_ff @(posedge clk) begin
    if (load_bit) begin
      data <= {in, data[7:1]};
      bit_cnt <= bit_cnt + 3'b1;
    end
    if (clr_cnt)
      bit_cnt <= 4'd0;
  end

  assign done = done_r;
  assign out_byte = done ? data : 8'd0;

endmodule
