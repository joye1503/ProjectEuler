/// @file
/// Test Project Euler getValidUserInt
/// \test Test getValidUserInt result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  int trueResult = 7;
  FILE *stream;
  int lower = 1, upper = 500, input;

  // Open file
  stream = fopen("tests/input/test-util-getvaliduserint.in", "r");
  if(stream == NULL) {
    // LCOV_EXCL_START
    perror("Error opening file\n");
    return(-1);
    // LCOV_EXCL_STOP
  }

  // Get userInt
  getValidUserInt("", stream, lower, upper, &input);

  // Check
  if (input != trueResult)
    // LCOV_EXCL_START
    printf("Error:\n\tComputed: %d != True: %d\n", input, trueResult);
  // LCOV_EXCL_STOP

  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
