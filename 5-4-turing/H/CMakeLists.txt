project(TaskA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++11")
set(CMAKE_BUILD_TYPE "Debug")

cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(gen gen.cpp)

