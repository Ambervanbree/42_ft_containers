cmake_minimum_required(VERSION 3.14)
project(ft_containers)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

# including headers
include_directories(../include/other)
include_directories(../include/containers)
include_directories(../include/iterators)

# including sources
# add_subdirectory(tests/ft)
# add_subdirectory(tests/std)
add_subdirectory(tests)
add_subdirectory(googletest)
