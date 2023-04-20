#include <stdio.h>
void mergesort(int *,int,int);
void merge(int *,int,int,int);
int main(){
	int arr[]={4,1,2,3,9,6};
	mergesort(arr,0,5);
	for(int i=0;i<6;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}
void mergesort(int arr[6],int lo,int hi){
	if(hi==lo){
		return;
	}
	else if((hi-lo)==1){
		if(arr[lo]>arr[hi]){


		int temp=arr[lo];
		arr[lo]=arr[hi];
		arr[hi]=temp;
		return;
	}
	}
	else{
	int m=(hi+lo)/2;
	mergesort(arr,lo,m);
	mergesort(arr,m+1,hi);
	merge(arr,lo,m,hi);
}
}
void merge(int arr[6],int lo,int m,int hi){

	for(int i=lo)
}
