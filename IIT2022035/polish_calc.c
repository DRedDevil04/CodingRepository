#include <stdio.h>
#include <stdlib.h>
#include "adt.h"

float compute(char op,float op1, float op2){
	printf("%.2f %c %.2f\n",op1,op,op2);
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
	
	int i=0;
	while((s[i]=fgetc(fptr))!='#' || i>=98){
		
		i++;
	}

	s[i]='\0';
	i--;
	
	int f=0;
	for(;i>=0;i--){
		
		if(s[i]==' '){
			continue;
		}
		if(s[i]-'0'<=9 && s[i]-'0'>=0){

			int sum=s[i]-'0';
			
			i--;
			
			int q=1;
			while(s[i]!='\0' && ((s[i]-'0')<=9 && (s[i]-'0')>=0) ){
				
				q*=10;
				sum+=(s[i]-'0')*q;
				
				i--;
				
				
			}
			i++;
			
			push(&calc,(float)sum);
			continue;
		}
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
			
			float ans=compute(s[i],pop(&calc),pop(&calc));
			push(&calc,ans);
		}

		
	}
	
	// while(calc!=NULL){
	// 	push(&fin,pop(&calc));
	// }
	// while(oper!=NULL){
	// 	float ans=compute(pop(&oper),pop(&calc),pop(&calc));
	// 	push(&calc,ans);
	// }
	printf("\nFinal Answer is: %.2f",pop(&calc));

	return 0;
}