/*Devam Desai
IIT2022035 Assignment 9 Program 1*/


#include <stdio.h>
int main(){
	float a,b,*point_a,*point_b;
	printf("Enter 2 numbers:");
	scanf("%f%f",&a,&b);
	point_b=&b,point_a=&a;
	printf("\nSum is : %.2f",*point_a+*point_b);
}