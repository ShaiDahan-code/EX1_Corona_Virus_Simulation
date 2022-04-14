cmake_minimum_required(VERSION 3.21)
project(EX1)

set(CMAKE_CXX_STANDARD 11)

add_executable(EX1 main.cpp ExecuteProgram.cpp ExecuteProgram.h SARS_CoV_2.cpp SARS_CoV_2.h Alpha.cpp Alpha.h Delta.cpp Delta.h Omicron.cpp Omicron.h)
