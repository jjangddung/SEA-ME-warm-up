cmake_minimum_required(VERSION 3.10)
project(module_2)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)

add_executable(module_2
    src/Brake.cpp
    src/Car.cpp
    src/Engine.cpp
    src/Wheel.cpp
    src/Transmission.cpp
    src/main.cpp

)

