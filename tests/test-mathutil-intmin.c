/// @file
/// Test Project Euler intMin
/// \test Test intMin result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  int trueResult = 3;
  int a = 3, b = 7, min;

  // Get min
  min = intMin(a, b);

  // Check
  if (min != trueResult)
    printf("Error:\n\tComputed: %d != True: %d\n", min, trueResult);

  return 0;
}
// -----------------------------------------------------------------------------
