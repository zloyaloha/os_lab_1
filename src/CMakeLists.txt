cmake_minimum_required(VERSION 3.10)
project (1_OC_LAB)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(son.out son.cpp  WriteRead.cpp)
add_executable(parent.out parent.cpp WriteRead.cpp)