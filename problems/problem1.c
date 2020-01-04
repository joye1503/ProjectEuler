#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 1
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the sum of multiples of a or b below limit

  @param[in] a     first divisor
  @param[in] b     second divisor
  @param[in] limit limit for sum
  @param[out] sum  sum of multiples

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem1(int a, int b, int limit, int *sum) {
  // Initalize
  *sum = 0;

  // Multiples of a
  for (int i=a; i<limit; i+=a)
      *sum += i;

  // Multiples of b
  for (int i=b; i<limit; i+=b)
    if (i%a)
      *sum += i;

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
///
/// @addtogroup Interface
/// @{
// -----------------------------------------------------------------------------
/**
  @brief: Project Euler Problem 1

  If we list all the natural numbers below 10 that are multiples of 3 or 5, we
  get 3, 5, 6 and 9. The sum of these multiples is 23.

  Find the sum of all the multiples of 3 or 5 below 1000.
**/
// -----------------------------------------------------------------------------
int problem1CL(void) {
  int a, b, limit, sum;

  // Get a, b, and limit
  printf("This code finds the sum of all the multiples of [a] or [b]\n  below "
         "[limit].\n");
  getUserInt("Enter a: ", &a);
  getUserInt("Enter b: ", &b);
  getUserInt("Enter limit: ", &limit);

  // Find sum of multiples
  problem1(a, b, limit, &sum);

  printf("Sum of multiples of %d or %d below %d: %d\n", a, b, limit, sum);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
