%{
	#include<stdio.h>
%}

%%
[A-Z]+[ \t\n] {printf("%s\n",yytext);}
. ;
%%
int main()
{
	printf("Enter the String: ");
	yylex();
	return 0;
}
int yywrap()
{
	return 1;
}