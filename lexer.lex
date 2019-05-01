%option noyywrap
%option noinput
%option nounput

%{
    #include <iostream>
    #include <string>
    #include <vector>
    
    #include "vector.hpp"
    #include "parser.tab.hpp"

    extern void yyerror(std::string error);
%}

%%

"vector"                { return vector_token; }
"print"                 { return print_token; }
"transformation"        { return transform_token; }
"rotate"                { return rotate_token; }
"scale"                 { return scale_token; }
\$[a-z]+[0-9]*          { yylval.id = new std::string(yytext); return t_id_token; }
[a-zA-Z]+[0-9]*         { yylval.id = new std::string(yytext); return id_token; }
[-]?[0-9]+([.][0-9]+)?  { yylval.num = atof(yytext); return num_token; }
[+*=;.,)(\]\[$-]        { return *yytext; }
[ \t]                   { }
.                       { yyerror("Lexical error."); }

%%
