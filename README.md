# ProjectEuler_1_100
Solutions to the first 100 Project Euler problems.

## Build System
* From root, run:
    * `cmake -Bbuild`
    * `cmake --build build -- -j4`
* Now, all binaries should be in build/bin
* Benchmark will be at **build/bin/ProjectEulerBenchmarks**
* Each problem will have an associated binary file at **build/bin/px_main**, where x is the problem number.

## Structure
* Each problem has its folder
* The problem solution itself is compiled as a shared library.
* There is a benchmarks file associated with each problem.
    * Benchmarks are compiled as shared libraries -- this reduces compile times for development.
* Each problem has a main associated to verify the output.

## Solved Problems
* Problem 1
* Problem 2

