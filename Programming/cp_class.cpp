#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
int checkpal(string s){
	int n=s.length();
	rep(i,0,n/2){
		if(s[i]!=s[n-i-1]){
			return 0;
		}
	}
	return 1;
}
int sumi(int n){
	return (n*(n+1))/2;
}
int full_cover(int x, int y,int n,int m){
	int k=4;
	if(x==1){
		k--;
	}
	if(y==1){
		k--;
	}
	if(y==m){
		k--;
	}
	if(x==n){
		k--;
	}
	return k;
}





int joseph(int n,int k){
	if(n==1){
		return 1;
	}
	else{
		return (joseph(n-1,k)+k-1)%n+1;
	}
}


int bin_search(vector<vector<int>> arr ,vector<vector<int>> vals,int i,int j,int st,int end,int n,int m,int k){
	
	// if((end-st)<1){
		
	// 	return end;
	
	// }

	int d=(st+end)/2;
	// cout<<"din is : "<<st<<" "<<end<<" "<<" "<<d<<endl;

	int x1=max(i-d,1);
	int y1=max(1,j-d);
	int x2=min(i+d,n);
	int y2=min(m,j+d);
	int sum=(arr[x2][y2]-arr[x2][y1-1]-arr[x1-1][y2]+arr[x1-1][y1-1]);
	
		// cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<sum<<endl;
	
	if((end-st)<1){
		if(sum<k+1){
			return d;
		}
		else{
			return d;
		}
		
	
	}
	if(sum>=k+1){
		return bin_search(arr,vals,i,j,st,d,n,m,k);
	}
	else{
		// cout<<d+1<<" caller "<<end<<endl;
		return bin_search(arr,vals,i,j,d+1,end,n,m,k);
	}
}

int main(){
	int t;
	cin>>t;
	
	while(t--){
		
		

		// int n,m,k;
		// cin>>n>>m>>k;
		// vector<vector<int>> vals ;
		// vector<vector<int>> arr ;
		// for(int i=0;i<=n;i++){

		// 	vector<int> v;
		// 	arr.push_back(v);
		// 	vector<int> siu;
		// 	vals.push_back(siu);
		// 	for(int j=0;j<=m;j++){
		// 		// arr[i][j]=0;
		// 		vals[i].push_back(0);
		// 		arr[i].push_back(0);
				
		// 	}
			
		// }
		
		
		// int kiss=0;
		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=m;j++){
		// 		int num;
		// 		cin>>num;
		// 		kiss+=num;
		// 		vals[i][j]=num;
		// 		arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+num;
		// 		// cout<<arr[i][j]<<" ";
		// 	}
			
		// }
		
		// if(kiss<k+1){
		// 	cout<<-1<<endl;
		// 	continue;
		// }

		// int mini=INT_MAX;
		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=m;j++){
		// 		if(vals[i][j]==0){
		// 			continue;
		// 		}
		// 		// cout<<"j: "<<j<<endl;
		// 		int d=bin_search(arr,vals,i,j,0,max(n,m),n,m,k);
		// 		// cout<<"d: "<<d<<endl;
		// 		// cout<<endl;
		// 		mini=min(mini,d);

		// 	}
		// }
		// cout<<mini<<endl;
	// 	 ll n; cin>>n;
      // ll m, k; cin>>m>>k;
      // ll i, j;
      // ll a[n][m], sum[n+1][m+1];
      // memset(sum,0, sizeof(sum));
      // rep(i,0,n-1)
      // {
      //   rep(j,0,m-1)
      //   {
      //     cin>>a[i][j];
      //     sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + a[i][j];
          
      //   }
      // }
      // // loo(i, n+1)
      // // {
      // //   loo(j, m+1)
      // //     cout<<sum[i][j]<<" ";
      // //   cout<<endl;
      // // }
      // if(sum[n][m] < (k+1))
      // {
      //   cout<<"-1"<<endl;
      //   continue;
      // }
      // ll ans = max(n, m)+1;
      // // use binary search on every cell
      // rep(i,0,n-1)
      // {
      //   rep(j,0,m-1)
      //   {
      //     if(a[i][j] == 0)
      //       continue;
      //     //cout<<"NEXT"<<endl;
      //     ll low = 0, high = ans-1;
      //     while(low<=high)
      //     {
      //       ll mid= (low+high)/2;
      //       //cout<<low<<" "<<high<<" "<<mid<<endl;
      //       ll ti = max((ll)-1, i-mid-1), lj = max((ll)-1, j-mid-1);
      //       ll bi = min(n-1, i+mid), rj = min(m-1, j+mid);
      //       ll tsum = sum[bi+1][rj+1]- sum[bi+1][lj+1] - sum[ti+1][rj+1] + sum[ti+1][lj+1];
      //       //cout<<ti<<" "<<lj<<" "<<bi<<" "<<rj<<endl;
      //       //cout<<sum[bi+1][rj+1]<<" "<<sum[bi+1][lj+1]<<" "<<sum[ti+1][rj+1]<<" "<<sum[ti+1][lj+1]<<endl<<endl;
      //       if(tsum >=(k+1))
      //       {
      //         ans = min(ans, mid);
      //         high = mid-1;
      //       }
      //       else
      //         low = mid+1;
      //     }
      //     //cout<<ans<<" ";
      //   }
      //   //cout<<endl;
      // }
      // cout<<ans<<endl;


		
// 		int f;
// cin>>f;
// cout<<f<<endl;
		
		
		// cout<<n<<" & "<<m<<endl;
		// for(int i=0;i<m;i++){
		// 	int f,p;
		// 	string s;
		// 	cin>>f>>p>>s;
		// 	cout<<f<<" "<<p<<endl;
		// }
		
		int n;
		cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		int st=-1,end=-1;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				st=i;
				break;
			}
		}
		for(int i=n-1;i>=0;i--){
			if(a[i]!=b[i]){
				end=i;
				break;
			}
		}
		cout<<st<<" "<<end<<endl;





	}
	return 0;
}


