/// @file
/// Test Project Euler getUserInt
/// \test Test getUserInt result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  int trueResult = 7;
  FILE *stream;
  int input;

  // Open file
  stream = fopen("tests/input/test-util-getuserint.in", "r");
  if(stream == NULL) {
    // LCOV_EXCL_START
    perror("Error opening file\n");
    return(-1);
    // LCOV_EXCL_STOP
  }

  // Get userInt
  getUserInt("", stream, &input);

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
