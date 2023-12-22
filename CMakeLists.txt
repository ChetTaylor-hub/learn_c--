cmake_minimum_required(VERSION 3.0.0)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
project(demo1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

#include_directories(MyVector/include)
add_executable(demo1 InstanceProject/Producer_Cousmer.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
