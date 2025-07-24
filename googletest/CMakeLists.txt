cmake_minimum_required(VERSION 3.14)

project(mp_HW03)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_library(mp_HW03Lib SHARED ../Task3/src/main.cpp)

add_executable(mp_HW03Tests ../Task3.Tests/OptimalBinaryTree.tests.cpp)

target_link_libraries(mp_HW03Tests mp_HW03Lib gtest gtest_main pthread)