/**
 * @author Andrue Peters
 * @date 1/29/20
 * 
 * @brief 
 */
#include <iostream>
#include <p1.h>

int main()
{
    std::cout << "p1_loop: " << p1_loop(1000) << std::endl;
    std::cout << "p1_loop_constexpr: " << p1_loop_constexpr(1000) << std::endl;
    std::cout << "smart: " << p1_partial_sum_formula(1000) << std::endl;
    return 0;
}