#include "scanner.h"

#define MAX 100

string scan(const char *filename, string funcName) {
  string res;
  bool found = false;
  char buffer[MAX];
  ifstream fin(filename);
  int i = 1;
  string::size_type pos;
  while(!fin.eof()) {
    fin.getline(buffer, MAX);
    //    cout.width(2); cout << right << i++ << buffer << endl;
    res = buffer;
    pos = res.find(funcName);

    if (pos != res.npos/* && !fin.eof()*/) {
      //      cout << "Line: " << i << " " << res << endl;
      found = true;
      break;
    }
    ++i;
  }
  assert(found == true && "target function should exist in this file");

  return res;
}
