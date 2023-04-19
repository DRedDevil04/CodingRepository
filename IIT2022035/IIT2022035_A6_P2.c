/*Devam Desai
IIT2022035 Assignment 6 Program 2*/



#include <stdio.h>
void add(float,float);
void divide(float,float);
void multiply(float,float);
void subtract(float,float);
void modulo(int ,int);
void abs(float);
void pow(float,int);
void isPrime(int);

int main(){
	float num1,num2;
	char op;
	printf("\nWelcome to CALCULATOR\n");
	printf("\nOPERATOR CHART\nAddition: +\nSubtraction: -\nMultiplication: *\nDivision: /\nModulo: %\nPower: ^\nAbsolute value: |\nPrime Check: ?\n");
	printf("Enter the operator: \n");
	scanf("%c",&op);
	if(op=='?'||op=='|'){
		printf("\nEnter Number: \n");
		scanf("%f",&num1);
		(op=='?')?isPrime((int)num1):abs(num1);
	}
	else{
		printf("\nEnter Operand 1 and Operand 2: \n");
		scanf("%f%f",&num1,&num2);

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
		case '^':
			pow(num1,(int)num2);
			break;
		default:
			printf("\nEnter valid operator\n");
			break;

	}
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
void abs(float x){
	if(x<0){
		x*=-1;
	}
	printf("\nAbsolute value is %.3f\n",x);
}
void isPrime(int x){
	int flag=0;
	for(int i=2;i<=x/2;i++){
		if((x%i)==0){
			flag=1;
			break;
		}
		else{
			continue;
		}
	}
	if (flag==0){
		printf("\nNumber is prime\n");
	}
	else{
		printf("\nNumber is not prime\n");
	}
}
void pow(float x,int y){
	float val=1.0;

	if(y<0){
		
		while(y++){
			val=val/x;
		}
		
	}
	else{
		while(y--){
			val*=x;
		}
	}
	
	printf("\nValue is %.3f",val);


}

