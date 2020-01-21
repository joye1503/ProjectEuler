#include <math.h>
#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 6
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the difference between the square of a sum and the sum of squares
           of a range of numbers from 1 to limit

  @param[in] limit        upper limit of range to consider
  @param[out] difference  difference between square of sum and sum of squares

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem006(int limit, long *difference) {
  // Initalize
  *difference = 0;

  // Calculate difference
  //  Note: (a + b + c + ...)^2 = a^2 + b^2 + ... + 2ab + 2ac + ...
  for (long i = limit; i > 0; i--)
    for (long j = i-1; j > 0; j--)
      *difference += 2*i*j;

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
///
/// @addtogroup Interface
/// @{
// -----------------------------------------------------------------------------
/**
  @brief: Project Euler Problem 6

  The sum of the squares of the first ten natural numbers is,

    12 + 22 + ... + 102 = 385

  The square of the sum of the first ten natural numbers is,

    (1 + 2 + ... + 10)2 = 552 = 3025

  Hence the difference between the sum of the squares of the first ten natural
  numbers and the square of the sum is 3025 − 385 = 2640.

  Find the difference between the sum of the squares of the first one hundred
  natural numbers and the square of the sum.
**/
// -----------------------------------------------------------------------------
int problem006CL(FILE *stream) {
  int ierr;

  int limit;
  long difference;

  // Get a and limit from user
  printf("    This code finds the difference between the square of a sum and\n"
         "    the sum of squares of numbers from 1 to [limit].\n\n");
  ierr = getValidUserInt("      Enter limit: ", stream, 1, INT_MAX, &limit);
  ErrChk(ierr);

  // Find lcm
  ierr = problem006(limit, &difference); ErrChk(ierr);

  printf("    The difference between the square of a sum and the sum of\n"
         "    of squares of numbers from 1 to %d: %ld\n\n",
         limit, difference);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
