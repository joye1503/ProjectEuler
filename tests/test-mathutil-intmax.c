/// @file
/// Test Project Euler intMax
/// \test Test intMax result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  int trueResult = 7;
  int a = 3, b = 7, max;

  // Get max
  max = intMax(a, b);

  // Check
  if (max != trueResult)
    printf("Error:\n\tComputed: %d != True: %d\n", max, trueResult);

  return 0;
}
// -----------------------------------------------------------------------------
