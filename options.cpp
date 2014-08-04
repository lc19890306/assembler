#include "options.h"

#define MAX 80

void options::add(const string &opt) {
  if (opts.find(opt) == opts.end()) {
    opts[opt] = "true";
  }
}

void options::addFuncName(const string &funcName) {
  string key = "--funcname";
  if (opts.find(key) == opts.end()) {
    opts[key] = funcName;
  }
}

string options::getFuncName() {
  string res;
  string key = "--funcname";
  if (opts.find(key) != opts.end()) {
    res = opts[key];
  }
  else {
    res = "weight";
  }

  return res;
}

void options::addPhi(const string &phi) {
  string key = "--phi";
  if (opts.find(key) == opts.end()) {
    opts[key] = phi;
  }
}

string options::getPhi() {
  string res;
  string key = "--phi";
  if (opts.find(key) != opts.end()) {
    string realValue = opts[key];
    int val = atoi(realValue.c_str());
    char buffer[MAX];
    sprintf(buffer, "%d", val);
    string value = buffer;
    assert(realValue == value && "the value of phi should be legal");
    res = realValue;
  }
  else {
    res = "0";
  }

  return res;
}

/*
int options::getPhi() {
  int res;
  string key = "--phi";
  if (opts.find(key) != opts.end()) {
    string realValue = opts[key];
    res = atoi(realValue.c_str());
    char buffer[MAX];
    sprintf(buffer, "%d", res);
    string value = buffer;
    assert(realValue == value && "the value of phi should be legal");
  }
  else {
    res = 0;
  }

  return res;
}
*/

void options::addPathLen(const string &pathLen) {
  string key = "--pathlen";
  if (opts.find(key) == opts.end()) {
    opts[key] = pathLen;
  }
}

string options::getPathLen() {
  string res;
  string key = "--pathlen";
  if (opts.find(key) != opts.end()) {
    string realValue = opts[key];
    int val = atoi(realValue.c_str());
    char buffer[MAX];
    sprintf(buffer, "%d", val);
    string value = buffer;
    assert(realValue == value && "the length of path should be legal");
    assert(val > 0 && "the length of path should be greater than 0");
    res = realValue;
  }
  else {
    res = "20";
  }

  return res;
}

void options::addDataType(const string &dataType) {
  string key = "--datatype";
  set<string> dataTypes;
  set<string>::iterator it;
  dataTypes.insert("int");
  dataTypes.insert("float");

  if (opts.find(key) == opts.end()) {
    it = dataTypes.find(dataType);
    if (it != dataTypes.end()) {
      opts[key] = dataType;
    }
    else {
      cerr << "Data type \"" << dataType << "\" provided is not supported! \"int\" will be used instead\n";
    }
  }
}

string options::getDataType() {
  string res;

  string key = "--datatype";
  if (opts.find(key) != opts.end()) {
    res = opts[key];
  }
  else {
    res = "int";
  }

  return res;
}

bool options::exist(const string &opt) {
  bool res;
  if (opts.find(opt) != opts.end()) {
    res = true;
  }
  else {
    res = false;
  }

  return res;
}
