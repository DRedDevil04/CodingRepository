/*Devam Desai 
IIT2022035 Sem 2 Assignment 1 Program 1*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int maxi(int *arr, int i,int n){
	static int max_s=INT_MIN;
	if(i==n){
		return max_s;
	}
	if(arr[i]>max_s){
		max_s=arr[i];
	}
	return maxi(arr,i+1,n);
}
int main(){
	int n;
	printf("Enter size of array: \n");
	scanf("%d",&n);
	int *arr=(int *)calloc(n,sizeof(int));
	for(int i=0;i<n;i++){
		printf("\nEnter element %d :",i+1);
		scanf("%d",arr+i);
	}
	//MAX through iterationc
	int max=INT_MIN;
	for(int i=0;i<n;i++){
		if(max<arr[i]){
			max=arr[i];
		}
	}
	printf("\nMax is (iteratively): %d\n",max);
	//Recursively
	int maxR=maxi(arr,0,n);
	printf("\nMax is (recursively): %d\n",maxR);
	
	return 0;



}