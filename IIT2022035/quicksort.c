#include <stdio.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}
void quicksort(int *arr,int n){
	int pivot=arr[0];
	int i=1,j=n-1;
	if(n<=0) return;
	while(i<j && i!=n-1 && j!=0){
		while(arr[i]<pivot && i<n-1) i++;
		while(arr[j]>=pivot && j>1) j--;
		if(i<j){
			
			swap(arr+i,arr+j);
		}	
		
	}
	if(i==1){
			quicksort(arr+1,n-1);
			return;
		}
	// if(j==n-1){
		
	// 	swap(arr,arr+n-1);
	// 	quicksort(arr,n-1);
	// }
	
		// if(i==1){
		// 	quicksort(arr+1,n-1);
		// }
		if(j==n-1){
		
		swap(arr,arr+n-1);
		quicksort(arr,n-1);
		return;
	}
		
			swap(arr,arr+j);
			quicksort(arr,j);
			quicksort(arr+j+1,n-1-j);
			return;
		
		
	}

	





// void partition(){

// }
int main(){
	int arr[]={5,-6,1,4,-100,-7,10};
	printf("Original array is: ");
	for(int i=0;i<7;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	quicksort(arr,7);
	printf("Sorted array is: ");

	for(int i=0;i<7;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}