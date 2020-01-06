/// @file
/// Test Project Euler Problem 3
/// \test Test problem 3 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  FILE *stream;

  // Open file
  stream = fopen("tests/input/test-problem-003.in", "r");
  if(stream == NULL) {
    // LCOV_EXCL_START
    perror("Error opening file\n");
    return(-1);
    // LCOV_EXCL_STOP
  }

  // Get largest prime factor
  problem3CL(stream);

  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
