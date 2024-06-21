//IIT2022035 Devam Desai 
//DAA Assignment Q2


#include<bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int> arr, int n)
{
	int ct=0;
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ct++;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    return ct;
}
int insertionSort(vector<int> arr, int n)
{
	int ct=0;
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        ct++;
    }
    return ct;
}

int selectionSort(vector<int> arr, int n) 
{ 
    int i, j, min_idx; 
  	int ct=0;
    for (i = 0; i < n - 1; i++) { 
        min_idx = i; 
        for (j = i + 1; j < n; j++) { 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
        } 
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]); 
        	ct++;
        }
    } 
    return ct;
} 

int main(){
	int n=1000;
    vector<int> arr1,arr2,arr3;
    int maxi = 1e5;

    for (int i = 0;i < n;i++){
    	int val=rand()%(maxi);
        arr1.push_back(val);
        arr2.push_back(val);
        arr3.push_back(val);   
    }
    int selsw=selectionSort(arr1,1000);
    int inssw=insertionSort(arr2,1000);
    int bubbsw=bubbleSort(arr3,1000);
    
    cout<<selsw<<" "<<inssw<<" "<<bubbsw<<endl;

    return 0 ;
}