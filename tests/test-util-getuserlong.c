/// @file
/// Test Project Euler getUserLong
/// \test Test getUserLong result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  long trueResult = 600851475143;
  FILE *stream;
  long input;

  // Open file
  stream = fopen("tests/input/test-util-getuserlong.in", "r");
  if(stream == NULL) {
    // LCOV_EXCL_START
    perror("Error opening file\n");
    return(-1);
    // LCOV_EXCL_STOP
  }

  // Get userInt
  getUserLong("", stream, &input);

  // Check
  if (input != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %ld != True: %ld\n", input, trueResult);
  // LCOV_EXCL_STOP

  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
