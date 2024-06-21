#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
const unsigned long long MOD =1e9+7;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
const int N=1e7+10;
vector<bool> isprime(N,1);
vector<int> hp(N,0),lp(N,0); 
ll sum=0;
bool done[10000][10000];


void dfs1(int vx, int vy,int n,int m,vector<vector<int>> &mat) {

   	if(vx<0) return;
   	if(vx>=n) return;
   	if(vy<0) return;
   	if(vy>=m) return;

   	if(done[vx][vy]){
   		return;
   	}
   	done[vx][vy]=true;
   	sum+=mat[vx][vy];
   	dfs1(vx+1,vy,n,m,mat);
   	dfs1(vx-1,vy,n,m,mat);
   	dfs1(vx,vy+1,n,m,mat);
   	dfs1(vx,vy-1,n,m,mat);


}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> mat(n);
	for(auto x:mat){
		x.assign(m,0);
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
			done[i][j]=false;
		}
	}
	int ans=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!done[i][j]){
				sum=0;
				dfs1(i,j,n,m,mat);
				ans=max((long long)ans,sum);
			}
			else{
				continue;
			}
		}
	}

}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	// t=1;
	// sieve();
	
	while(t--){
		// cout<<endl;
		// cout<<endl;
		// cout<<endl;
		solve ();	
		
	}
	return 0;
}






