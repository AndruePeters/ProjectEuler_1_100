#include <p2.h>

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

int main()
{
     std::vector<int> fibNumbers(30);
     std::iota(fibNumbers.begin(), fibNumbers.end(), 1);

     for (auto num : fibNumbers) {
         std::cout << "Fibonacci of " << num << ": " << fib_fast_matrix_exp(num) << "\n";
     }


    return 0;
}