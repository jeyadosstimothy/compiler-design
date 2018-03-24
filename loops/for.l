%{
	#include <bits/stdc++.h>
	using namespace std;
	#include "for.tab.h"
%}

%%

for 	yylval.str=strdup(yytext);return FOR ;
do		yylval.str=strdup(yytext);return DO ;
while	yylval.str=strdup(yytext);return WHILE ;
"(" 	yylval.str=strdup(yytext);return OP ;
";"		yylval.str=strdup(yytext);return SC ;
")"		yylval.str=strdup(yytext);return CL ;
"{"		yylval.str=strdup(yytext);return OP1 ;
"}"		yylval.str=strdup(yytext);return CL1 ;
[a-zA-Z 0-9+\-=*/<>!]*	yylval.str=strdup(yytext);return TEXT ;
[\n \t]+	;
. 		yylval.str=strdup(yytext);return UNR;

%%
