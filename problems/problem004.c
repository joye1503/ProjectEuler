#include <math.h>
#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 4
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the largest palindrome made from the product of two numbers of
           a given number of digits

  @param[in] digits       number of digits for each number
  @param[out] palindrome  largest palindrome product

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem004(int digits, long *palindrome) {
  // Initalize
  *palindrome = -1;

  // Upper and lower bounds on each number
  long lower = longPow(10, digits - 1), upper = 9;
  for (long i = 1; i < digits; i++)
    upper += longPow(10, i) * 9;

  // Find palindrome
  for (long first = upper; first >= lower; first--) {
    for (long second = upper; second >= lower; second--) {
      bool found = false;
      // Check for palindrome
      isPalindrome(first * second, &found);
      // Modify bounds and update largest found if palindrome
      if (found) {
        *palindrome = longMax(first * second, *palindrome);
        lower = second;
        break;
      }
    }
  }

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
///
/// @addtogroup Interface
/// @{
// -----------------------------------------------------------------------------
/**
  @brief: Project Euler Problem 4

  A palindromic number reads the same both ways. The largest palindrome made
  from the product of two 2-digit numbers is 9009 = 91 × 99.

  Find the largest palindrome made from the product of two 3-digit numbers.

**/
// -----------------------------------------------------------------------------
int problem004CL(FILE *stream) {
  int number;
  long palindrome;

  // Get a and limit from user
  printf("    This code finds the largest palindrome which is a product of\n"
         "      [number] digit numbers.\n\n");
  getUserInt("      Enter number: ", stream, &number);

  // Find sum of multiples
  problem004(number, &palindrome);

  printf("    The largest palindrome product of %d digit numbers: %ld\n\n",
         number, palindrome);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
