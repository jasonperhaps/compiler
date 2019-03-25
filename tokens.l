%{
#include <string>
#include "node.h"
#include "parser.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
extern "C" int yywrap() {  }
%}

%%
[ \t\n]                     ;
[a-zA-Z_][a-zA-Z0-9_]*      {printf("%s\t -- TIDENTIFIER\t TOKEN_ID is %d\n", yytext, TIDENTIFIER); SAVE_TOKEN; return TIDENTIFIER;}
[0-9]+"."[0-9]*             {printf("%s\t -- TDOUBLE\t TOKEN_ID is %d\n", yytext, TDOUBLE); SAVE_TOKEN; return TDOUBLE;} 
[0-9]+                      {printf("%s\t -- TINTEGER\t TOKEN_ID is %d\n", yytext, TINTEGER ); SAVE_TOKEN; return TINTEGER;} 
"="                         {printf("%s\t -- TEQUAL\t TOKEN_ID is %d\n", yytext, TOKEN(TEQUAL) ); SAVE_TOKEN; return TOKEN(TEQUAL);  }  
"=="                        {printf("%s\t -- TCEQ\t TOKEN_ID is %d\n", yytext, TOKEN(TCEQ)   ); SAVE_TOKEN;   return TOKEN(TCEQ);    }
"!="                        {printf("%s\t -- TCNE\t TOKEN_ID is %d\n", yytext, TOKEN(TCNE)   ); SAVE_TOKEN;   return TOKEN(TCNE);    }
"<"                         {printf("%s\t -- TCLT\t TOKEN_ID is %d\n", yytext, TOKEN(TCLT)   ); SAVE_TOKEN;   return TOKEN(TCLT);    }
"<="                        {printf("%s\t -- TCLE\t TOKEN_ID is %d\n", yytext, TOKEN(TCLE)   ); SAVE_TOKEN;   return TOKEN(TCLE);    }
">"                         {printf("%s\t -- TCGT\t TOKEN_ID is %d\n", yytext, TOKEN(TCGT)   ); SAVE_TOKEN;   return TOKEN(TCGT);    }
">="                        {printf("%s\t -- TCGE\t TOKEN_ID is %d\n", yytext, TOKEN(TCGE)   ); SAVE_TOKEN;   return TOKEN(TCGE);    }
"("                         {printf("%s\t -- TLPAREN\t TOKEN_ID is %d\n", yytext, TOKEN(TLPAREN)); SAVE_TOKEN;return TOKEN(TLPAREN); }
")"                         {printf("%s\t -- TRPAREN\t TOKEN_ID is %d\n", yytext, TOKEN(TRPAREN)); SAVE_TOKEN;return TOKEN(TRPAREN); }
"{"                         {printf("%s\t -- TLBRACE\t TOKEN_ID is %d\n", yytext, TOKEN(TLBRACE)); SAVE_TOKEN;return TOKEN(TLBRACE); }
"}"                         {printf("%s\t -- TRBRACE\t TOKEN_ID is %d\n", yytext, TOKEN(TRBRACE)); SAVE_TOKEN;return TOKEN(TRBRACE); }
"."                         {printf("%s\t -- TDOT\t TOKEN_ID is %d\n", yytext, TOKEN(TDOT)   ); SAVE_TOKEN;   return TOKEN(TDOT);    }
","                         {printf("%s\t -- TCOMMA\t TOKEN_ID is %d\n", yytext, TOKEN(TCOMMA) ); SAVE_TOKEN; return TOKEN(TCOMMA);  }
"+"                         {printf("%s\t -- TPLUS\t TOKEN_ID is %d\n", yytext, TOKEN(TPLUS)  ); SAVE_TOKEN;  return TOKEN(TPLUS);   }
"-"                         {printf("%s\t -- TMINUS\t TOKEN_ID is %d\n", yytext, TOKEN(TMINUS) ); SAVE_TOKEN; return TOKEN(TMINUS);  }
"*"                         {printf("%s\t -- TMUL\t TOKEN_ID is %d\n", yytext, TOKEN(TMUL)   ); SAVE_TOKEN;   return TOKEN(TMUL);    }
"/"                         {printf("%s\t -- TDIV\t TOKEN_ID is %d\n", yytext, TOKEN(TDIV)   ); SAVE_TOKEN;   return TOKEN(TDIV);    }
.                           {printf("Unknown token!\n"); yyterminate();}
%%
