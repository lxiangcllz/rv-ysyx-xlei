module Lemmings3(
  input clk, areset, bump_left, bump_right, ground, dig,
  output walk_left, walk_right, aaah, digging
);

  typedef enum logic [2:0] { 
    WALK_LEFT = 3'b000,
    WALK_RIGHT = 3'b001,
    FALL_FROM_LEFT = 3'b010,
    FALL_FROM_RIGHT = 3'b011,
    DIG_FROM_LEFT = 3'b100,
    DIG_FROM_RIGHT = 3'b101
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
        else if (dig)
          next_state = DIG_FROM_LEFT;
        else if (bump_left)
          next_state = WALK_RIGHT;
        else
          next_state = WALK_LEFT;
      end
      WALK_RIGHT: begin
        if (!ground)
          next_state = FALL_FROM_RIGHT;
        else if (dig)
          next_state = DIG_FROM_RIGHT;
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
      DIG_FROM_LEFT: begin
        if (!ground)
          next_state = FALL_FROM_LEFT;
        else 
          next_state = DIG_FROM_LEFT;
      end
      DIG_FROM_RIGHT: begin
        if (!ground)
          next_state = FALL_FROM_RIGHT;
        else 
          next_state = DIG_FROM_RIGHT;
      end
      default: 
        next_state = WALK_LEFT;
    endcase
  end

  assign walk_left = state == WALK_LEFT;
  assign walk_right = state == WALK_RIGHT;
  assign aaah = (state == FALL_FROM_LEFT) || (state == FALL_FROM_RIGHT);
  assign digging = (state == DIG_FROM_LEFT) || (state == DIG_FROM_RIGHT);

endmodule
