#ifndef __H_STROP_
#define __H_STROP_

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#include "options.h"
#include <cassert>

bool startswith(string str, string prefix);
vector<string> arrangeArgv(int argc, char **argv);
bool isLegal(string filename, vector<string> fileExt, string &source, unsigned &index);
string replaceFileExt(string filename, string source, unsigned index, string outputFormat);
vector<string> split(string &str,const char *c);
options getOpts(vector<string> argv);
string strip(const string &str, const string &target = " ");
string removeVarName(const string str);
string replaceDataType(const string &classType, const string &dataType = "int");
string replaceAll(const string &str, const string &substr, const string &target = "LINK_TYPE");

#endif // __H_STROP_
