#include "testingProgram.h"

void testingProgram::push_back(string stmt) {
  program.push_back(stmt);
}

void testingProgram::print() {
  for (int i = 0; i < program.size(); ++i) {
    cout << program[i];
    fout << program[i];
  }
}

