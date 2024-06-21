%{
	#include<stdio.h>
	int wc=0,lc=0,cc=0,sc=0;
%}

%%
[a-zA-Z]+ {wc++; cc+=yyleng;}
[\n]+ {lc++; cc+=yyleng;}
[ ]+ {sc++; cc+=yyleng;}
%%
int main()
{
	printf("Enter the String : ");
	yylex();
	printf("word count :%d\n",wc);
	printf("char count: %d\n", cc);
	printf("line count :%d\n",lc);
	printf("space count :%d\n",sc);
	return 0;
}

int yywrap(){
return 1;
}