#ifndef __H_OPTIONS_
#define __H_OPTIONS_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cassert>

using namespace std;

class options {
 public:
  options() {}
  ~options() {}
  void add(const string &opt);
  void addFuncName(const string &opt);
  string getFuncName();
  void addPhi(const string &phi = "0");
  string getPhi();
  void addPathLen(const string &pathLen = "20");
  string getPathLen();
  void addDataType(const string &dataType = "int");
  string getDataType();
  bool exist(const string &opt);
 private:
  map<string, string> opts;
  //  string funcName;
 };
//#define __cplusplus_

#endif // __H_OPTIONS_
