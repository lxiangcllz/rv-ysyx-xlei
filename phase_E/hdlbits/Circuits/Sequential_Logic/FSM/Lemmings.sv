/*  Lemmings:
*     state encoding: WALK_LEFT(1'b0), WALK_RIGHT(1'b1)
*     input: bump_left, bump_right
*     state transition diagram:
  *     state  bump_left bump_right | next_state
  *     ----------------------------|-----------
  *       0       0         0       |    0
  *       0       0         1       |    0
  *       0       1         0       |    1
  *       0       1         1       |    1
  *       1       0         0       |    1
  *       1       0         1       |    0
  *       1       1         0       |    1
  *       1       1         1       |    0
  *     ----------------------------------------
  *   ==> next_state = (!state)&&bump_left || state&&(!bump_right);
  *   assign walk_left = (state == WALKING_LEFT);
  *   assign walk_right = !walk_left;
  */
module Lemmings(
  input clk, areset, bump_left, bump_right,
  output walk_left, walk_right
);
  parameter WALK_LEFT = 1'b0, WALK_RIGHT = 1'b1;
  reg state, next_state, aaah_tmp;
  always_ff @(posedge clk, posedge areset) begin
    if (areset)
      state <= WALK_LEFT;
    else 
      state <= next_state;
  end

  // derived from truth table above:
  assign next_state = ~state&bump_left | state&(~bump_right);
  //// or, by inspection:
  //always_comb begin
  //  case (state)
  //    WALK_LEFT: next_state = bump_left ? WALK_RIGHT : WALK_LEFT;
  //    WALK_RIGHT: next_state = bump_right ? WALK_LEFT : WALK_RIGHT;
  //  endcase
  //end
  assign walk_left = (state == WALK_LEFT);
  assign walk_right = ~walk_left;

endmodule
