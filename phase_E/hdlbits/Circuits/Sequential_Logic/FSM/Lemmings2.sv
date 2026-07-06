module Lemmings2(
  input clk, areset, bump_left, bump_right, ground,
  output walk_left, walk_right, aaah
);

  typedef enum logic [1:0] { 
    WALK_LEFT = 2'b00,
    WALK_RIGHT = 2'b01,
    FALL_FROM_LEFT = 2'b10,
    FALL_FROM_RIGHT = 2'b11
  } State;
  State state, next_state;

  always_ff @(posedge clk, posedge areset)
    if (areset)
      state <= WALK_LEFT;
    else
      state <= next_state;

  always_comb begin
    case (state)
      WALK_LEFT: begin
        if (!ground)
          next_state = FALL_FROM_LEFT;
        else if (bump_left)
          next_state = WALK_RIGHT;
        else
          next_state = WALK_LEFT;
      end
      WALK_RIGHT: begin
        if (!ground)
          next_state = FALL_FROM_RIGHT;
        else if (bump_right)
          next_state = WALK_LEFT;
        else
          next_state = WALK_RIGHT;
      end
      FALL_FROM_LEFT: begin
        if (ground)
          next_state = WALK_LEFT;
        else 
          next_state = FALL_FROM_LEFT;
      end
      FALL_FROM_RIGHT: begin
        if (ground)
          next_state = WALK_RIGHT;
        else 
          next_state = FALL_FROM_RIGHT;
      end
    endcase
  end

  assign walk_left = state == WALK_LEFT;
  assign walk_right = state == WALK_RIGHT;
  assign aaah = (state == FALL_FROM_LEFT) || (state == FALL_FROM_RIGHT);

endmodule
