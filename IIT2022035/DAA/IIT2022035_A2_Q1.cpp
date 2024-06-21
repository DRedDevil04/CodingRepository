#include <bits/stdc++.h>
using namespace std;

#define TH 200

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
	return;
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quicksort(int *arr,int n){
	if(n<TH){
		insertionSort(arr,n);
		return;
	}
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





int main(){
	int n;
	cout<<"Enter number of values in array :";
	cin>>n;
	int *arr=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	quicksort(arr,n);
	
	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	return 0;
}







	

