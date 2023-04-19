/*Devam Desai
IIT2022035 Assignment 10 Program 2*/


#include <stdio.h>
#include <stdlib.h>
int main(){
	int *arr,n;
	printf("Enter number of elements of array:");
	scanf("%d",&n);
	arr=(int *)calloc(n,sizeof(int));
	int sum=0;
	for(int i=0;i<n;i++){
		int num;
		printf("\nEnter number %d for array:",i+1);
		scanf("%d",&num);
		*(arr+i)=num;
	}
	int search_num;
	printf("\nEnter number you want to search:");
	scanf("%d",&search_num);
	for(int i=0;i<n;i++){
		if(search_num==*(arr+i)){
			printf("Number occurs at %d position",i+1);
			return 0;
		}
		else{
			continue;
		}
	}
	arr=realloc(arr,(n+1)*sizeof(int));
	*(arr+n)=search_num;
	printf("\nValue at %d position is %d\n",n+1,*(arr+n));
	free(arr);
	return 0;
}