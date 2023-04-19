/*Devam Desai
IIT2022035 Assignment 9 Program 2*/


#include <stdio.h>
void inputArray(int *,int);
int search(int *, int, int);
int main(){
	int func;
	
	int arr[1000];
	
	int size;
	printf("\nEnter number of values you want to input:");
	scanf("%d",&size);
		
	inputArray(arr,size);
	
	
	int num,position;
	printf("\nEnter number you want to search:");
	scanf("%d",&num);
	position=search(arr,size,num);
	if(position){
		printf("\nElement is at %d position in the array\n",position);
	}
	else{
		printf("\nGiven Element is not in the array\n");
	}


	return 0;
}
void inputArray(int * arr, int size){
	printf("\nEnter the array:");
	for(int i=0;i<size;i++){
		scanf("%d",arr+i);
	}
}
int search(int * arr, int size, int toSearch){
	for(int i=0;i<size;i++){
		if((*(arr+i))==toSearch){
			
			return i+1;
		}
	}
	return 0;
}