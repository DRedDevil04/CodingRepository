%{
	#include<stdio.h>
	int v=0,c=0;
%}

%%
[aeiouAEIOU] {v++;}
[^aeiouAEIOU \n] {c++;}
%%
int main()
{
	printf("Enter the String: ");
	yylex();
	printf("\nNo. of Vowels: %d\n",v);
	printf("\nNo. of Consonants: %d\n",c);
	return 0;
}
int yywrap()
{
return 1;
}