#include <math.h>
#include <string.h>
#include "utils.h"
/// @file
/// Implementation of Project Euler Problem 9
///
/// @addtogroup Problem
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Find the product of a Pythagorean triplet that sums to n

  @param[in] n         sum of the Pythagorean triplet
  @param[out] product  product of the Pythagorean triplet

  @return An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int problem009(int n, long *product) {
  long a = 1, b = 1, c = 0;

  // Search for triplet
  for (a = 1; a < n; a++) {
    double frac = (2.*n*a - n*n) / (2.*a - 2.*n);

    if (fabs(frac - floor(frac)) < 1e-15) {
      b = floor(frac);
      c = n - a - b;
      break;
    }
  }

  // Save result
  *product = a * b * c;

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
///
/// @addtogroup Interface
/// @{
// -----------------------------------------------------------------------------
/**
  @brief: Project Euler Problem 9

  A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
    a2 + b2 = c2

  For example, 32 + 42 = 9 + 16 = 25 = 52.

  There exists exactly one Pythagorean triplet for which a + b + c = 1000.
  Find the product abc.

**/
// -----------------------------------------------------------------------------
int problem009CL(FILE *stream) {
  int ierr;

  int n;
  long product;

  // Get sum from user
  printf("    This code finds the product of a Pythagorean triplet that sums\n"
         "      to [n].\n\n");
  ierr = getValidUserInt("      Enter n: ", stream, 1, INT_MAX, &n);
  ErrChk(ierr);

  // Find product
  ierr = problem009(n, &product); ErrChk(ierr);

  if (product) {
    printf("    The product of the Pythagorean triplet that sums %d: %ld\n\n",
           n, product);
  } else {
    printf("    No Pythagorean triplet was found that sums to %d.\n", n);
  }

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
