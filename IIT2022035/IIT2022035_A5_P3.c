/*Devam Desai
IIT2022035 Assignment 5 Program 3*/



#include <stdio.h>


int main(){
	int n;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	
	int arr[100],count[100];
	for (int i=0;i<100;i++){
		count[i]=0;
	}
	printf("\nEnter elements of array: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		count[arr[i]-1]++;
	}
	for(int i=0;i<100;i++){
		if(count[i]!=0){
			printf("\nNumber of occurences of %d is %d",i+1,count[i]);
		}
	}
	printf("\n");
	return 0;
}
