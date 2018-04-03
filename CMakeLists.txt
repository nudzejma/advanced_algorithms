cmake_minimum_required(VERSION 3.10)
project(advanced_algortihms)

set(CMAKE_CXX_STANDARD 11)

add_executable(advanced_algortihms main.cpp graph/Graph.cpp graph/Graph.h node/Node.cpp node/Node.h maxCycleDecomposition/maxCycledecomposition.h)