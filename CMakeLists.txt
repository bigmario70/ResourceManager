cmake_minimum_required(VERSION 3.25)
project(LinesLoader)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME}  main.cpp Observer.h Subject.h)
