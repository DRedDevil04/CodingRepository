%{
	#include<stdio.h>
%}

%%
if |
else |
printf {printf("\n%s is a keyword.\n",yytext);}
[0-9]+ {printf("\n%s is a number.\n",yytext);}
[a-zA-Z]+ {printf("\n%s is a word.\n",yytext);}
.|\n {ECHO;}
%%
int main()
{
	printf("Enter the string: ");
	yylex();
	return 0;
}
int yywrap(){
return 1;
}