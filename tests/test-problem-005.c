/// @file
/// Test Project Euler Problem 5
/// \test Test problem 5 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  FILE *stream;

  // Open file
  stream = fopen("tests/input/test-problem-005.in", "r");
  if(stream == NULL) {
    // LCOV_EXCL_START
    perror("Error opening file\n");
    return(-1);
    // LCOV_EXCL_STOP
  }

  // Get lcm of numbers from 1 to 10
  problem005CL(stream);

  // Get lcm of numbers from 1 to 20
  problem005CL(stream);

  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
