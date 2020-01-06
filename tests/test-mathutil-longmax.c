/// @file
/// Test Project Euler longMax
/// \test Test longMax result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  long trueResult = 600851475147;
  long a = 600851475143, b = 600851475147, max;

  // Get max
  max = longMax(a, b);

  // Check
  if (max != trueResult)
    printf("Error:\n\tComputed: %ld != True: %ld\n", max, trueResult);

  return 0;
}
// -----------------------------------------------------------------------------
