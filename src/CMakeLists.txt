# 
# Andrue Peters
# 3/25/20
#
# This file is responsible for building the GTests and Benchmarks

# build the libraries and problems
add_subdirectory(libraries)
add_subdirectory (problems)

# project_problems acts like shared library of all libraries
add_library (project_problems INTERFACE ) 
target_link_libraries(project_problems INTERFACE p1 p2 p3)

# project_benchmarks acts like a shared library of all project euler problem benchmarks
add_library (project_benchmarks INTERFACE )
target_link_libraries( project_benchmarks INTERFACE p1_benchmark p2_benchmark p3_benchmark)

# project_tests acts like a shared library of all project euler tests
add_library (project_tests INTERFACE )
target_link_libraries( project_tests INTERFACE p1_test p2_test p3_test)



# these are all of the lovely benchmarks
add_executable(ProjectEulerBenchmarks benchmark.cpp)
target_link_libraries(ProjectEulerBenchmarks PRIVATE 
    benchmark::benchmark
    project_problems
    project_benchmarks)

enable_testing()
add_executable(ProjectEulerTests test.cpp)
target_link_libraries(ProjectEulerTests PRIVATE 
    project_tests
    GTest::GTest 
    GTest::Main)
add_test( NAME projectEulerTests COMMAND ProjectEulerTests )

