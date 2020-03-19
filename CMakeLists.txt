cmake_minimum_required(VERSION 3.13)
project(ProjectEuler)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

set (CMAKE_BUILD_TYPE Release)

include (CTest)


# Add the external libraries

#add_subdirectory (${CMAKE_SOURCE_DIR}/external)

# Add my custom libraries and utilities
#add_subdirectory (${CMAKE_SOURCE_DIR}/libraries)

#####################################################################
#               Let's handle Conan                                  #
#####################################################################
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file( DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.15/conan.cmake"
      "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_check(REQUIRED)

execute_process(COMMAND ${CONAN_CMD} remote list OUTPUT_VARIABLE CONAN_REMOTES)

conan_add_remote(NAME bincrafters INDEX 1
    URL https://api.bintray.com/conan/bincrafters/public-conan)

conan_add_remote(NAME conan_public INDEX 2
    URL https://api.bintray.com/conan/conan/conan-center )

conan_cmake_run(CONANFILE conanfile.txt
                BASIC_SETUP
                CONAN_COMMAND ${CONAN_CMD}
                BUILD missing)

# need this to force benchmark to compile
# need to add bug
set (CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_BINARY_DIR}")

find_package(fmt)
find_package(spdlog)
find_package(benchmark)

#both are required because of using conan
find_package(gtest REQUIRED)
find_package(GTest REQUIRED)

find_package(Eigen3)


message ( "CMAKE_MODULE_PATH   : ${CMAKE_MODULE_PATH}")


#####################################################################
#               Let's Continue                                      #
#####################################################################
# Link this 'library' to use the standard warnings
add_library(project_warnings INTERFACE)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE )

# Link this `library` for project includes

# Link this `library` for external projects
add_library(external_dependencies INTERFACE )
target_include_directories(external_dependencies INTERFACE
                            ${Eigen3_INCLUDE_DIR} )


# Create the compile options
target_include_directories(project_options INTERFACE include 
                            external/cxxopts/include
                            )
#target_link_options( project_options INTERFACE -flto ) # Travis CI doesn't have a new enough cmake
target_link_libraries( project_options INTERFACE tbb )
target_compile_options(project_warnings
                            INTERFACE
                            -Wall
                            -Wextra # reasonable and standard
                            -Wshadow # warn the user if a variable declaration shadows one from a
                                    # parent context
                            -Wnon-virtual-dtor # warn the user if a class with virtual functions has a
                                                # non-virtual destructor. This helps catch hard to
                                                # track down memory errors
                            #-Wold-style-cast # warn for c-style casts // disable because of
                            -Wcast-align # warn for potential performance problem casts
                            -Wunused # warn on anything being unused
                            -Woverloaded-virtual # warn if you overload (not override) a virtual
                                                # function
                            -Wpedantic # warn if non-standard C++ is used
                            #-Wconversion # warn on type conversions that may lose data
                            #-Wsign-conversion # warn on sign conversions
                            -Wmisleading-indentation # warn if identation implies blocks where blocks
                                                    # do not exist
                            -Wduplicated-cond # warn if if / else chain has duplicated conditions
                            -Wduplicated-branches # warn if if / else branches have duplicated code
                            -Wlogical-op # warn about logical operations being used where bitwise were
                                        # probably wanted
                            -Wnull-dereference # warn if a null dereference is detected
                            -Wuseless-cast # warn if you perform a cast to the same type
                            -Wdouble-promotion # warn if float is implicit promoted to double
                            -Wformat=2 # warn on security issues around functions that format output
                                        # (ie printf)
                            -Wno-unknown-warning-option
                            -O3
                            -mllvm
                            -polly
                            # -flto #commented out because Travis CI is old
                            -Wpessimizing-move
                            -march=native
                            -std=c++17
                            -mavx2
                            -Rpass-analysis=polly
                            )


# Add the src code cmake lists
add_subdirectory (src)
