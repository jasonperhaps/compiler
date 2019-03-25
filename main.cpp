#include <iostream>
#include "node.h"

using namespace std;

extern NBlock *programBlock;
extern int yyparse();
extern int yylex();
extern FILE * yyin;

int main(int argc, char **argv) {
  ++argv, --argc;
  if (argc > 0) 
    yyin = fopen(argv[0], "r");
  else
    yyin = stdin;
  
  yyparse();
  std::cout << programBlock << std::endl;

  //CodeGenContext context;
  //context.generateCode(*programBlock);
  //context.runCode();
  
  return 0;
}

