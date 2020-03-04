# build p1 as a library so we can make the main and benchmark
add_library (p1 SHARED src/p1.cpp)
target_include_directories(p1  PUBLIC "include")
target_link_libraries(p1    PRIVATE     project_options
                                             project_warnings
                                             fmt::fmt
                                             spdlog::spdlog
)

# build p1 as a library so we can make the main and benchmark
add_library (p1_benchmark SHARED src/p1_benchmark.cpp)
target_include_directories(p1_benchmark  PUBLIC "include")
target_link_libraries(p1_benchmark    PRIVATE      project_options
                                             project_warnings
                                             fmt::fmt
                                             p1
)

# Add the main exeucutable
add_executable (p1_main src/p1_main.cpp)
target_include_directories(p1_main  INTERFACE include)
target_link_libraries(p1_main    PRIVATE     project_options
                                             project_warnings
                                             fmt::fmt
                                             p1
                     )



