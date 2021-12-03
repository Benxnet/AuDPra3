cmake_minimum_required(VERSION 3.20)
project(AuDPra3 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_EXE_LINKER_FLAGS "-wl,--stack,${100000000}")
add_executable(AuDPra3 main.c sort.c sort.h)
