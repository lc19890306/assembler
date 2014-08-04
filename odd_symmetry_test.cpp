#include "stmt.h"

string odd_symmetry_test(weightFunction_t weightFunction) {
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
  res += "reverseLink(";
  res += "l_1";
  res += ");";
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

  res += "  ";
  res += "__";
  res += XXX;
  res += "_assume(";
  res += "w_1";
  res += " ";
  res += "<=";
  res += " ";
  res += "PHI";
  res += ");";
  res += "\n";

  res += "  ";
  res += "__";
  res += XXX;
  res += "_assert(";
  res += "w_2";
  res += " ";
  res += ">=";
  res += " ";
  res += "PHI";
  res += ",";
  res += " ";
  res += "\"Odd symmetry violated!\");";
  res += "\n";

  return res;
}
