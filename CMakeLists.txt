cmake_minimum_required(VERSION 3.8)
project(ResourceManager)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES_RL Observer.h Subject.h
        ResourceLoader.cpp ResourceLoader.h
        ProgressBar.cpp ProgressBar.h
        Model.cpp Model.h
        Controller.cpp Controller.h)

add_library(${PROJECT_NAME}Library ${SOURCE_FILES_RL})
add_executable(${PROJECT_NAME} ResourceManager.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}Library ${wxWidgets_LIBRARIES})

add_subdirectory(UnitTesting)








