/// @file
/// Test Project Euler Problem 2
/// \test Test problem 2 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  FILE *stream;

  // Open file
  stream = fopen("tests/input/test-problem-002.in", "r");
  if(stream == NULL) {
    // LCOV_EXCL_START
    perror("Error opening file\n");
    return(-1);
    // LCOV_EXCL_STOP
  }

  // Get sum
  problem2CL(stream);

  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
