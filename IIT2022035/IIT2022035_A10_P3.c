/*Devam Desai 
IIT2022035 Assignment 10 Program 3*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	
	int *arr,n;
	printf("Enter number of elements of initial array:");
	scanf("%d",&n);
	arr=(int *)calloc(n,sizeof(int));
	int sum=0;
	for(int i=0;i<n;i++){
		int num;
		printf("\nEnter number %d for array:",i+1);
		scanf("%d",&num);
		*(arr+i)=num;
	}
	int factor;
	printf("\nEnter factor:");

	scanf("%d",&factor);

	arr=realloc(arr,sizeof(int)*n*factor);
	for(int i=1;i<factor;i++){
		for(int j=0;j<n;j++){
			*(arr+(n*i)+j)=*(arr+j);
		}
	}
	printf("\nArray is:");
	for(int i=0;i<factor*n;i++){
		printf(" %d ",*(arr+i));
	}
	printf("\n");
	free(arr);
	return 0;
}