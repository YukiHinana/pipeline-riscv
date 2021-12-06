# Verilated -*- CMake -*-
# DESCRIPTION: Verilator output: CMake include script with class lists
#
# This CMake script lists generated Verilated files, for including in higher level CMake scripts.
# This file is meant to be consumed by the verilate() function,
# which becomes available after executing `find_package(verilator).

### Constants...
set(PERL "perl" CACHE FILEPATH "Perl executable (from $PERL)")
set(VERILATOR_ROOT "/usr/share/verilator" CACHE PATH "Path to Verilator kit (from $VERILATOR_ROOT)")

### Compiler flags...
# User CFLAGS (from -CFLAGS on Verilator command line)
set(Vsystem_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(Vsystem_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(Vsystem_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(Vsystem_COVERAGE 0)
# Threaded output mode?  0/1/N threads (from --threads)
set(Vsystem_THREADS 0)
# VCD Tracing output mode?  0/1 (from --trace)
set(Vsystem_TRACE_VCD 1)
# FST Tracing output mode? 0/1 (from --fst-trace)
set(Vsystem_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(Vsystem_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "${VERILATOR_ROOT}/include/verilated_vcd_c.cpp")
# Generated module classes, non-fast-path, compile with low/medium optimization
set(Vsystem_CLASSES_SLOW )
# Generated module classes, fast-path, compile with highest optimization
set(Vsystem_CLASSES_FAST "/home/user/pipeline-riscv/verilator/cmake-build-debug/CMakeFiles/riscv_sim.dir/Vsystem.dir/Vsystem.cpp" "/home/user/pipeline-riscv/verilator/cmake-build-debug/CMakeFiles/riscv_sim.dir/Vsystem.dir/Vsystem_wishbone.cpp")
# Generated support classes, non-fast-path, compile with low/medium optimization
set(Vsystem_SUPPORT_SLOW "/home/user/pipeline-riscv/verilator/cmake-build-debug/CMakeFiles/riscv_sim.dir/Vsystem.dir/Vsystem__Syms.cpp" "/home/user/pipeline-riscv/verilator/cmake-build-debug/CMakeFiles/riscv_sim.dir/Vsystem.dir/Vsystem__Trace__Slow.cpp")
# Generated support classes, fast-path, compile with highest optimization
set(Vsystem_SUPPORT_FAST "/home/user/pipeline-riscv/verilator/cmake-build-debug/CMakeFiles/riscv_sim.dir/Vsystem.dir/Vsystem__Trace.cpp")
# All dependencies
set(Vsystem_DEPS "../gen_rtl/SinglePortRam.v" "../gen_rtl/YJTop.v" "../gen_rtl/ihex.sv" "../gen_rtl/uart_rx.sv" "../gen_rtl/uart_tx.sv" "../gen_rtl/wb_master_breakout.sv" "../gen_rtl/wbuart_with_buffer.sv" "../gen_rtl/wishbone.sv" "../rtl/../gen_rtl/wbuart_with_ihex.sv" "../rtl/../rtl/system.sv" "../rtl/dual_port_reg_file.sv" "../rtl/ex.sv" "../rtl/fetch.sv" "../rtl/id.sv" "../rtl/mem.sv" "../rtl/rr.sv" "../rtl/top.sv" "/usr/bin/verilator_bin")
# User .cpp files (from .cpp's on Verilator command line)
set(Vsystem_USER_CLASSES )
