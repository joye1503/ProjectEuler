/// @file
/// Test Project Euler getValidUserLong
/// \test Test getValidUserLong result
#include <stdio.h>
#include "utils.h"
// -----------------------------------------------------------------------------
int main(void) {
  long trueResult = 7;
  FILE *stream;
  long lower = 1, upper = 500, input;

  // Open file
  stream = fopen("tests/input/test-util-getvaliduserlong.in" , "r");
  if(stream == NULL) {
    perror("Error opening file\n");
    return(-1);
  }

  // Get userInt
  getValidUserLong("", stream, lower, upper, &input);

  // Check
  if (input != trueResult)
    printf("Error:\n\tComputed: %ld != True: %ld\n", input, trueResult);

  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
