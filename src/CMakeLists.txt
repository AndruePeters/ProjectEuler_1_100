########################################################################
#       This CMake file adds the various problems and Google BenchMark #
########################################################################
add_subdirectory (problems)

add_executable(ProjectEulerBenchmarks benchmark.cpp)
target_include_directories(ProjectEulerBenchmarks PUBLIC 
                        "${CMAKE_SOURCE_DIR}/src/problems/p1/include"
                        "${benchmark_INCLUDE_DIRS}")

message (${CMAKE_SOURCE_DIR}/src/problems/p1/include)
target_link_libraries(ProjectEulerBenchmarks PRIVATE project_options
                                                     project_warnings
                                                     benchmark::benchmark
                                                     spdlog::spdlog
                                                     p1_lib)