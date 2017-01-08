cmake_minimum_required(VERSION 3.6)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES problem02.cpp problem03.cpp problem04.cpp problem05.cpp problem06.cpp problem14.cpp problem15.cpp problem16.cpp problem18.cpp problem17.cpp)
add_executable(leetcode ${SOURCE_FILES})