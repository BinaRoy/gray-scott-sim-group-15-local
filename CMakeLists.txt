cmake_minimum_required(VERSION 3.10)
project(GrayScottSimulation)

set (CMAKE_CXX_STANDARD 14)

add_executable(GrayScottSimulation gs.cpp)
add_executable(GrayScottSimulationTests test_gs.cpp)
