project(TaskC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_BUILD_TYPE "Debug")

cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(main main.cpp input.txt output.txt)

add_executable(gen gen.cpp)


