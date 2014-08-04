#include <iostream>
#include "geogr_types.h"
//#include "RPF.h"
#include "adv_greedy_forwarding_v1.h"

using namespace std;
#define PHI 0
int main() {
  GFLink<int> a;
  GFLink<int> b = a.reverseLink();
  
  float res0 = weight(a);
  float res1 = weight(b);
  
  __ESBMC_assume(res0 <= PHI);
  __ESBMC_assert(res1 >= PHI, "violated");
  
  return 0;
}
