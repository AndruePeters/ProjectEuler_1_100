# 
# Andrue Peters
# 4/4/20
#
# This file is repsonsible for building the various components of problem 3
#       * p5 is a shared library that only solves project euler problem 3. It is included multiple areas throughout this entire project
#       * p5_benchmark links to the main benchmarks file
#       * p5_test links to the main test file
#       * p5_main is used to show the answer to p5

# build p5 as a library so we can make the main and benchmark
add_library (p5 SHARED src/p5.cpp)
target_include_directories(p5  PUBLIC "include")
target_link_libraries(p5    PRIVATE     project_options
                                            project_warnings
                                            fmt::fmt
                                            math_lib
)

# build p5 as a library so we can make the main and benchmark
add_library (p5_benchmark SHARED src/p5_benchmark.cpp)
target_include_directories(p5_benchmark  PUBLIC "include")
target_link_libraries(p5_benchmark    PRIVATE   project_options
                                                project_warnings
                                                math_lib
                                                
)

# build p5 as a library so we can make the main, benchmark, and GTest
add_library (p5_test SHARED src/p5_test.cpp)
target_include_directories(p5_test  PUBLIC "include")
target_link_libraries(p5_test    PRIVATE      project_options
                                              project_warnings
                                              fmt::fmt
                                              p5
                                              math_lib
                                              GTest::GTest
)

# Add the main exeucutable
add_executable (p5_main src/p5_main.cpp)
target_include_directories(p5_main  INTERFACE include)
target_link_libraries(p5_main    PRIVATE     project_options
                                             project_warnings
                                             external_dependencies
                                             fmt::fmt
                                             p5
                                             math_lib
                     )


