cmake_minimum_required(VERSION 3.25)
project(ResourceLoader)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME}  main.cpp Observer.h Subject.h ResourceLoader.cpp ResourceLoader.h ProgressBar.cpp ProgressBar.h
        MyExceptions.h)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})