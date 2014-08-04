#ifndef __H_HELP_
#define __H_HELP_

#include "errno.h"

void help(string thisProgram, error_t error) {
  switch (error) {
  case NOINPUT:
    cout << thisProgram << ": fatal error: no input files" << endl;
    cout << "testing program assembling teminated." << endl;
    break;
  case WRONGINPUT:
    cout << thisProgram << ": fatal error: wrong input file type: .h, .hh, or .hpp file is needed" << endl;
    cout << "testing program assembling teminated." << endl;
    break;
  case USAGE:
    cout << "Usage:" << endl;
    break;
    //  default:
  }
}

#endif // __H_HELP_
