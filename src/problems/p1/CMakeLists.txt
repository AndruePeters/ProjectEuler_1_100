# 
# Andrue Peters
# 3/25/20
#
# This file is repsonsible for building the various components of problem 1
#       * p1 is a shared library that only solves project euler problem 1. It is included multiple areas throughout this entire project
#       * p1_benchmark links to the main benchmarks file
#       * p1_test links to the main test file
#       * p1_main is used to show the answer to p1

# build p1 as a library so we can make the main and benchmark
add_library (p1 SHARED src/p1.cpp)
target_include_directories(p1  PUBLIC "include")
target_link_libraries(p1    PRIVATE     project_options
                                             project_warnings
                                             fmt::fmt
                                             spdlog::spdlog
                                             math_lib
)

# build p1 as a library so we can make the main, benchmark, and GTest
add_library (p1_benchmark SHARED src/p1_benchmark.cpp)
target_include_directories(p1_benchmark  PUBLIC "include")
target_link_libraries(p1_benchmark    PRIVATE      project_options
                                             project_warnings
                                             fmt::fmt
                                             p1
)

# build p1 as a library so we can make the main, benchmark, and GTest
add_library (p1_test SHARED src/p1_test.cpp)
target_include_directories(p1_test  PUBLIC "include")
target_link_libraries(p1_test    PRIVATE      project_options
                                              project_warnings
                                              fmt::fmt
                                              p1
                                              GTest::GTest
)

# Add the main exeucutable
add_executable (p1_main src/p1_main.cpp)
target_include_directories(p1_main  INTERFACE include)
target_link_libraries(p1_main    PRIVATE     project_options
                                             project_warnings
                                             fmt::fmt
                                             p1
                     )



