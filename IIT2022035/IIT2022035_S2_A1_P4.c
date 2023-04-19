/*Devam Desai 
IIT2022035 Sem 2 Assignment 1 Program 4*/
#include <stdio.h>
#include <stdlib.h>
int n;
void interchange(int **arr1, int **arr2){
	int *a=*arr1;
	*arr1=*arr2;
	*arr2=a;
}
int main(){
	
	printf("Enter the size of the arrays: ");
	scanf("%d",&n);
	int *arr1=(int*)malloc(n*sizeof(int));
	int *arr2=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		printf("\nEnter element %d of array 1:",i+1);
		scanf("%d",arr1+i);
	}
	for(int i=0;i<n;i++){
		printf("\nEnter element %d of array 2:",i+1);
		scanf("%d",arr2+i);
	}
	interchange(&arr1,&arr2);
	printf("\nArray 1 is now: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr1[i]);
	}
	printf("\nArray 2 is now: ");
	for(int i=0;i<n;i++){
		printf("%d ",arr2[i]);
	}
	printf("\n");
	return 0;

}