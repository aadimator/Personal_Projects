cmake_minimum_required(VERSION 3.3)
project(BarChart_P_2_6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BarChart.cpp BarChart.h)
add_executable(BarChart_P_2_6 ${SOURCE_FILES})