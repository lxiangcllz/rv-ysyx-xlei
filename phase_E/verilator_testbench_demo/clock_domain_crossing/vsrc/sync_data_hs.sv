// Multi-bit CDC via 4-phase req/ack handshake.
// Do NOT put each data bit through its own 2FF: bits can skew and the
// destination would sample a value that was never sent.
// Only the 1-bit req/ack controls are synchronized. data_hold is kept
// stable in the source domain until the destination has captured it.
module sync_data_hs(
  input        clk_src, clk_dst, rst_n,
  input  [7:0] data_in,
  input        send,          // 1-cycle pulse in clk_src: push data_in
  output       busy,          // src cannot send until handshake finishes
  output [7:0] data_out,
  output       recv           // 1-cycle pulse in clk_dst: data_out is new
);

  typedef enum logic [1:0] {
    S_IDLE         = 2'd0,
    S_WAIT_ACK     = 2'd1,
    S_WAIT_ACK_CLR = 2'd2
  } src_state_e;

  typedef enum logic [1:0] {
    D_IDLE         = 2'd0,
    D_WAIT_REQ_CLR = 2'd1
  } dst_state_e;

  src_state_e src_state;
  dst_state_e dst_state;

  reg [7:0] data_hold;
  reg       req;
  reg [7:0] data_out_r;
  reg       ack;
  reg       recv_r;

  // req: src -> dst  (2FF)
  reg req_d1, req_sync;
  always_ff @(posedge clk_dst, negedge rst_n) begin
    if (!rst_n) begin
      req_d1 <= 1'b0; req_sync <= 1'b0;
    end
    else begin
      req_d1   <= req;
      req_sync <= req_d1;
    end
  end

  // ack: dst -> src  (2FF)
  reg ack_d1, ack_sync;
  always_ff @(posedge clk_src, negedge rst_n) begin
    if (!rst_n) begin
      ack_d1 <= 1'b0; ack_sync <= 1'b0;
    end
    else begin
      ack_d1   <= ack;
      ack_sync <= ack_d1;
    end
  end

  assign busy     = (src_state != S_IDLE);
  assign data_out = data_out_r;
  assign recv     = recv_r;

  // source: latch data, raise req, wait for ack high then low
  always_ff @(posedge clk_src, negedge rst_n) begin
    if (!rst_n) begin
      src_state <= S_IDLE;
      data_hold <= 8'd0;
      req       <= 1'b0;
    end
    else begin
      case (src_state)
        S_IDLE: begin
          if (send) begin
            data_hold <= data_in;
            req       <= 1'b1;
            src_state <= S_WAIT_ACK;
          end
        end
        S_WAIT_ACK: begin
          if (ack_sync) begin
            req       <= 1'b0;
            src_state <= S_WAIT_ACK_CLR;
          end
        end
        S_WAIT_ACK_CLR: begin
          if (!ack_sync)
            src_state <= S_IDLE;
        end
        default: src_state <= S_IDLE;
      endcase
    end
  end

  // destination: on req, sample the held bus, raise ack, wait for req low
  always_ff @(posedge clk_dst, negedge rst_n) begin
    if (!rst_n) begin
      dst_state  <= D_IDLE;
      data_out_r <= 8'd0;
      ack        <= 1'b0;
      recv_r     <= 1'b0;
    end
    else begin
      recv_r <= 1'b0;
      case (dst_state)
        D_IDLE: begin
          if (req_sync) begin
            data_out_r <= data_hold;
            ack        <= 1'b1;
            recv_r     <= 1'b1;
            dst_state  <= D_WAIT_REQ_CLR;
          end
        end
        D_WAIT_REQ_CLR: begin
          if (!req_sync) begin
            ack       <= 1'b0;
            dst_state <= D_IDLE;
          end
        end
        default: dst_state <= D_IDLE;
      endcase
    end
  end

endmodule
