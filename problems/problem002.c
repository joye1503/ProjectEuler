#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 2
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the sum of Fibonacci numbers that are multiples of a below limit

  @param[in] a      divisor
  @param[in] limit  limit for sum
  @param[out] sum   sum of multiples

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem002(long a, long limit, long *sum) {
  // Initalize
  *sum = 0;

  // Fibonacci numbers
  int f0 = 0, f1 = 1, f2 = f0 + f1;
  while (f2 < limit) {
    // Multiples of a
    if (!(f2 % a))
      *sum += f2;

    // Iterate
    f0 = f1;
    f1 = f2;
    f2 = f0 + f1;
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
  @brief: Project Euler Problem 2

  Each new term in the Fibonacci sequence is generated by adding the previous
  two terms. By starting with 1 and 2, the first 10 terms will be:

  1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

  By considering the terms in the Fibonacci sequence whose values do not exceed
  four million, find the sum of the even-valued terms.
**/
// -----------------------------------------------------------------------------
int problem002CL(FILE *stream) {
  int ierr;

  long a, limit, sum;

  // Get a and limit from user
  printf("    This code finds the sum of all Fibonacci numbers that are\n"
         "      multiples of [a] below [limit].\n\n");
  ierr = getUserLong("      Enter a: ", stream, &a); ErrChk(ierr);
  ierr = getUserLong("      Enter limit: ", stream, &limit); ErrChk(ierr);

  // Find sum of multiples
  ierr = problem002(a, limit, &sum); ErrChk(ierr);

  printf("    Sum of Fibonacci numbers that are multiples of %ld below %ld: "
         "%ld\n\n", a, limit, sum);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
