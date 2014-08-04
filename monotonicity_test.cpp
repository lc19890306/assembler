#include "stmt.h"

string monotonicity_test(weightFunction_t weightFunction, const string &pathLen, const string &dataType, const string &testType) {
  string res, varType;

  if (weightFunction.parc == 1) {
    res += "  ";
    varType = weightFunction.parType[0];
    varType = replaceDataType(varType, dataType);
    res += varType;
  }
  string returnType = weightFunction.returnType;
  string funcName = weightFunction.funcName;
  res += " ";
  res += "p_1";
  res += "(";
  res += pathLen;
  res += ")";
  res += ",";
  res += " ";
  res += "p_2";
  res += "(";
  res += pathLen;
  res += ")";
  res += ";";
  res += "\n";

  res += "\n";

  res += "  ";
  res += "createPath";
  res += "(";
  res += "p_1";
  res += ")";
  res += ";";
  res += "\n";

  res += "  ";
  res += "createPath";
  res += "(";
  res += "p_2";
  res += ")";
  res += ";";
  res += "\n";

  res += "\n";

  res += "  ";
  res += returnType;
  res += " ";
  res += "res_0";
  res += ",";
  res += " ";
  res += "res_1";
  res += ";";
  res += "\n";

  res += "  ";
  res += "res_0";
  res += " ";
  res += "=";
  res += " ";
  res += funcName;
  res += "(";
  res += "p_1";
  res += ")";
  res += ";";
  res += "\n";

  res += "  ";
  res += "res_1";
  res += " ";
  res += "=";
  res += " ";
  res += funcName;
  res += "(";
  if (testType == "right") {
    res += "p_1";
    res += "+";
    res += "p_2";
  }
  if (testType == "left") {
    res += "p_2";
    res += "+";
    res += "p_1";
  }
  res += ")";
  res += ";";
  res += "\n";

  res += "\n";

  res += "  ";
  res += "__";
  res += XXX;
  res += "_assert(";
  res += "res_1 >= res_0";
  res += ",";
  res += " ";
  if (testType == "right") {    
    res += "\"Right-monotonicity violated!\"";
  }
  if (testType == "left") {
    res += "\"Left-monotonicity violated!\"";
  }
  res += ")";
  res += ";";
  res += "\n";

  return res;
}










