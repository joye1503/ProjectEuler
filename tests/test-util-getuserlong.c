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
  stream = fopen("tests/input/test-util-getuserlong.in" , "r");
  if(stream == NULL) {
    perror("Error opening file\n");
    return(-1);
  }

  // Get userInt
  getUserLong("", stream, &input);

  // Check
  if (input != trueResult)
    printf("Error:\n\tComputed: %ld != True: %ld\n", input, trueResult);


  // Close
  fclose(stream);

  return 0;
}
// -----------------------------------------------------------------------------
