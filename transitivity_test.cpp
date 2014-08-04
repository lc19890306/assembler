#include "stmt.h"

string transitivity_test(weightFunction_t weightFunction) {
  string res;
  string returnType = weightFunction.returnType;
  string funcName = weightFunction.funcName;
  res += "  ";
  res += "const int num = 20;";
  res += "\n";
  res += "  ";
  res += "Link<int>  *path = createPath(num);";
  res += "\n";
  res += "  ";
  res += "Link<int> link = createLink(path[0].getStart(), path[num - 1].getEnd());";
  res += "\n";
  res += "  ";
res += "for (int i = 0; i < num - 1; ++i) {\n" \
"    __ESBMC_assume(weight(path[i]) <= PHI);\n" \
"  }\n" \
"  __ESBMC_assert(weight(link) <= PHI, \"Transitivity violated!\");";
 res += "\n";

  return res;
}
