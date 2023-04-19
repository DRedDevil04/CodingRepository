/*Devam Desai
IIT2022035	Assignment 5 Program1*/

#include <stdio.h>

void print_arr(int *,int );
int main(){


	

	int arr[100];
	int num,check_num,flag=0;
	printf("Enter the size of arrays: ");
	scanf("%d",&num);
	printf("\nEnter elements of array: ");
	int i;
	for(i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}
	printf("\nArray is: ");
	print_arr(arr,num);
	printf("\nEnter Number you want to check: ");
	scanf("%d",&check_num);
	for(i--;i>=0;i--){
		if(arr[i]==check_num){
			printf("\nTrue");
			flag=1;

			break;
		}
		
	}
	if(flag==0) printf("\nFalse");

	

	return 0;
	}
	void print_arr(int *arr,int n){
	printf("\n");
	for(int i=0;i<n;i++){
		
		printf("%d ",*(arr+i));
		
	}
	printf("\n");
}