/// @file
/// Test Project Euler Problem 6
/// \test Test problem 6 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  FILE *stream;

  // Open file
  stream = fopen("tests/input/test-problem-006.in", "r");
  if(stream == NULL) {
    // LCOV_EXCL_START
    perror("Error opening file\n");
    return(-1);
    // LCOV_EXCL_STOP
  }

  // Get sum-squares difference of numbers from 1 to 10
  problem006CL(stream);

  // Get sum-squares difference of numbers from 1 to 100
  problem006CL(stream);

  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
