/*Devam Desai
IIT2022035 Assignment 5 Program 2*/



#include <stdio.h>

void print_arr(int *, int);
int main(){
	int n;
	printf("Enter the size of arrays: ");
	scanf("%d",&n);
	
	int arr1[100],arr2[100],arr_sum[200];
	printf("\nEnter elements of array 1: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr1[i]);
	}
	printf("\nArray 1 is: ");
	print_arr(arr1,n);
	printf("\nEnter elements of array 2: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr2[i]);
	}

	printf("\nArray 2 is: ");
	print_arr(arr2,n);
	
	for(int i=0;i<n;i++){
		arr_sum[i]=arr1[i];

		arr_sum[n+i]=arr2[i];

	}
	printf("\nArray sum is: ");
	print_arr(arr_sum,n+n);

}

void print_arr(int *arr,int n){
	printf("\n");
	for(int i=0;i<n;i++){
		
		printf(" %d ",*(arr+i));
		
	}
	printf("\n");
}



