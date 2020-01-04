#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------------------------------------------
// Utilites
// -----------------------------------------------------------------------------
int getUserInt(char *userPrompt, int *input) {
  char *p, s[100];
  int n = 0;

  // Get user input with given prompt
  printf(userPrompt);
  while (fgets(s, sizeof(s), stdin)) {
      n = strtol(s, &p, 10);
      // Check for integer
      if (p == s || *p != '\n') {
          printf(userPrompt);
      } else break;
  }

  // Save user input
  *input = n;

  return 0;
};
