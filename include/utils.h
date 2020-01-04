#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>

// -----------------------------------------------------------------------------
// Interface utilites
// -----------------------------------------------------------------------------
int getUserInt(char *userPrompt, int *input);

// -----------------------------------------------------------------------------
// Math utilities
// -----------------------------------------------------------------------------
int calculateGCD(int a, int b, int *result);
int calculateLCM(int a, int b, int *result);

#endif
