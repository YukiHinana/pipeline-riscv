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
set(Vtop_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(Vtop_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(Vtop_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(Vtop_COVERAGE 0)
# Threaded output mode?  0/1/N threads (from --threads)
set(Vtop_THREADS 0)
# VCD Tracing output mode?  0/1 (from --trace)
set(Vtop_TRACE_VCD 1)
# FST Tracing output mode? 0/1 (from --fst-trace)
set(Vtop_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(Vtop_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "${VERILATOR_ROOT}/include/verilated_vcd_c.cpp")
# Generated module classes, non-fast-path, compile with low/medium optimization
set(Vtop_CLASSES_SLOW )
# Generated module classes, fast-path, compile with highest optimization
set(Vtop_CLASSES_FAST "/home/user/pipeline-riscv/verilator/cmake-build-debug/CMakeFiles/riscv_sim.dir/Vtop.dir/Vtop.cpp")
# Generated support classes, non-fast-path, compile with low/medium optimization
set(Vtop_SUPPORT_SLOW "/home/user/pipeline-riscv/verilator/cmake-build-debug/CMakeFiles/riscv_sim.dir/Vtop.dir/Vtop__Syms.cpp" "/home/user/pipeline-riscv/verilator/cmake-build-debug/CMakeFiles/riscv_sim.dir/Vtop.dir/Vtop__Trace__Slow.cpp")
# Generated support classes, fast-path, compile with highest optimization
set(Vtop_SUPPORT_FAST "/home/user/pipeline-riscv/verilator/cmake-build-debug/CMakeFiles/riscv_sim.dir/Vtop.dir/Vtop__Trace.cpp")
# All dependencies
set(Vtop_DEPS "../rtl/../rtl/top.sv" "../rtl/dual_port_reg_file.sv" "../rtl/ex.sv" "../rtl/fetch.sv" "../rtl/id.sv" "../rtl/mem.sv" "../rtl/memdev.sv" "../rtl/rr.sv" "/usr/bin/verilator_bin")
# User .cpp files (from .cpp's on Verilator command line)
set(Vtop_USER_CLASSES )
