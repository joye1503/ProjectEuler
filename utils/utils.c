#include <stdio.h>
#include <stdlib.h>
/// @file
/// Interface utilities
///
/// @addtogroup Utilities
/// @{
// -----------------------------------------------------------------------------
/**
  @brief Get user input integer

  @param[in] userPrompt Text for user prompt
  @param[out] input     User input integer

  @return  An error code: 0 - success, otherwise - failure
**/
// -----------------------------------------------------------------------------
int getUserInt(char *userPrompt, int *input) {
  char *p, s[100];
  int n = 0;

  // Get user input with given prompt
  printf("%s", userPrompt);
  while (fgets(s, sizeof(s), stdin)) {
    n = strtol(s, &p, 10);
    // Check for integer
    if (p == s || *p != '\n') {
      printf("%s", userPrompt);
    } else break;
  }

  // Save user input
  *input = n;

  return 0;
};
// -----------------------------------------------------------------------------
/// @}
