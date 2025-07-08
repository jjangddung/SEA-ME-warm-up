#최상위 CMakeLists.txt
# MyProject/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(exercise0)

# C++ 표준 지정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include 디렉토리 포함 (헤더 파일 찾을 수 있도록)
include_directories(include)


# 실행 파일 생성
add_executable(exercise0
    src/main.cpp
    src/car.cpp
)
