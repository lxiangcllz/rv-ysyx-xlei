module fsm1(
  input clk, areset, in,
  output reg out
);
  
  // one-hot encoding
  typedef enum logic [3:0] { A = 4'b0001, B = 4'b0010, C = 4'b0100, D = 4'b1000 } State;
  // binary encoding
  //typedef enum logic [3:0] { A = 2'b00, B = 2'b01, C = 2'b10, D = 2'b11 } State;
  State state, next_state;
  always_ff @(posedge clk, posedge areset) begin
    if (areset)
      state <= A;
    else
      state <= next_state;
  end

  always_comb begin
    // next-state logic can be simplified by one-hot encoding:
    // next_state will be A
    next_state[0] = state[0]&(~in) | state[2]&(~in);
    // next_state will be B
    next_state[1] = state[0]&in | state[1]&in | state[3]&in;
    // next_state will be C
    next_state[2] = state[1]&(~in) | state[3]&(~in);
    // next_state will be D
    next_state[3] = state[2]&in;

    // next-state logic with binary encoding:
    //case (state)
    //  A: 
    //    if (in) next_state = B; else next_state = A;
    //  B:
    //    if (in) next_state = B; else next_state = C;
    //  C:
    //    if (in) next_state = D; else next_state = A;
    //  D:
    //    if (in) next_state = B; else next_state = C;
    //endcase
  end
  assign out = state[3];
  //assign out = (state == D);

endmodule
