#ifndef __H_ANALYZER_
#define __H_ANALYZER_

#include "weightFunction.h"
#include "scanner.h"
#include "parser.h"

weightFunction_t analyze(const char *filename, string funcName = "weight") {
  weightFunction_t res;
  string func = scan(filename, funcName);
  //  cout << funcName << endl;
  res = parse(func, funcName);

  return res;
}

#endif // __H_ANALYZER_
