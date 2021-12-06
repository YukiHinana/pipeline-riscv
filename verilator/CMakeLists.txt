cmake_minimum_required(VERSION 3.20)
project(verilator)

set(CMAKE_CXX_STANDARD 14)
find_package(verilator REQUIRED)
include_directories(src)
add_executable(riscv_sim src/main.cpp src/testbench.h)



verilate(riscv_sim SOURCES ../rtl/system.sv ../gen_rtl/wbuart_with_ihex.sv  INCLUDE_DIRS ../rtl ../gen_rtl TRACE VERILATOR_ARGS -Wno-width)
