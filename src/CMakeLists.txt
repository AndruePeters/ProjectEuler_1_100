########################################################################
#       This CMake file adds the various problems and Google BenchMark #
########################################################################
add_subdirectory (problems)

add_executable(ProjectEulerBenchmarks benchmark.cpp)
target_include_directories(ProjectEulerBenchmarks PUBLIC 
                        "${CMAKE_SOURCE_DIR}/src/problems/p1/include"
                        "${CMAKE_SOURCE_DIR}/src/problems/p2/include"
                        "${benchmark_INCLUDE_DIRS}")
message (${CMAKE_SOURCE_DIR}/src/problems/p1/include)
target_link_libraries(ProjectEulerBenchmarks PRIVATE project_options
                                                     project_warnings
                                                     benchmark::benchmark
                                                     spdlog::spdlog
                                                     p1_lib
                                                     p2_lib)

enable_testing()
message( "\n\nLUVA gtest: ${gtest_INCLUDE_DIR}")
add_executable(ProjectEulerTests test.cpp)
target_include_directories(ProjectEulerTests PUBLIC "${CMAKE_SOURCE_DIR}/src/problems/p1/include" )
target_link_libraries(ProjectEulerTests PRIVATE 
                        project_options 
                        project_warnings 
                        p1_lib
                        GTest::GTest GTest::Main)
add_test( NAME projectEulerTests COMMAND ProjectEulerTests )

