/// @file
/// Test Project Euler longMin
/// \test Test longMin result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  long trueResult = 600851475143;
  long a = 600851475143, b = 600851475147, min;

  // Get min
  min = longMin(a, b);

  // Check
  if (min != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %ld != True: %ld\n", min, trueResult);
  // LCOV_EXCL_STOP

  return 0;
}
// -----------------------------------------------------------------------------
