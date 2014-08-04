#ifndef __H_WEIGHTFUNCTION_
#define __H_WEIGHTFUNCTION_

#include <vector>
#include <string>

using namespace std;

typedef struct {
  string returnType;
  string funcName;
  int parc;
  vector<string> parType;
} weightFunction_t;

#endif // __H_WEIGHTFUNCTION_
