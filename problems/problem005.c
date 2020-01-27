#include <math.h>
#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 5
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the least common multiple of a range of numbers from 1 to limit

  @param[in] limit  upper limit of range to consider
  @param[out] lcm   least common multiple

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem005(int limit, long *lcm) {
  // Initalize
  *lcm = 1;

  // Calculate LCM
  //  Note: lcm([1, ..., limit]) = lcm(1, [2, ..., limit])
  for (long i = 2; i <= (long)limit; i++) {
    int ierr;
    ierr = calculateLCM(*lcm, i, lcm); ErrChk(ierr);
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
  @brief: Project Euler Problem 5

  2520 is the smallest number that can be divided by each of the numbers from 1
  to 10 without any remainder.

  What is the smallest positive number that is evenly divisible by all of the
  numbers from 1 to 20?
**/
// -----------------------------------------------------------------------------
int problem005CL(FILE *stream) {
  int ierr;

  int limit;
  long lcm;

  // Get limit from user
  printf("    This code finds the least common multiple of numbers from 1 to\n"
         "    [limit].\n\n");
  ierr = getValidUserInt("      Enter limit: ", stream, 1, INT_MAX, &limit);
  ErrChk(ierr);

  // Find lcm
  ierr = problem005(limit, &lcm); ErrChk(ierr);

  printf("    The least common mulitple of numbers from 1 to %d: %ld\n\n",
         limit, lcm);

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
