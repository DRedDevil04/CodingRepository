/*Devam Desai
IIT2022035 Assignment 10 Program 1*/


#include <stdio.h>
#include <stdlib.h>
int main(){
	int *arr,n;
	printf("Enter number of values:");
	scanf("%d",&n);
	arr=(int *)calloc(n,sizeof(int));
	int sum=0;
	for(int i=0;i<n;i++){
		int num;
		printf("\nEnter number %d:",i+1);
		scanf("%d",&num);
		*(arr+i)=num;
	}
	for(int i=0;i<n;i++){
		sum+=*(arr+i);
	}
	printf("\nSum is %d\n",sum);
	free(arr);
	return 0;
}