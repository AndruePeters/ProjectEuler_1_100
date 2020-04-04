///
/// \author Andrue Peters
/// \date 4/2/20
///
/// \brief Solves ProjectEuler Problem 4
///

#ifndef P4_H
#define P4_H

#include <cmath>

///
/// The smallest integer is always in the form 10^x
/// For a single digit, digit_length is 1, 10^(1-1) = 1;
/// For a double digit, digit_length is 2, 10^(2-1) = 10;
///
template <class Integer>
constexpr Integer smallest_integer(Integer digit_length)
{
    if ( digit_length == 0) return 0;
    else if (digit_length == 1) return 0;

    return std::pow(10, digit_length - 1);
}

template <class Integer>
constexpr Integer largest_integer(Integer digit_length)
{
    Integer num = 9;
    for (Integer i = 0; i < digit_length - 1; ++i) {
        num = num * 10 + 9;
    }
    return num;
}

template <class Integer>
constexpr Integer largest_multiple(const Integer mult, const Integer limit)
{
    if (mult == 0) return 0;

    Integer dividend = limit / mult;
    return dividend * mult;
}


template <class Integer>
bool is_palindrome(Integer n)
{
    Integer u = 0;
    Integer v = n;

    while (n > 0) {
        u = u * 10 + n % 10;
        n = n / 10;
    }

    return u == v;
}

// largest palindrome number of product of two 3 digit numbers
template<class Integer>
Integer largest_palindrome(Integer digit_length)
{
    // smallest integer will be in form 10^x, where x is a positive integer
    const Integer lower_limit = smallest_integer(digit_length);

    // the upper limit is the largest multiple of 11 with digit_length digits
    const Integer upper_limit = largest_integer(digit_length);
    const Integer largest_mult = largest_multiple(static_cast<Integer>(11), upper_limit);


    Integer largest_pal = 0;

    // since all even palindromes are multiples of 11, only check for multiples of 11
    for (Integer p = largest_mult; p >= lower_limit; p -= 11 ) {

        // now iterate through all numbers between the limit - this generates the multiples of 11
        // realization that all of the answers are odd, so we can subtract q by 2 instead of 1
        // this cuts down the search space by 2
        for (Integer q = upper_limit; q >= lower_limit; q -= 2) {
            Integer pal = p * q;

            // set the largest palindrome
            if (largest_pal < pal && is_palindrome(pal)) {
                largest_pal = pal;
                break;
            // there's no point in continuing if we find a number less than the 
            // current largest palindrome
            } else if (pal < largest_pal) {
                break;
            }
        }
    }

    return largest_pal;
}

unsigned largest_3digit_palindrome_product();

#endif
