%token IF ELSE OP CL OB CB TEXT SC UNR
%{
	#include<stdio.h>
	extern char *yytext;
	int yyerror(char *s);
	int yylex();
%}
%%
s:	TEXT {printf("%s",yytext);}| IF {printf("%s",yytext);} OP {printf("%s",yytext);} TEXT {printf("%s",yytext);} CL {printf("%s",yytext);} OB {printf("%s",yytext);} s CB {printf("%s",yytext);} t	| ;
t: 	ELSE {printf("%s",yytext);} OB {printf("%s",yytext);} s CB {printf("%s",yytext);} s | {printf("else{}\n");} s;
%%
#include "lex.yy.c"
int yyerror(char *s)
{
	printf("%s",s);
}
int main(void)
{
	yyparse();
}
