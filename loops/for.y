%{
	#include<bits/stdc++.h>
	using namespace std;
	int yylex();	
	void yyerror(char *s);
	string s;
	deque<int> start,onemore;
	int x;
%}

%token <str> FOR OP CL OP1 CL1 TEXT SC UNR DO WHILE

%union{
	char *str;
}

%type <str> s stmt for dwhile

%%
ss: 	s {cout<<s<<endl;}
s:		for s | stmt s | dwhile s| {};
for:	FOR OP TEXT SC TEXT SC TEXT CL OP1 {s=s+$3+";\nwhile("+$5+")"+$9+"\n";} s CL1 {s=s+$7+";\n"+$12;};
stmt:	TEXT SC {s=s+$1+$2;};
dwhile: DO OP1 
			{
				onemore.push_back(s.length());
				s=s+"\nwhile(";
				start.push_back(s.length());
			} 
			s CL1 WHILE OP TEXT CL SC 
			{
				x=start.back()+s.substr(start.back()).length();
				s.insert(onemore.back(),s.substr(start.back()));
				onemore.pop_back();
				start.pop_back();
				start.push_back(x);
				s.insert(start.back(),strcat($8,"){\n"));
				s=s+"\n}";
				start.pop_back();
			};
%%

void yyerror(char *s)
{
	printf("%s\n",s);
}
int yywrap()
{
	return 1;
}
int main(void)
{
	yyparse();
}