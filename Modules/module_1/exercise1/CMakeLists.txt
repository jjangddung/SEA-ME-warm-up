cmake_minimum_required(VERSION 3.10)
project(exercise1)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)

add_executable(exercise1
    src/main.cpp
    src/Car.cpp
    src/Sports.cpp
)

