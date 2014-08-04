#include <stdio.h>
#include "wcett.h"

#include "lsdvfunctions.h"

int main() {
  initialize();
  Path<int> p_1(5), p_2(5), p_3(5);

  createPath(p_1);
  createPath(p_2);
  createPath(p_3);

  float res_0, res_1, res_2, res_3;
  res_0 = weight(p_1);
  res_1 = weight(p_2);
  res_2 = weight(p_1+p_3);
  res_3 = weight(p_2+p_3);

  __ESBMC_assume(res_0 >= res_1);
  __ESBMC_assert(res_2 >= res_3, "Right-isotonicity violated!");


  return 0;
}
