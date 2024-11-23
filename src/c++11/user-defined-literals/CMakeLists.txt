#src/c++11/user-defined-literals/CMakeLists.txt
project(user-defined-literals)

# set compile version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# execute file
add_executable(user-defined-literals
    Distance.cpp
    main.cpp
)