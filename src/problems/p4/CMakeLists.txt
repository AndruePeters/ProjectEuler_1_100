# 
# Andrue Peters
# 3/25/20
#
# This file is repsonsible for building the various components of problem 3
#       * p4 is a shared library that only solves project euler problem 3. It is included multiple areas throughout this entire project
#       * p4_benchmark links to the main benchmarks file
#       * p4_test links to the main test file
#       * p4_main is used to show the answer to p4

# build p4 as a library so we can make the main and benchmark
add_library (p4 SHARED src/p4.cpp)
target_include_directories(p4  PUBLIC "include")
target_link_libraries(p4    PRIVATE     project_options
                                            project_warnings
                                            fmt::fmt
                                            math_lib
)

# build p4 as a library so we can make the main and benchmark
add_library (p4_benchmark SHARED src/p4_benchmark.cpp)
target_include_directories(p4_benchmark  PUBLIC "include")
target_link_libraries(p4_benchmark    PRIVATE   project_options
                                                project_warnings
                                                
)

# build p4 as a library so we can make the main, benchmark, and GTest
add_library (p4_test SHARED src/p4_test.cpp)
target_include_directories(p4_test  PUBLIC "include")
target_link_libraries(p4_test    PRIVATE      project_options
                                              project_warnings
                                              fmt::fmt
                                              p4
                                              GTest::GTest
)

# Add the main exeucutable
add_executable (p4_main src/p4_main.cpp)
target_include_directories(p4_main  INTERFACE include)
target_link_libraries(p4_main    PRIVATE     project_options
                                             project_warnings
                                             external_dependencies
                                             fmt::fmt
                                             p4
                     )


