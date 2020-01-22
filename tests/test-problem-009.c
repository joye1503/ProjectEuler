/// @file
/// Test Project Euler Problem 9
/// \test Test problem 9 result
#include <stdio.h>
#include "euler.h"
// -----------------------------------------------------------------------------
int main(void) {
  FILE *stream;

  // Open file
  stream = fopen("tests/input/test-problem-009.in", "r");
  if(stream == NULL) {
    // LCOV_EXCL_START
    perror("Error opening file\n");
    return(-1);
    // LCOV_EXCL_STOP
  }

  // Get product of the Pythagorean triplet that sums to 12
  problem009CL(stream);

  // Get product of the Pythagorean triplet that sums to 13 (expected failure)
  problem009CL(stream);

  // Get product of the Pythagorean triplet that sums to 1000
  problem009CL(stream);

  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
