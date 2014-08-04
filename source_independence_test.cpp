#include "stmt.h"

string source_independence_test(weightFunction_t weightFunction) {
  string res, varType;

  if (weightFunction.parc == 1) {
    res += "  ";
    varType = weightFunction.parType[0];
    res += varType;
  }
  string returnType = weightFunction.returnType;
  string funcName = weightFunction.funcName;
  res += " ";
  res += "l_1";
  res += " ";
  res += "=";
  res += " ";
  res += "createLink();";
  res += "\n";

  res += " ";
  res += "l_2";
  res += " ";
  res += "=";
  res += " ";
  res += "createLink();";
  res += "\n";

  res += "  Node<int> start_1 = l_1.getStart();\n";
  res += "  Node<int> end_1 = l_1.getEnd();\n";
  res += "  Node<int> src_1 = l_1.getSrc();\n";
  res += "  Node<int> start_2 = l_2.getStart();\n";
  res += "  Node<int> end_2 = l_2.getEnd();\n";
  res += "  Node<int> src_2 = l_2.getSrc();\n";

  res += "  __ESBMC_assume(start_1 == start_2);\n";
  res += "  __ESBMC_assume(end_1 == end_2);\n";
  res += "  __ESBMC_assume(src_1 != src_2);\n";

  res += "  float w_1 = weight(l_1);\n";
  res += "  float w_2 = weight(l_2);\n";

  res += "  __ESBMC_assert(w_1 == w_2, \"Source independence violated!\");\n";

  return res;
}
