/// @file
/// Test Project Euler longPow
/// \test Test longPow result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  long trueResult = 2861381721051424;
  long a = 1234, b = 5, power;

  // Get power
  power = longPow(a, b);

  // Check
  if (power != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %ld != True: %ld\n", power, trueResult);
  // LCOV_EXCL_STOP

  return 0;
}
// -----------------------------------------------------------------------------
