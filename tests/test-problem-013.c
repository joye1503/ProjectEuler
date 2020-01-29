/// @file
/// Test Project Euler Problem 13
/// \test Test problem 13 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  FILE *stream;

  // Open file
  stream = fopen("tests/input/test-problem-013.in", "r");
  if(stream == NULL) {
    // LCOV_EXCL_START
    perror("Error opening file\n");
    return(-1);
    // LCOV_EXCL_STOP
  }

  // Get first 5 digits of sum
  problem013CL(stream);

  // Get first 9 digits of sum
  problem013CL(stream);

  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
