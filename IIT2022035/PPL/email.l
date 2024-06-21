%{
int flag=0;

%}

%%

"\n" {return 0;}
[^a-zA-Z] {return 0;}
[a-zA-Z][a-zA-Z0-9]+[@][a-zA-Z]+[\.]"com" {flag=1;}
. ECHO;
%%
int main(){
	printf("\nEnter the email: \n");
	yylex();

	if(flag==0){
		printf("\nINVALID EMAIL");
	}
	else{
		printf("\nVALID EMAIL\n");
	}
	return 0;
}

int yywrap(){
	return 1;
}
