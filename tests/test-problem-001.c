/// @file
/// Test Project Euler Problem 1
/// \test Test problem 1 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  FILE *stream;

  // Open file
  stream = fopen("tests/input/test-problem-001.in", "r");
  if(stream == NULL) {
    // LCOV_EXCL_START
    perror("Error opening file\n");
    return(-1);
    // LCOV_EXCL_STOP
  }

  // Get sum of multiples of 3 or 5 below 10
  problem1CL(stream);

  // Get sum of multiples of 3 or 5 below 1000
  problem1CL(stream);

  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
