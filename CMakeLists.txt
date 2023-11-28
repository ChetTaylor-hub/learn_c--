cmake_minimum_required(VERSION 3.0.0)
project(demo1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

#include_directories(MyVector/include)
add_executable(demo1 LearningPaths/STL/vector/string_find.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
