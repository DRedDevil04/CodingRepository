#include <bits/stdc++.h>
using namespace std;

vector<int> printingLongestIncreasingSubsequence(int nums[], int n,int start) {
	
    
    vector<int> dp(n,1);
	vector<int> hash(n);
        int mx=0;
		int last=0;
        
        for(int i=start;i<n;i++){
			hash[i]=i;
            for(int j=start;j<=i;j++){
                if(nums[j]<nums[i] && 1+dp[j]>dp[i]) {
					dp[i]=1+dp[j];
					hash[i]=j;
            }
            if (dp[i] > mx) {
                                        mx = dp[i];
                                        last = i;
            }
            }
        }
        vector<int> ans;
		ans.push_back(nums[last]);
                while (hash[last] != last) {
                        last = hash[last];
                        ans.push_back(nums[last]);
                }

                reverse(ans.begin(),ans.end());
		return ans;
}
int main() {
    
   int arr[8]={5,3,8,10,6,5,7,8};
    
    int n=8;
    
    for(int i=0;i<n;i++){
        vector<int> ans;
        ans=printingLongestIncreasingSubsequence(arr,n,i);
        cout<<"Starting Position:- "<<i<<endl;
        cout<<"The Largest Sorted Subsequence is"<<endl;
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}
