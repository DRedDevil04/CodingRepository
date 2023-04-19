/*IIT2022035
Devam Desai Assignment 7 Program 1*/


#include <stdio.h>
void digit_sum(int);
int main(){
	int n;
	printf("Enter number:");
	scanf("%d",&n);
	if(n<0){
		n*=-1;
	}
	digit_sum(n);
	return 0;
}
void digit_sum(int n){
	static int sum=0;
	if(n==0){
		printf("\nSum of digits is:%d\n",sum);
	}
	else{
		sum+=(n%10);
	
		digit_sum(n/10);


	}
}
