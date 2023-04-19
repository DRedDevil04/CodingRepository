/*Devam Desai
IIT2022035 Assignment_7 Program_3*/


#include <stdio.h>
int arr[10000];
int search(int,int,int);
int main(){
	int len,num,index;
	printf("Enter the length of arr: ");
	scanf("%d",&len);
	printf("\nEnter the array: ");
	for(int i=0;i<len;i++){
		scanf("%d",arr+i);
	}
	printf("\nEnter number to be seached:");
	scanf("%d",&num);
	index=search(num,0,len);
	printf("\nFirst position of occurence is %d position\n",index+1);

}
int search(int num,int index,int len){
	if(arr[index]==num){
		return index;
	}

	else if(index==(len-1)){
		return -1;
	}
	else{
		return search(num,index+1,len);
	}

}