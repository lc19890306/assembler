#include <iostream>

using namespace std;

#include "RPF.h"

#include "geogr_functions.h"

#define PHI 0

int main() {
  initialize();
  Link<int> l_1 = createLink();
  Link<int> l_2 = reverseLink(l_1);
  float w_1 = weight(l_1);
  float w_2 = weight(l_2);
  __ESBMC_assume(w_1 <= PHI);
  __ESBMC_assert(w_2 >= PHI, "Odd symmetry violated!");

  return 0;
}
