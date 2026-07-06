module Lemmings4(
  input clk, areset, bump_left, bump_right, ground, dig,
  output walk_left, walk_right, aaah, digging
);

  typedef enum logic [2:0] { 
    WALK_LEFT = 3'b000,
    WALK_RIGHT = 3'b001,
    FALL_FROM_LEFT = 3'b010,
    FALL_FROM_RIGHT = 3'b011,
    DIG_FROM_LEFT = 3'b100,
    DIG_FROM_RIGHT = 3'b101,
    SPLATTER = 3'b110
  } State;
  State state, next_state;

  reg [4:0] fall_cycles; // datapath
  wire fall_longer_than_19 = (fall_cycles > 5'd19); // status signal from datapath

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
        if (!ground)
          next_state = FALL_FROM_LEFT;
        else if (!fall_longer_than_19) 
          next_state = WALK_LEFT;
        else
          next_state = SPLATTER;
      end
      FALL_FROM_RIGHT: begin
        if (!ground)
          next_state = FALL_FROM_RIGHT;
        else if (!fall_longer_than_19)
          next_state = WALK_RIGHT;
        else
          next_state = SPLATTER;
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
      SPLATTER: 
        next_state = SPLATTER;
      default: 
        next_state = WALK_LEFT;
    endcase
  end

  // datapath
  assign walk_left =  (state == WALK_LEFT);
  assign walk_right = (state == WALK_RIGHT);
  assign aaah = ((state == FALL_FROM_LEFT) || (state == FALL_FROM_RIGHT));
  assign digging = ((state == DIG_FROM_LEFT) || (state == DIG_FROM_RIGHT));

  always_ff @(posedge clk, posedge areset)
    if (areset)
      fall_cycles <= 5'd0;
    else if (state == FALL_FROM_LEFT || state == FALL_FROM_RIGHT)
      if (fall_cycles <= 5'd19)
        fall_cycles <= fall_cycles + 5'd1;
      else
        fall_cycles <= fall_cycles;
    else
      fall_cycles <= 5'd0;

endmodule
