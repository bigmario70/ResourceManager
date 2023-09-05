cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp ResourceLoaderTest.cpp ResourceLoaderFixture.cpp)
add_executable(runResourceLoaderTests ${TEST_SOURCE_FILES})
target_link_libraries(runResourceLoaderTests gtest gtest_main ${PROJECT_NAME}Library ${wxWidgets_LIBRARIES})