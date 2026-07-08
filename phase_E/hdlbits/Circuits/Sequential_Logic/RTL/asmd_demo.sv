module asmd_demo(input clk, reset_b, start, output reg [3:0] A, output reg E, F);
  
  wire clr_A_F, incr_A, set_E, clr_E, set_F;
  Controller G1(clk, reset_b, start, A[2], A[3], clr_A_F, incr_A, set_E, clr_E, set_F);
  Datapath G2(clk, clr_A_F, incr_A, set_E, clr_E, set_F, A, E, F);
  
endmodule

module Controller(input clk, reset_b, start, A2, A3, 
  output reg clr_A_F, incr_A, set_E, clr_E, set_F);

  //parameter S_idle = 2'b00, S1 = 2'b01, S2 = 2'b10;
  typedef enum logic [1:0] { S_idle = 2'b00, S1 = 2'b01, S2 = 2'b10 } State;

  //reg [1:0] state, next_state;
  State state, next_state;
  always_ff @(posedge clk, negedge reset_b) begin
    if (!reset_b)
      state <= S_idle;
    else
      state <= next_state;
  end

  //always @(state, start, A2, A3) begin
  always_comb begin
    next_state = S_idle;
    case (state)
      S_idle: if (start) next_state = S1; else next_state = S_idle;
      S1: if (!A2 || !A3) next_state = S1; else next_state = S2;
      S2: next_state = S_idle;
    endcase
  end
  
  //always @(state, start, A2) begin
  always_comb begin
    clr_A_F = 1'b0; incr_A = 1'b0; clr_E = 1'b0; set_E = 1'b0; set_F = 1'b0;
    case (state)
      S_idle:
        if (start)
          clr_A_F = 1'b1;
      S1:
        begin
          incr_A = 1'b1;
          if (!A2)
            clr_E = 1'b1;
          else
            set_E = 1'b1;
        end
      S2:
        set_F = 1'b1;
    endcase
  end
endmodule

module Datapath(input clk, clr_A_F, incr_A, set_E, clr_E, set_F, output reg [3:0] A, output reg E, F);
  always_ff @(posedge clk) begin
    if (clr_A_F) begin
      A <= 4'd0;
      F <= 1'b0;
    end
    if (incr_A)
      A <= A + 4'd1;
    if (set_E)
      E <= 1'b1;
    if (clr_E)
      E <= 1'b0;
    if (set_F)
      F <= 1'b1;
  end
endmodule
