%{
	#include<stdio.h>
	int com=0;
%}

%%
"//"[a-zA-Z0-9 \t]*"\n" {com++;}
"/*"[a-zA-Z0-9 \n\t]*"*/" {com++;}
%%
int main(int argc, char* argv[])
{
	if(argc==2)
	{
	yyin = fopen(argv[1], "r");
	}else {
	printf("Enter the input: ");
	yyin=stdin;
	}
	yylex();
	printf("No. of comment lines are: %d\n",com);
	return 0;
}
int yywrap()
{
return 1;
}