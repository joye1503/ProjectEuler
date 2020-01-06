/// @file
/// Test Project Euler calculateLCM
/// \test Test calculateLCM result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  long trueResult = 70;
  long a = 14, b = 35, lcm;

  // Get GCD
  calculateLCM(a, b, &lcm);

  // Check
  if (lcm != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %ld != True: %ld\n", lcm, trueResult);
  // LCOV_EXCL_STOP

  return 0;
}
// -----------------------------------------------------------------------------
