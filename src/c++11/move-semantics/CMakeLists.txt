#src/c++11/move-semantics/CMakeLists.txt
project(move-semantics)

# set compile version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# execute file
add_executable(move-semantics
    Person.cpp
    main.cpp
)