#include "stmt.h"

string strict_order_test(weightFunction_t weightFunction) {
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


  res += "  ";
  res += varType;
  res += " ";
  res += "l_2";
  res += " ";
  res += "=";
  res += " ";
  res += "createLink(l_1.getStart());";
  res += "\n";

  res += "  ";
  res += returnType;
  res += " ";
  res += "w_1";
  res += " ";
  res += "=";
  res += " ";
  res += funcName;
  res += "(";
  res += "l_1";
  res += ");";
  res += "\n";

  res += "  ";
  res += returnType;
  res += " ";
  res += "w_2";
  res += " ";
  res += "=";
  res += " ";
  res += funcName;
  res += "(";
  res += "l_2";
  res += ");";
  res += "\n";

  res += "  __ESBMC_assume(l_1.getEnd() != l_2.getEnd());\n";
  res += "  __ESBMC_assert(w_1 != w_2, \"Strict order violated!\")\n";

  return res;
}
