# build p2 as a library so we can make the main and benchmark
add_library (p2_lib STATIC src/p2.cpp)
target_include_directories(p2_lib  PUBLIC "include")
target_link_libraries(p2_lib    PRIVATE     project_options
                                             project_warnings
                                             fmt::fmt
                                             tbb
)

# Add the main exeucutable
add_executable (p2_main src/p2_main.cpp)
target_include_directories(p2_main  INTERFACE include)
target_link_libraries(p2_main    PRIVATE     project_options
                                             project_warnings
                                             fmt::fmt
                                             p2_lib
                     )



