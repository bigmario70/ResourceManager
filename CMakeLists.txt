cmake_minimum_required(VERSION 3.25)
project(LinesLoader)

set(CMAKE_CXX_STANDARD 11)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME}  main.cpp Observer.h Subject.h LinesLoader.cpp LinesLoader.h ProgressBar.cpp ProgressBar.h)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})