cmake_minimum_required(VERSION 3.6)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES problem02.cpp problem03.cpp)
add_executable(leetcode ${SOURCE_FILES})