%{
/**/
#include <iostream>
#include <string>
#include <stack>

#include "scanner.h"

using namespace std;

stack<string> tagStack;
stack<string> dataStack;

int add_word(int type, char * word);
int lookup_word(char * word);
%}
%%

[\t ]+              /* ignore whitespace */ ;

(<[a-zA-Z]+>)                                   { tagStack.push(strdup(yytext)); return OPEN_TAG; }
(<\/[a-zA-Z]+>)                                 { tagStack.push(strdup(yytext)); return CLOSE_TAG; }
([a-zA-Z]+)                                     { dataStack.push(strdup(yytext)); return WORD; }
(-?[0-9]+((.)[0-9]+)?)                          { dataStack.push(strdup(yytext)); return NUMBER; }
(([0-9]|[a-zA-Z])+('([0-9]|[a-zA-Z])+)+)         { dataStack.push(strdup(yytext)); return APOSTROPHIZED; }
(([0-9]|[a-zA-Z])+(-([0-9]|[a-zA-Z]|')+)+)      { dataStack.push(strdup(yytext)); return HYPHENATED; }
(.)                                             { dataStack.push(strdup(yytext)); return PUNCTUATION; }
\n                                              { return NEW_LINE; }

%%

TOKEN getToken(void) { 
  return (TOKEN)yylex(); 
}
