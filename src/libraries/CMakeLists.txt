# 
# Andrue Peters
# 3/25/20
#
# This file is responsible for building math_lib

add_library(math_lib SHARED "src/gen_math.cpp" )
target_include_directories(math_lib PUBLIC "include" )
target_link_libraries(math_lib PRIVATE project_options project_warnings )