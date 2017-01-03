cmake_minimum_required(VERSION 3.5)
project(kmeans)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES kmeans.cpp)
add_executable(kmeans ${SOURCE_FILES})