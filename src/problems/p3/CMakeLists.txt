# build p3 as a library so we can make the main and benchmark
add_library (p3_lib STATIC src/p3.cpp)
target_include_directories(p3_lib  PUBLIC "include")
target_link_libraries(p3_lib    PRIVATE     project_options
                                            project_warnings
                                            fmt::fmt
)

# Add the main exeucutable
add_executable (p3_main src/p3_main.cpp)
target_include_directories(p3_main  INTERFACE include)
target_link_libraries(p3_main    PRIVATE     project_options
                                             project_warnings
                                             external_dependencies
                                             fmt::fmt
                                             p3_lib
                     )


