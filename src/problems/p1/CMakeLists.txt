# build p1 as a library so we can make the main and benchmark
add_library (p1_lib STATIC src/p1.cpp)
target_include_directories(p1_lib  PUBLIC "include")
target_link_libraries(p1_lib    PRIVATE     project_options
                                             project_warnings
                                             fmt::fmt
                                             tbb
)

# Add the main exeucutable
add_executable (p1_main src/p1_main.cpp)
target_include_directories(p1_main  INTERFACE include)
target_link_libraries(p1_main    PRIVATE     project_options
                                             project_warnings
                                             fmt::fmt
                                             p1_lib
                     )



