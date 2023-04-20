#include<stdio.h>
#include <stdlib.h>
void quicksort(int arr[],int st_ind,int end_ind);
void replace(int arr[],int ind1,int ind2);

void print_arr(int arr[]);
int main(){
	// INPUT VARIABLE ARRAY LEFT

	int arr[10]={7,3,8,6,4,1,2};
	quicksort(arr,0,6);
	print_arr(arr);

	
	
	

	
}
void quicksort(int arr[10],int st_ind,int end_ind){
	int pivot=arr[end_ind];
	int j=st_ind-1;
	if(end_ind-st_ind>1){
	
	for(int i=st_ind;i<=end_ind-st_ind;i++){
		if (arr[i]<pivot){
			j+=1;
			replace(arr,j,i);
			print_arr(arr);

			printf("%d %d\n",j,i );
		}
	}
		replace(arr,j+1,end_ind);
		printf("\n\n\n");
		print_arr(arr);
		printf("\n\n\n");
		quicksort(arr,st_ind,j);
		quicksort(arr,j+2,end_ind);
}

}
void replace(int arr[10],int st_ind,int end_ind){
	int temp =arr[st_ind];
	arr[st_ind]=arr[end_ind];
	arr[end_ind]=temp;
}
void print_arr(int arr[10]){
	
	
	int n=0;
	
	while(n<=6){
		printf("%d ",arr[n]);
		n++;
	}
	printf("\n");
}

