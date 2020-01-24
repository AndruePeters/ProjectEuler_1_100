add_executable (p1 src/p1.cpp)
#add_dependencies(p1 )
target_include_directories(p1  INTERFACE src)
target_link_libraries(p1    PRIVATE     project_options
                                        project_warnings
                                        fmt::fmt
                                   #     pthread
                     )