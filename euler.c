#include <stdio.h>
#include "euler.h"
#include "utils.h"

// -----------------------------------------------------------------------------
// Driver
// -----------------------------------------------------------------------------
int main(void) {
  int menuOption = 0;

  printf("-------------------------------------------------------------------\n"
         "  Welcome to a Project Euler solver:\n"
         "-------------------------------------------------------------------\n"
         "  Menu Option 1: Print help information\n"
         "  Menu Option 2: Solve Euler problem\n"
         "  Menu Option 3: Exit\n\n");

  // Loop until exit
  while (menuOption != 3) {
    // Prompt user
    getValidUserInt("  Enter a menu option (1-3): ", stdin, 1, 3, &menuOption);

    // Take selected action
    switch (menuOption) {
    case 1:
      printf("---------------------------------------------------------------\n"
             "  Help:\n"
             "    Menu Option 1: Print help information\n"
             "    Menu Option 2: Solve Euler problem\n"
             "    Menu Option 3: Exit\n\n");
      break;

    case 2: {
      int problemOption;

      printf("---------------------------------------------------------------\n"
             "  Euler Problems 1-%d are avaliable\n", NUM_PROBLEMS);
      getValidUserInt("  Select an Euler problem to solve: ", stdin, 1,
                      NUM_PROBLEMS, &problemOption);

      (*problems[problemOption-1])(stdin);
    } break;

    default :
      printf("---------------------------------------------------------------\n"
             "  Exit\n\n"
             "---------------------------------------------------------------\n"
            );
      break;
    }
  }

  return 0;
}
// -----------------------------------------------------------------------------
