#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 2
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the sum of Fibonacci numbers that are multiples of a below limit

  @param[in] a     divisor
  @param[in] limit limit for sum
  @param[out] sum  sum of multiples

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem2(int a, int limit, int *sum) {
  // Initalize
  *sum = 0;

  // Fibonacci numbers
  int f1 = 0, f2 = 1, f3 = 1;
  while (f3 < limit) {
    // Multiples of a
    if (!(f3 % a))
      *sum += f3;

    // Iterate
    f1 = f2;
    f2 = f3;
    f3 = f1 + f2;
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
  @brief: Project Euler Problem 1

  Each new term in the Fibonacci sequence is generated by adding the previous
  two terms. By starting with 1 and 2, the first 10 terms will be:

  1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

  By considering the terms in the Fibonacci sequence whose values do not exceed
  four million, find the sum of the even-valued terms.
**/
// -----------------------------------------------------------------------------
int problem2CL(void) {
  int a, limit, sum;

  // Get a, b, and limit
  printf("This code finds the sum of all Fibonacci numbers that are "
         "multiples of [a] below [limit].\n\n");
  getUserInt("Enter a: ", &a);
  getUserInt("Enter limit: ", &limit);

  // Find sum of multiples
  problem2(a, limit, &sum);

  printf("Sum of Fibonacci numbers that are multiples of %d below %d: %d\n",
         a, limit, sum);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
