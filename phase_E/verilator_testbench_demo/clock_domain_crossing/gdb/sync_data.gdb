# GDB init script for Vsync_data_hs simulation debug
# Usage: gdb -x gdb/sync_data.gdb --args build/obj_dir/Vsync_data_hs
#    or: make gdb

set print pretty on
set pagination off

# Re-run after editing this file: make gdb
# Signal names come from build/obj_dir/Vsync_data_hs___024root.h (re-verilate if RTL changes)

define src-state-name
  set $s = (int)$arg0
  if $s == 0
    printf "S_IDLE"
  else
    if $s == 1
      printf "S_WAIT_ACK"
    else
      if $s == 2
        printf "S_WAIT_ACK_CLR"
      else
        printf "unknown(%d)", $s
      end
    end
  end
end
document src-state-name
Print source-domain handshake state name.
Usage: src-state-name 1
end

define dst-state-name
  set $s = (int)$arg0
  if $s == 0
    printf "D_IDLE"
  else
    if $s == 1
      printf "D_WAIT_REQ_CLR"
    else
      printf "unknown(%d)", $s
    end
  end
end
document dst-state-name
Print destination-domain handshake state name.
Usage: dst-state-name 1
end

define sync-setup
  set $root = dut->rootp
  printf "sync-setup: $root = dut->rootp\n"
end
document sync-setup
Bind convenience variable $root to Verilated design internals.
Run once after dut is created (e.g. at start of main loop).
end

define sync-pipe
  if $root == 0
    printf "Run sync-setup first (after dut is initialized).\n"
  else
    printf "src: "
    src-state-name $root->sync_data_hs__DOT__src_state
    printf "  data_in=0x%02x send=%d busy=%d data_hold=0x%02x req=%d ack_sync=%d\n", \
      (unsigned int)dut->data_in, (int)dut->send, (int)dut->busy, \
      (unsigned int)$root->sync_data_hs__DOT__data_hold, \
      (int)$root->sync_data_hs__DOT__req, \
      (int)$root->sync_data_hs__DOT__ack_sync
    printf "req 2FF: req=%d -> [d1=%d] -> [req_sync=%d]\n", \
      (int)$root->sync_data_hs__DOT__req, \
      (int)$root->sync_data_hs__DOT__req_d1, \
      (int)$root->sync_data_hs__DOT__req_sync
    printf "ack 2FF: ack=%d -> [d1=%d] -> [ack_sync=%d]\n", \
      (int)$root->sync_data_hs__DOT__ack, \
      (int)$root->sync_data_hs__DOT__ack_d1, \
      (int)$root->sync_data_hs__DOT__ack_sync
    printf "dst: "
    dst-state-name $root->sync_data_hs__DOT__dst_state
    printf "  data_out=0x%02x recv=%d ack=%d req_sync=%d\n", \
      (unsigned int)dut->data_out, (int)dut->recv, \
      (int)$root->sync_data_hs__DOT__ack, \
      (int)$root->sync_data_hs__DOT__req_sync
  end
end
document sync-pipe
Print 4-phase handshake and data-hold path as a diagram.
end

define sync-info
  if $root == 0
    printf "Run sync-setup first (after dut is initialized).\n"
  else
    printf "time=%lu ns  rst_n=%d  clk_src=%d  clk_dst=%d  wr_idx=%d\n", \
      (unsigned long)curtime, (int)dut->rst_n, \
      (int)dut->clk_src, (int)dut->clk_dst, (int)wr_idx
    printf "src_state="
    src-state-name $root->sync_data_hs__DOT__src_state
    printf "  dst_state="
    dst-state-name $root->sync_data_hs__DOT__dst_state
    printf "\n"
    sync-pipe
  end
end
document sync-info
Pretty-print sync_data_hs IO, FSM, and 2FF controls once.
end

define sync-display-on
  sync-setup
  display/d curtime
  display/d dut->rst_n
  display/d dut->clk_src
  display/d dut->clk_dst
  display/d wr_idx
  display/x dut->data_in
  display/d dut->send
  display/d dut->busy
  display/x $root->sync_data_hs__DOT__data_hold
  display/d $root->sync_data_hs__DOT__src_state
  display/d $root->sync_data_hs__DOT__req
  display/d $root->sync_data_hs__DOT__req_sync
  display/d $root->sync_data_hs__DOT__dst_state
  display/d $root->sync_data_hs__DOT__ack
  display/d $root->sync_data_hs__DOT__ack_sync
  display/x dut->data_out
  display/d dut->recv
  printf "sync-display-on: auto display enabled (see info display)\n"
end
document sync-display-on
Register auto-display for handshake ports and internals. Call after dut exists.
end

define sync-display-off
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
  undisplay 16
  undisplay 17
  printf "sync-display-off: removed displays 1-17\n"
end
document sync-display-off
Remove default display slots registered by sync-display-on.
end

define sync-break-send
  break tb_sync_data_hs.cpp:56 if dut->send != 0
  printf "sync-break-send: stop when source issues send\n"
end
document sync-break-send
Break at the source print site when send is high.
end

define sync-break-recv
  break tb_sync_data_hs.cpp:60 if dut->recv != 0
  printf "sync-break-recv: stop when destination pulses recv\n"
end
document sync-break-recv
Break at the destination print site when recv is high.
end

# --- default session setup ---
break tb_sync_data_hs.cpp:23
run

sync-display-on

printf "\n"
printf "Vsync_data_hs gdb ready (stopped at main loop entry).\n"
printf "  sync-info         - print handshake/data signals once\n"
printf "  sync-pipe         - print 4-phase + data_hold path\n"
printf "  sync-display-on   - re-enable auto display\n"
printf "  sync-display-off  - disable auto display\n"
printf "  sync-break-send   - stop on source send\n"
printf "  sync-break-recv   - stop on destination recv\n"
printf "  info display      - list active display slots\n"
printf "  c / continue      - run simulation\n"
printf "  break tb_sync_data_hs.cpp:50  - optional: stop each eval\n"
printf "  break tb_sync_data_hs.cpp:37  - optional: stop each src posedge\n"
printf "  break tb_sync_data_hs.cpp:38  - optional: stop each dst posedge\n"
printf "\n"
