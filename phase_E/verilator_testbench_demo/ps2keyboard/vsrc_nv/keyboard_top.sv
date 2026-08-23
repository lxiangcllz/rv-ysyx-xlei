module keyboard_top (
  input        clk,
  input        rst_n,
  input        ps2_clk,
  input        ps2_data,
  output [6:0] hex [5:0],
  output       overflow,
  output [7:0] keycode,
  output [7:0] ascii,
  output [7:0] press_cnt,
  output       key_valid
);
  wire [7:0] kbd_data;
  wire       ready;
  wire       nextdata_n;

  ps2_keyboard u_kbd (
    .clk(clk),
    .clrn(rst_n),
    .ps2_clk(ps2_clk),
    .ps2_data(ps2_data),
    .nextdata_n(nextdata_n),
    .data(kbd_data),
    .ready(ready),
    .overflow(overflow)
  );

  key_scan u_scan (
    .clk(clk),
    .rst_n(rst_n),
    .data(kbd_data),
    .ready(ready),
    .nextdata_n(nextdata_n),
    .keycode(keycode),
    .ascii(ascii),
    .press_cnt(press_cnt),
    .disp_on(key_valid)
  );

  // hex[0] 对应 SEG0（最右，最低位）。从右到左：键码、ASCII、次数
  hex7seg u_hex0 (.b(keycode[3:0]),   .blank(~key_valid), .h(hex[0]));
  hex7seg u_hex1 (.b(keycode[7:4]),   .blank(~key_valid), .h(hex[1]));
  hex7seg u_hex2 (.b(ascii[3:0]),     .blank(~key_valid), .h(hex[2]));
  hex7seg u_hex3 (.b(ascii[7:4]),     .blank(~key_valid), .h(hex[3]));
  hex7seg u_hex4 (.b(press_cnt[3:0]), .blank(1'b0),       .h(hex[4]));
  hex7seg u_hex5 (.b(press_cnt[7:4]), .blank(1'b0),       .h(hex[5]));
endmodule
