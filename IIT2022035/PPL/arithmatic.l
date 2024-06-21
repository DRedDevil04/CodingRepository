%{
	#include<stdio.h>
	#include<string.h>
	int i=0, o=0,k,flag=0;
	char id[10][10],op[10][10];
%}

%%
[0-9]+ {flag++; strcpy(id[i], yytext); i++;}
[+*] {flag--; strcpy(op[o], yytext); o++;}
.|\n {return 0;}
%%
int main()
{
	printf("Enter the expression: ");
	yylex();
	if(flag!=1){
	printf("Invalid Expression.");
	}else {
	printf("Valid expresion.\n");
	printf("Operators are:\n");
	for(k=0;k<o;k++){
	printf("%s\t",op[k]);
	}
	printf("\nOperands are:\n");
	for(k=0;k<i;k++){
	printf("%s\t",id[k]);
	}
	}
	return 0;
}
int yywrap()
{
return 1;
}