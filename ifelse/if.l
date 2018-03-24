%%
if  					return IF ;
else 					return ELSE ;
"(" 					return OP ;
")"					    return CL ;
"{"					    return OB ;
"}"					    return CB ;
[\n \t]+				printf("%s",yytext);
[a-zA-Z0-9_+\-=*/%;<>=!]+		return TEXT ;
. 					    return UNR ;
%%
