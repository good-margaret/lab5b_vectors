cmake_minimum_required(VERSION 3.20)
project(git_progect C)

set(CMAKE_C_STANDARD 11)

add_executable(git_progect main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h libs/algorithms/array/array.c libs/algorithms/array/array.h libs/algorithms/algorithms.c libs/algorithms/algorithms.h)

add_subdirectory(libs)
target_link_libraries(git_progect data_structures)
target_link_libraries(git_progect algorithms)