module Serial_receiver_parity(
  input  clk,
  input  in,
  input  reset,   // synchronous reset
  output done,
  output [7:0] out_byte
);

  typedef enum logic [2:0] {
    S_idle = 3'd0, S_recv = 3'd1, S_pari = 3'd2,
    S_stop = 3'd3, S_stop_err = 3'd4, S_err = 3'd5
  } State;

  State state, next_state;
  reg load_bit, parity_en;
  reg [7:0] data;
  reg parity_check;
  reg clr_cnt, done_r;
  reg [3:0] bit_cnt;

  always_ff @(posedge clk) begin
    if (reset)
      state <= S_idle;
    else
      state <= next_state;
  end

  always_comb begin
    load_bit = 1'b0; parity_en = 1'b0;
    clr_cnt = 1'b0; done_r = 1'b0;
    next_state = S_idle;
    case (state)
      S_idle: begin
        clr_cnt = 1'b1;
        next_state = in ? S_idle : S_recv;
      end
      S_recv: begin
        parity_en = 1'b1;
        if (bit_cnt != 8) begin
          load_bit = 1'b1;
          next_state = S_recv;
        end
        else begin
          next_state = S_pari;
        end
      end
      S_pari: begin
        parity_en = 1'b1;
        if (in)
          next_state = parity_check ? S_stop : S_stop_err;
        else
          next_state = S_err;
      end
      S_stop: begin
        done_r = 1'b1;
        clr_cnt = 1'b1;
        next_state = in ? S_idle : S_recv;
      end
      S_stop_err: begin
        clr_cnt = 1'b1;
        next_state = in ? S_idle : S_recv;
      end
      S_err:
        next_state = in ? S_idle : S_err;
      default:;
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

  parity inst(clk, reset | !parity_en, in, parity_check);

  assign done = done_r;
  assign out_byte = done ? data : 8'd0;
endmodule


/* verilator lint_off DECLFILENAME */
module parity(
  input clk, rst, in,
  output reg odd
);
  always_ff @(posedge clk)
    if (rst)
      odd <= 1'b0;
    else
      odd <= odd ^ in;
endmodule
