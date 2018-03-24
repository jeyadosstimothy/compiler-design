%{
	#include <bits/stdc++.h>
	#include "syntree.tab.h"
%}

%%

[a-zA-Z_][a-zA-Z_0-9]* 	yylval.str=strdup(yytext);return ID ;
([0-9]*\.?[0-9]*)|(\".*?\")|(\'.\')	yylval.str=strdup(yytext);return VAL ;
";"		yylval.str=strdup(yytext);return SC ;
"+"		yylval.str=strdup(yytext);return PL ;
"-"		yylval.str=strdup(yytext);return MI ;
"*"		yylval.str=strdup(yytext);return MUL ;
"/"		yylval.str=strdup(yytext);return DIV ;
"="		yylval.str=strdup(yytext);return EQ ;
"("		yylval.str=strdup(yytext);return OP ;
")"		yylval.str=strdup(yytext);return CL ;
"^"		yylval.str=strdup(yytext);return POW ;
[\n \t]+	;
. 		yylval.str=strdup(yytext);return UNR;

%%