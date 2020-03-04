# build p2 as a library so we can make the main and benchmark
add_library (p2 SHARED src/p2.cpp)
target_include_directories(p2  PUBLIC "include")
target_link_libraries(p2    PRIVATE     project_options
                                             project_warnings
                                             fmt::fmt
                                             
)

# build p1 as a library so we can make the main and benchmark
add_library (p2_benchmark SHARED src/p2_benchmark.cpp)
target_include_directories(p2_benchmark  PUBLIC "include")
target_link_libraries(p2_benchmark    PRIVATE   project_options
                                                project_warnings
                                                p2
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



