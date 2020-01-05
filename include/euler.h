#ifndef EULER_H
#define EULER_H
#include <math.h>

#define NUM_PROBLEMS 3

// -----------------------------------------------------------------------------
// Solution code
// -----------------------------------------------------------------------------
int problem1(int a, int b, int limit, int *sum);
int problem2(int a, int limit, int *sum);
int problem3(long number, long *factor);

// -----------------------------------------------------------------------------
// Command line interfaces
// -----------------------------------------------------------------------------
typedef int funcPtr(void);
funcPtr problem1CL, problem2CL, problem3CL;

funcPtr *problems[NUM_PROBLEMS] = {
  problem1CL,
  problem2CL,
  problem3CL
};

#endif
