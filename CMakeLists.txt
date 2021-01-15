cmake_minimum_required(VERSION 3.1)# Mandatory
project(bear_robotics_atm)# Mandatory
set  (CMAKE_CXX_STANDARD 11)# Use c++11

# tell cmake where to look for *.hpp, *. h files
include_directories(include/)

# create library "libtools"
#add_library(tools src/tools.cpp)# creates libtools.a
add_library(bank src/bank.cpp)# creates libtools.a
add_library(cash_bin src/cash_bin.cpp)# creates libtools.a
add_library(atm src/atm.cpp)# creates libtools.a


# add executable main
add_executable(main src/main.cpp)# main.o

# tell the linker to bind these objects together

target_link_libraries(main atm bank cash_bin)# ./ main
