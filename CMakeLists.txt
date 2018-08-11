cmake_minimum_required(VERSION 3.12.0)
project(CS50)

set(CMAKE_C_STANDARD 11)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_subdirectory(PSET1)
add_subdirectory(PSET2)
add_subdirectory(PSET3)
add_subdirectory(PSET4)
add_subdirectory(PSET5)
