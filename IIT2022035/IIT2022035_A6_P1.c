/*Devam Desai
IIT2022035 Assignment 6 Program 1*/



#include <stdio.h>
void add(float,float);
void divide(float,float);
void multiply(float,float);
void subtract(float,float);
void modulo(int ,int);

int main(){
	float num1,num2;
	char op;
	printf("Enter the first operand,operator,second operand: \n");
	scanf("%f %c%f",&num1,&op,&num2);
	switch (op){
		case '+':
			add(num1,num2);
			break;
		case '-':
			subtract(num1,num2);
			break;
		case '*':
			multiply(num1,num2);
			break;
		case '/':
			divide(num1,num2);
			break;
		case '%':
			modulo((int)num1,(int)num2);
			break;
		default:
			printf("\nEnter valid operator\n");
			break;

	}
	return 0;

}
void add(float x,float y){ //prints sum
		printf("\nSum is %.2f\n",x+y);
	}
void subtract(float x,float y){ //prints subtracted value
		printf("\nSubtracted value is %.2f\n",x-y);
	}
void multiply(float x,float y){ //prints product
		printf("\nProduct is %.2f\n",x*y);
	}
void divide(float x,float y){ //prints quotient
	if(y==0){
		printf("\nSecond operand cannot be zero in case of division\n");
	}
	else{
		printf("\nQuotient is %.2f\n",x/y);
	}
	
	}
void modulo(int x, int y){
		(x<y)?printf("\nSecond number cant be bigger for remainder\n"):printf("\nRemainder is %d\n",x%y);
}
