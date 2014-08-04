#include "main.h"

int main(int argc, char **argv) {
  string header, filename;
  
  vector<string> newArgv = arrangeArgv(argc, argv);
  string thisProgram = newArgv[0];

  if (argc == 1) {
    help(thisProgram, NOINPUT);
    return 1;
  }

  options opts = getOpts(newArgv);

  if (opts.exist("-v")) {
    printVersion();
    return 2;
  }

  if (opts.exist("-h")) {
    help(thisProgram, USAGE);
    return 3;
  }

  if (newArgv[1].empty()) {
    help(thisProgram, NOINPUT);
    return 1;
  }

  string outputFormat;
  if (opts.exist("-C")) {
    outputFormat = "c";
  }
  else {
    outputFormat = "cpp";
  }

  vector<string> fileExt;
  string source;
  unsigned index;

  fileExt.push_back("hpp");
  fileExt.push_back("hh");
  fileExt.push_back("h");

  header = newArgv[1];

  if (isLegal(header, fileExt, source, index)) {
    filename = replaceFileExt(header, source, index, outputFormat);
  }
  else {
    help(thisProgram, WRONGINPUT);
    return 4;
  }

  testingProgram program(filename);

  if (outputFormat == "cpp") {
    program.push_back(__H_IOSTREAM_);
    program.push_back("\n");
    program.push_back(__NAMESPACE_);
    program.push_back("\n");
  }
  else {
    program.push_back(__H_STDIO_);
  }

  string funcName = opts.getFuncName();
  weightFunction_t weightFunction = analyze(header.c_str(), funcName);

  string phi = opts.getPhi();

  //  program.push_back(__H_CMATH_);
  program.push_back("#include \"" + header + "\"\n\n");

  if (opts.exist("--odd-symmetry")) {
    //    program.push_back("\n");
    modifyFuncHeader("geogr_functions", header, weightFunction);
    program.push_back(__H_GEOGR_FUNCS_);
    program.push_back("\n");
    program.push_back("#define PHI " + phi + "\n");
    program.push_back("\n");
    program.push_back(__MAIN_);
    program.push_back(__INITIALIZE_);
    program.push_back(odd_symmetry_test(weightFunction));
    program.push_back("\n");
  }

  if (opts.exist("--transitivity")) {
    modifyFuncHeader("geogr_functions", header, weightFunction);
    program.push_back(__H_GEOGR_FUNCS_);
    program.push_back("\n");
    program.push_back("#define PHI " + phi + "\n");
    program.push_back("\n");
    program.push_back(__MAIN_);
    program.push_back(__INITIALIZE_);
    program.push_back(transitivity_test(weightFunction));
    program.push_back("\n");
  }

  if (opts.exist("--strict-order")) {
    modifyFuncHeader("geogr_functions", header, weightFunction);
    program.push_back(__H_GEOGR_FUNCS_);
    program.push_back("\n");
    program.push_back("#define PHI " + phi + "\n");
    program.push_back("\n");
    program.push_back(__MAIN_);
    program.push_back(__INITIALIZE_);
    program.push_back(strict_order_test(weightFunction));
    program.push_back("\n");
  }

  if (opts.exist("--source-independence")) {
    modifyFuncHeader("geogr_functions", header, weightFunction);
    program.push_back(__H_GEOGR_FUNCS_);
    program.push_back("\n");
    program.push_back("#define PHI " + phi + "\n");
    program.push_back("\n");
    program.push_back(__MAIN_);
    program.push_back(__INITIALIZE_);
    program.push_back(source_independence_test(weightFunction));
    program.push_back("\n");
  }

  string pathLen = opts.getPathLen();
  string dataType = opts.getDataType();

  if (opts.exist("--right-isotonicity")) {
    modifyFuncHeader("lsdv_functions", header, weightFunction);
    program.push_back(__H_LSDV_FUNCS_);
    program.push_back("\n");
    program.push_back(__MAIN_);
    program.push_back(isotonicity_test(weightFunction, pathLen, dataType, "right"));
    program.push_back("\n");
  }

  if (opts.exist("--left-isotonicity")) {
    modifyFuncHeader("lsdv_functions", header, weightFunction);
    program.push_back(__H_LSDV_FUNCS_);
    program.push_back("\n");
    program.push_back(__MAIN_);
    program.push_back(isotonicity_test(weightFunction, pathLen, dataType));
    program.push_back("\n");
  }

  if (opts.exist("--right-monotonicity")) {
    modifyFuncHeader("lsdv_functions", header, weightFunction);
    program.push_back(__H_LSDV_FUNCS_);
    program.push_back("\n");
    program.push_back(__MAIN_);
    program.push_back(monotonicity_test(weightFunction, pathLen, dataType, "right"));
    program.push_back("\n");
  }

  if (opts.exist("--left-monotonicity")) {
    modifyFuncHeader("lsdv_functions", header, weightFunction);
    program.push_back(__H_LSDV_FUNCS_);
    program.push_back("\n");
    program.push_back(__MAIN_);
    program.push_back(monotonicity_test(weightFunction, pathLen, dataType));
    program.push_back("\n");
  }

  program.push_back(__RETURN_);
  program.push_back(__END_);

  program.print();

  return 0;
}
