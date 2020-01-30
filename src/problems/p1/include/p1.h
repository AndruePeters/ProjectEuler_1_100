/**
 * @author Andrue Peters
 * @date 1/29/20
 * 
 * @brief Various implementations to solve problem 1 of Project Euler.
 */

#ifndef P1_H
#define P1_H
#include <vector>

/**
 * @brief Raw loop to solve problem 1.
 * Naive solution.
 */
int p1_loop(const int upperBound);

/**
 * @brief Raw loop to be done at compile time.
 */
constexpr int p1_loop_constexpr(const int upperBound)
{
    int sum = 0;
    for (int i = 0; i < upperBound; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

/**
 * @brief Make use of partial sum formula.
 */
int p1_partial_sum_formula(const int upperBound);

/**
 * @brief Raw loop with a vector to compare performace.
 */
int p1_rawloop_vector(const std::vector<int>& v);

/**
 * @brief Uses std::reduce with sequential execution policy.
 */
int p1_reduce_seq_vector(const std::vector<int>& v);

/**
 * @brief Uses std::reduce with unsequential execution policy.
 */
int p1_reduce_unseq_vector(const std::vector<int>& v);

/**
 * @brief Uses std::reduce with parallel sequential execution policy.
 */
int p1_reduce_par_vector(const std::vector<int>& v);

/**
 * @brief Uses std::reduce with parallel unsequential execution policy.
 */
int p1_reduce_par_unseq_vector(const std::vector<int>& v);

/**
 * @brief Generates the vector.
 */
std::vector<int> generateVector(const int upperBound);

/**
 * @brief Compute partial sum.
 */
template <typename T>
T finite_sum(const T n) 
{
    return static_cast<T>((0.5) * (n) * (n+1));
}

#endif