// Binary Search

#include<bits/stdc++.h>
using namespace std;

// Function for binary search 
int binary_search(int a[],int n,int target){
      

      int l=0;
      int r=n-1;
      int mid;
      int ans=-1;

      while(l<=r){
         mid=l+(r-l)/2;

         if(a[mid]==target){
            ans=mid;
            break;
         }
         else if(a[mid]<target) l=mid+1;
         else r=mid-1;
      }
      return ans;
}

int main(){

    int n;  // number of the elements of the array
    cin>>n;

    int a[n];// the array should be sorted beforehand
    for(int i=0;i<n;i++) cin>>a[i];

    int target;// the required target value to be found in the array
    cin>>target;

   int ans=binary_search(a,n,target);
   cout<<ans<<endl;

   // The following code outputs the index of the target value in array and returns -1 if the target value is not found in the array

   // Time Complexity =O(logn)
   // Space Complexity=O(n)
   // where n is the size of the array

}