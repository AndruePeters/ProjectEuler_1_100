# ProjectEuler_1_100
Solutions to the first 100 Project Euler problems.

## Build System
* From the project root, run:
    * `cmake -Bbuild`
    * `cmake --build build`
* Now, all binaries should be in build/bin
* Benchmarks for the Problems will be at **build/bin/ProjectEulerBenchmarks**
* Tests for solved Problems will be at **build/bin/ProjectEulerTests**
* Each problem will have an associated binary file at **build/bin/px_main**, where x is the problem number.

## Structure
* There is a folder for each project, `px` where, x is the problem number
* Every problem has the following folder structure:
    * `include/` : contains the headers related to solving the problem.
    * `src/` : contains the implentations, test, main, benchmark, and any other files needed.
    * `README.md` contains the problem prompt.
    * `CmakeLists.txt` tells cmake how to build this problem.
* Each problem is build into three shared libraries where the name of the library is the same as the source file. 
    * `px` is the library for the solution implementation. `px` is linked to `px_test`, `px_benchmark`, `px_main`, and is linked to the CMake target `project_problems`
    * `px_test` contains the GTest for the problem. It is linked to the CMake target, `ProjectEulerTests`. 
    * `px_benchmark` contains the Google Benchmark for the problem. it is linked to the CMake Target `ProjectEulerBenchmarks`
* There will also always be a `px_main`, which is used to run a specific problem.

## Libraries
* math_lib
    * gen_math
    * primes


## Solved Problems
* Problem 1
* Problem 2
* Problem 3
* Problem 4
* Problem 5