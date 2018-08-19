cmake_minimum_required(VERSION 3.0)
if(NOT CMAKE_VERSION VERSION_LESS 3.1)
    set(CMAKE_CXX_STANDARD 11)
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -O3")
endif()

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(Algorithms)

add_executable(
    bubbleSort
    sorting/bubbleSort.cpp
)

add_executable(
    selectionSort
    sorting/selectionSort.cpp
)

add_executable(
    mergeSort
    sorting/mergeSort.cpp
)

add_executable(
    quickSort
    sorting/quickSort.cpp
)
