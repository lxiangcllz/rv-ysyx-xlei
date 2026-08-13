# GDB init script for VSerial_receiver_parity simulation debug
# Usage: gdb -x gdb/fsm.gdb --args build/obj_dir/VSerial_receiver_parity
#    or: make gdb

set print pretty on
set pagination off

# Re-run after editing this file: make gdb
# Signal names come from build/obj_dir/VSerial_receiver_parity___024root.h (re-verilate if RTL changes)

define fsm_state_name
  set $s = (int)$arg0
  if $s == 0
    printf "S_idle"
  else 
    if $s == 1
      printf "S_recv"
    else
      if $s == 2
        printf "S_pari"
      else
        if $s == 3
          printf "S_stop"
        else
          if $s == 4
            printf "S_stop_err"
          else
            if $s == 5
              printf "S_err"
            else
              printf "unknown(%d)", $s
            end
          end
        end
      end
    end
  end
end
document fsm_state_name
Print Serial_receiver_parity state enum name for numeric code.
Usage: fsm_state_name 2
end

define fsm-setup
  set $root = dut->rootp
  printf "fsm-setup: $root = dut->rootp\n"
end
document fsm-setup
Bind convenience variable $root to Verilated design internals.
Run once after dut is created (e.g. at start of main loop).
end

define fsm-info
  if $root == 0
    printf "Run fsm-setup first (after dut is initialized).\n"
  else
    printf "time=%lu posedge inputs: clk=%d in=%d reset=%d\n", \
      (unsigned long)contextp->time(), (int)dut->clk, (int)dut->in, (int)dut->reset
    printf "outputs: done=%d out_byte=0x%02x (%d)\n", \
      (int)dut->done, (unsigned int)dut->out_byte, (int)dut->out_byte
    printf "state="
    fsm_state_name $root->Serial_receiver_parity__DOT__state
    printf "  next="
    fsm_state_name $root->Serial_receiver_parity__DOT__next_state
    printf "\n"
    printf "datapath: bit_cnt=%u data=0x%02x load_bit=%d clr_cnt=%d done_r=%d\n", \
      (unsigned int)$root->Serial_receiver_parity__DOT__bit_cnt, \
      (unsigned int)$root->Serial_receiver_parity__DOT__data, \
      (int)$root->Serial_receiver_parity__DOT__load_bit, \
      (int)$root->Serial_receiver_parity__DOT__clr_cnt, \
      (int)$root->Serial_receiver_parity__DOT__done_r
  end
end
document fsm-info
Pretty-print Serial_receiver_parity IO and internal signals once.
end

define fsm-display-on
  fsm-setup
  display/d curtime
  display/d dut->clk
  display/d posedge_cnt
  display/d dut->reset
  display/d dut->in
  display/d $root->Serial_receiver_parity__DOT__state
  display/d $root->Serial_receiver_parity__DOT__next_state
  display/d $root->Serial_receiver_parity__DOT__bit_cnt
  display/x $root->Serial_receiver_parity__DOT__data
  display/d $root->Serial_receiver_parity__DOT__load_bit
  display/d $root->Serial_receiver_parity__DOT__parity_en
  display/d $root->Serial_receiver_parity__DOT__clr_cnt
  display/d $root->Serial_receiver_parity__DOT__parity_check
  display/d $root->Serial_receiver_parity__DOT__done_r
  display/x dut->out_byte
  printf "fsm-display-on: auto display enabled (see info display)\n"
end
document fsm-display-on
Register auto-display for Serial_receiver_parity ports and internals. Call after dut exists.
end

define fsm-display-off
  undisplay 1
  undisplay 2
  undisplay 3
  undisplay 4
  undisplay 5
  undisplay 6
  undisplay 7
  undisplay 8
  undisplay 9
  undisplay 10
  undisplay 11
  undisplay 12
  undisplay 13
  undisplay 14
  undisplay 15
  printf "fsm-display-off: removed displays 1-15\n"
end
document fsm-display-off
Remove default display slots registered by fsm-display-on.
end

# --- default session setup ---
# Stop after dut is ready, then enable auto-display
break tb_Serial_receiver_parity.cpp:23
run

fsm-display-on

printf "\n"
printf "VSerial_receiver_parity gdb ready (stopped at main loop entry).\n"
printf "  fsm-info          - print signals once\n"
printf "  fsm-display-on    - re-enable auto display\n"
printf "  fsm-display-off   - disable auto display\n"
printf "  info display      - list active display slots\n"
printf "  c / continue      - run simulation\n"
printf "  break tb_Serial_receiver_parity.cpp:31  - optional: stop each posedge after eval\n"
printf "\n"
