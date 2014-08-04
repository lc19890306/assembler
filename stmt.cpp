#include "stmt.h"

#include <fstream>

void modifyFuncHeader(const string funcHeader, const string header, const weightFunction_t &weightFunction) {
  string newFuncHeader = funcHeader + ".h";
  string includeHeader = "#include \"" + header + "\"";
  ifstream fin;
  ofstream fout;

  fin.open(funcHeader.c_str());
  fout.open(newFuncHeader.c_str());

  string str, varType;
  int i = 0;
  if (weightFunction.parc == 1) {
    varType = weightFunction.parType[0];
  }

  while (getline(fin, str))  {
    str = replaceAll(str, varType);
    fout << str << endl;
    if (i < 3) {
      ++i;
    }
    if (i == 3) {
      ++i;
      fout << includeHeader << endl;
    }
  }

  fout.close();
  fin.close();
}
