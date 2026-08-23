module key_scan (
  input            clk,
  input            rst_n,
  input      [7:0] data,
  input            ready,
  output reg       nextdata_n,
  output reg [7:0] keycode,
  output     [7:0] ascii,
  output reg [7:0] press_cnt,
  output reg       disp_on
);
  typedef enum logic [1:0] {
    IDLE = 2'd0, HOLD = 2'd1, WAIT_BRK = 2'd2
  } State;

  State state;

  // 两位 BCD：00–99，超过回 00
  function automatic [7:0] bcd_inc(input [7:0] c);
    if (c[3:0] == 4'h9) begin
      if (c[7:4] == 4'h9)
        bcd_inc = 8'h00;
      else
        bcd_inc = {c[7:4] + 4'h1, 4'h0};
    end
    else
      bcd_inc = {c[7:4], c[3:0] + 4'h1};
  endfunction

  always @(posedge clk) begin
    if (!rst_n) begin
      state      <= IDLE;
      nextdata_n <= 1'b1;
      keycode    <= 8'h00;
      press_cnt  <= 8'h00;
      disp_on    <= 1'b0;
    end
    else if (ready && nextdata_n) begin
      nextdata_n <= 1'b0;  // 读完拉低一拍，通知 FIFO 出队
      case (state)
        IDLE: begin
          if (data == 8'hF0)
            state <= WAIT_BRK;
          else begin
            keycode   <= data;
            press_cnt <= bcd_inc(press_cnt);
            disp_on   <= 1'b1;
            state     <= HOLD;
          end
        end
        HOLD: begin
          if (data == 8'hF0)
            state <= WAIT_BRK;
          // 同一通码连发：保持显示，次数不加
        end
        default: begin  // WAIT_BRK
          disp_on <= 1'b0;
          state   <= IDLE;
        end
      endcase
    end
    else
      nextdata_n <= 1'b1;
  end

  scancode_rom u_rom (
    .scancode(keycode),
    .ascii(ascii)
  );

endmodule
