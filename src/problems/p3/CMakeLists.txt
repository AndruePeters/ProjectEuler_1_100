# build p3 as a library so we can make the main and benchmark
add_library (p3 SHARED src/p3.cpp)
target_include_directories(p3  PUBLIC "include")
target_link_libraries(p3    PRIVATE     project_options
                                            project_warnings
                                            fmt::fmt
)

# build p1 as a library so we can make the main and benchmark
add_library (p3_benchmark SHARED src/p3_benchmark.cpp)
target_include_directories(p3_benchmark  PUBLIC "include")
target_link_libraries(p3_benchmark    PRIVATE   project_options
                                                project_warnings
                                                
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


