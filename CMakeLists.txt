cmake_minimum_required(VERSION 3.5.0)
project(future-cpp VERSION 0.1.0 LANGUAGES C CXX)

# ver. c++11
add_subdirectory(src/c++11/move-semantics)
add_subdirectory(src/c++11/attribute)
add_subdirectory(src/c++11/user-defined-literals)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
