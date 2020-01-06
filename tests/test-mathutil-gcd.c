/// @file
/// Test Project Euler calculateGCD
/// \test Test calculateGCD result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  long trueResult = 7;
  long a = 14, b = 35, gcd;

  // Get GCD
  calculateGCD(a, b, &gcd);

  // Check
  if (gcd != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %ld != True: %ld\n", gcd, trueResult);
  // LCOV_EXCL_STOP

  return 0;
}
// -----------------------------------------------------------------------------
