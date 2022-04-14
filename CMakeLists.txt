cmake_minimum_required(VERSION 3.21)
project(EX1)

set(CMAKE_CXX_STANDARD 11)

add_executable(EX1 main.cpp ExecuteProgram.cpp ExecuteProgram.h cmake-build-debug/SARS_CoV_2.cpp cmake-build-debug/SARS_CoV_2.h cmake-build-debug/Alpha.cpp cmake-build-debug/Alpha.h cmake-build-debug/Delta.cpp cmake-build-debug/Delta.h cmake-build-debug/Omicron.cpp cmake-build-debug/Omicron.h)
