cmake_minimum_required(VERSION 2.6)
project(ConvUAO)

SET(CMAKE_CXX_FLAGS -std=c++17)
SET(CMAKE_CXX_COMPILER "/opt/rh/devtoolset-8/root/bin/g++")
SET(CMAKE_C_COMPILER "/opt/rh/devtoolset-8/root/bin/gcc")

add_executable(ConvUAO main.cpp)
target_link_libraries(ConvUAO stdc++fs stdc++)

install(TARGETS ConvUAO RUNTIME DESTINATION bin)
