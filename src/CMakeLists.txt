########################################################################
#       This CMake file adds the various problems and Google BenchMark #
########################################################################
add_subdirectory (problems)

# project_problems acts like static library of all project euler problems solved
add_library (project_problems INTERFACE ) 
target_link_libraries(project_problems INTERFACE p1 p2 p3)

# project_benchmarks acts like a static library of all project euler problem benchmarks
add_library (project_benchmarks INTERFACE )
target_link_libraries( project_benchmarks INTERFACE p1_benchmark p2_benchmark p3_benchmark)


# these are all of the lovely benchmarks
add_executable(ProjectEulerBenchmarks benchmark.cpp)
target_link_libraries(ProjectEulerBenchmarks PRIVATE project_options
                                                     project_warnings
                                                     benchmark::benchmark
                                                     fmt::fmt
                                                     spdlog::spdlog
                                                     project_problems
                                                     project_benchmarks)

# gtests... not sure if I actually need these
enable_testing()
add_executable(ProjectEulerTests test.cpp)
target_include_directories(ProjectEulerTests PUBLIC "${CMAKE_SOURCE_DIR}/src/problems/p1/include" )
target_link_libraries(ProjectEulerTests PRIVATE 
                        project_options 
                        project_warnings 
                        project_problems
                        GTest::GTest GTest::Main)
add_test( NAME projectEulerTests COMMAND ProjectEulerTests )

