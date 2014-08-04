#ifndef __H_TESTINGPROGRAM_
#define __H_TESTINGPROGRAM_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//#include "options.h"

using namespace std;

class testingProgram {
 public: 
  testingProgram(string filename) {
    fout.open(filename.c_str());
  }
  ~testingProgram() {
    fout.close();
  }
  void push_back(string stmt);
  void print();
 private:
  vector<string> program;
  ofstream fout;
};

#endif // __H_TESTINGPROGRAM_
