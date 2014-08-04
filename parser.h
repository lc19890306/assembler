#ifndef __H_PARSER_
#define __H_PARSER_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "weightFunction.h"
#include "strop.h"

weightFunction_t parse(string func, string funcName = "weight") {
  weightFunction_t res;

  string thisFunc = func;
  string::size_type pos = thisFunc.find(funcName);
  string returnType = thisFunc.substr(0, pos - 1);
  //  cout << returnType << endl;

  string::size_type start = thisFunc.find_first_of("(");
  string realName = thisFunc.substr(pos, start - pos);
  realName = strip(realName);
  assert(realName == funcName && "target function name should be legal");

  string::size_type end = thisFunc.find_last_of(")");
  thisFunc = thisFunc.substr(start + 1, end - start - 1);
  vector<string> parType = split(thisFunc, ",");

  for (vector<string>::iterator it = parType.begin(); it != parType.end(); ++it) {
    *it = strip(*it);
    *it = strip(*it, "const");
    *it = strip(*it);
    //    cout << *it << endl;
    *it = removeVarName(*it);
    //    cout << *it << endl;
  }

  res.funcName = funcName;
  res.returnType = returnType;
  res.parc = parType.size();
  res.parType = parType;

  return res;
}

#endif // __H_PARSER_
