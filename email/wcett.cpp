#include "wcett.h"

int main() {
  Path<int> a(10), b(10), c(10);
  
  createPath(a);
  createPath(b);
  createPath(c);

  float res0, res1, res2, res3;
  res0 = weight(a);
  res1 = weight(b);
  res2 = weight(a+c);
  res3 = weight(b+c);
  
  __ESBMC_assume(res0 >= res1);
  __ESBMC_assert(res2 >= res3, "Right-isotonicity violated!");
          
  return 0;
}
