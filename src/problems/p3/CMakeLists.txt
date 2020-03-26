# 
# Andrue Peters
# 3/25/20
#
# This file is repsonsible for building the various components of problem 3
#       * p3 is a shared library that only solves project euler problem 3. It is included multiple areas throughout this entire project
#       * p3_benchmark links to the main benchmarks file
#       * p3_test links to the main test file
#       * p3_main is used to show the answer to p3

# build p3 as a library so we can make the main and benchmark
add_library (p3 SHARED src/p3.cpp)
target_include_directories(p3  PUBLIC "include")
target_link_libraries(p3    PRIVATE     project_options
                                            project_warnings
                                            fmt::fmt
                                            math_lib
)

# build p3 as a library so we can make the main and benchmark
add_library (p3_benchmark SHARED src/p3_benchmark.cpp)
target_include_directories(p3_benchmark  PUBLIC "include")
target_link_libraries(p3_benchmark    PRIVATE   project_options
                                                project_warnings
                                                
)

# build p3 as a library so we can make the main, benchmark, and GTest
add_library (p3_test SHARED src/p3_test.cpp)
target_include_directories(p3_test  PUBLIC "include")
target_link_libraries(p3_test    PRIVATE      project_options
                                              project_warnings
                                              fmt::fmt
                                              p3
                                              GTest::GTest
)

# Add the main exeucutable
add_executable (p3_main src/p3_main.cpp)
target_include_directories(p3_main  INTERFACE include)
target_link_libraries(p3_main    PRIVATE     project_options
                                             project_warnings
                                             external_dependencies
                                             fmt::fmt
                                             p3
                     )


