# 
# Andrue Peters
# 3/25/20
#
# This file is repsonsible for building the various components of problem 2
#       * p1 is a shared library that only solves project euler problem 2. It is included multiple areas throughout this entire project
#       * p2_benchmark links to the main benchmarks file
#       * p2_test links to the main test file
#       * p2_main is used to show the answer to p2

# build p2 as a library so we can make the main and benchmark
add_library (p2 SHARED src/p2.cpp)
target_include_directories(p2  PUBLIC "include")
target_link_libraries(p2    PRIVATE     project_options
                                             project_warnings
                                             fmt::fmt
                                             math_lib
)

# build p1 as a library so we can make the main and benchmark
add_library (p2_benchmark SHARED src/p2_benchmark.cpp)
target_include_directories(p2_benchmark  PUBLIC "include")
target_link_libraries(p2_benchmark    PRIVATE   project_options
                                                project_warnings
                                                p2
)

# build p1 as a library so we can make the main, benchmark, and GTest
add_library (p2_test SHARED src/p2_test.cpp)
target_include_directories(p2_test  PUBLIC "include")
target_link_libraries(p2_test    PRIVATE      project_options
                                              project_warnings
                                              fmt::fmt
                                              p2
                                              GTest::GTest
)


# Add the main exeucutable
add_executable (p2_main src/p2_main.cpp)
target_include_directories(p2_main  INTERFACE include)
target_link_libraries(p2_main    PRIVATE     project_options
                                             project_warnings
                                             external_dependencies
                                             fmt::fmt
                                             p2
                     )



