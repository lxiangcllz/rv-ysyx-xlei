/*  12-Hour clock:
*   hh[7:0]: hours 01-12(tens: hh[7:4], ones: hh[3:0])
*   mm[7:0]: minutes 00-59
*   ss[7:0]: seconds 00-59
*   mm/ss: 00->01->...->59->00
*   hh:    12->01->...->11->12(pm toggles when 11->12)
*   11:59:59 AM -> 12:00:00 PM
*/
module Countclock(input clk, reset, ena,
  output reg pm,
  output reg [7:0] hh, mm, ss
);

  wire ss_carry_out, mm_carry_out;
  BCDCounter seconds(clk, reset, ena, 1'b1, ss, ss_carry_out);
  BCDCounter #(.MAX_TENS(4'd5), .MAX_ONES(4'd9), .RESET_VAL(8'h00)) minutes(clk, reset, ena, ss_carry_out, mm, mm_carry_out);
  Hours hours(clk, reset, ena, mm_carry_out, hh, pm);
endmodule


module BCDCounter #(
  parameter MAX_TENS = 4'd5,
  parameter MAX_ONES = 4'd9,
  parameter RESET_VAL = 8'h00
  )(
  input clk, reset, en, carry_in,
  output reg [7:0] cnt,
  output reg carry_out
);
  
  wire [3:0] tens = cnt[7:4];
  wire [3:0] ones = cnt[3:0];
  wire tens_max = (tens == MAX_TENS);
  wire ones_max = (ones == MAX_ONES);
  wire max = tens_max && ones_max;
  assign carry_out = en && carry_in && max;

  always @(posedge clk) begin
    if (reset) begin
      cnt <= RESET_VAL;
    end
    else if (en && carry_in) begin
      if (max) begin
        cnt <= 8'h00;
      end
      else begin
        if (ones_max)
          cnt <= {tens + 4'h1, 4'h0};
        else
          cnt <= {tens, ones + 4'h1};
      end
    end
  end
endmodule


module Hours(input clk, reset, en, carry_in,
  output reg [7:0] hour, 
  output reg pm
);

  wire [3:0] tens = hour[7:4];
  wire [3:0] ones = hour[3:0];

  always @(posedge clk) begin
    if (reset) begin
      hour <= 8'h12;
      pm <= 1'b0;
    end
    else if (en && carry_in) begin
      if (hour == 8'h11) begin
        hour <= 8'h12;
        pm <= ~pm;
      end
      else if (hour == 8'h12)
        hour <= 8'h01;
      else begin
        if (ones == 4'h9)
          hour <= {tens + 4'h1, 4'h0};
        else
          hour <= {tens, ones + 4'h1};
      end
    end
  end
endmodule
