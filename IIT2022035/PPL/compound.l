%{
	#include<stdio.h>
	int flag=0;
%}

%%
and |
or |
but |
nevertheless |
then |
if |
because {flag=1;}
. ;
%%
int main()
{
	printf("Enter the String : ");
	yylex();
	if(flag==1)
	{
	printf("Sentence is Compound.");
	}
	else
	{
	printf("Sentence is Simple.");
	}
	return 0;
}
int yywrap(){
return 1;
}