cmake_minimum_required(VERSION 3.14)
project(my_project)

# Set policy for handling timestamps in FetchContent
cmake_policy(SET CMP0135 NEW)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# == TEMPLATE == 
#
# add_executable(
#   xxx_test
#   xxx_test.cc
#   ../src/xxx.c
# )
# target_link_libraries(
#   xxx_test
#   GTest::gtest_main
# )
#
# include(GoogleTest)
# gtest_discover_tests(xxx_test)


add_executable(
  node_test
  node_test.cc
  ../src/node.c 
)
target_link_libraries(
  node_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(node_test)
