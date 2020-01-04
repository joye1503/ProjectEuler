#ifndef EULER_H
#define EULER_H

#define NUM_PROBLEMS 2

// -----------------------------------------------------------------------------
// Solution code
// -----------------------------------------------------------------------------
int problem1(int a, int b, int limit, int *sum);
int problem2(int a, int limit, int *sum);

// -----------------------------------------------------------------------------
// Command line interfaces
// -----------------------------------------------------------------------------
typedef int funcPtr(void);
funcPtr problem1CL, problem2CL;

funcPtr *problems[NUM_PROBLEMS] = {
  problem1CL,
  problem2CL
};

#endif
