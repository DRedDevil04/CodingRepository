#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

float compute(char op,float op1, float op2){
	float ans;
		switch (op){
			case '+':
				ans=op1+op2;
				break;
			case '-':
				ans=op1-op2;
				break;
			case '*':
				ans=op2*op1;
				break;
			default:
				if(op1==0){
					printf("\nDivisor becomes 0. So exited.\n");
					exit(-1);
				}
				else{
					ans=op1/op2;
					break;
				}
			}
	return ans;
}

int main(int argc, char*argv[]){
	FILE* fptr=fopen(argv[1],"r");
	char s[100];
	stack *calc,*oper,*fin;
	create_stack(&calc);
	create_stack(&oper);
	create_stack(&fin);
	int i=0;
	while((s[i]=fgetc(fptr))!=EOF || i!=98){
		
		i++;
	}
	s[i]='\0';

	for(int i=0;s[i]!='\0';i++){
		if(s[i]==' '){
			continue;
		}
		if(s[i]-'0'<=9 && s[i]-'0'>=0){

			int sum=s[i]-'0';
			// printf("SUM: %d\n",sum);
			i++;
			// printf("SI IS %d\n",s[i]-'0');
			while(s[i]!='\0' && ((s[i]-'0')<=9 && (s[i]-'0')>=0) ){
				sum*=10;
				sum+=(s[i]-'0');
				s[i]=fgetc(fptr);
				i++;
				// printf("SUM: %d",sum);
			}
			push(&calc,(float)sum);
			continue;
		}
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
			
			push(&oper,s[i]);
		}
		
	}
	while(calc!=NULL){
		push(&fin,pop(&calc));
	}
	while(oper!=NULL){
		float ans=compute(pop(&oper),pop(&fin),pop(&fin));
		push(&fin,ans);
	}
	printf("\nFinal Answer is: %.2f",pop(&fin));

	return 0;
}