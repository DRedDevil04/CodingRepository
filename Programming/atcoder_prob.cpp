#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
const unsigned long long MOD =1e9+7;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long long ll;
const int N=1e6+10;
// vector<bool> isprime(N,0);
// vector<int> hp(N,0),lp(N,0); 
// ll dp[1000001];
 
// bool check(mid,v){

// }
vector<vector<bool>> visited;

void dfs(vector<string> &gr,int x,int y,int dir){
	if(((char)gr[x][y])=='#') {
		return;
	}
	if(dir==1) {
		if(gr[x+1][y]=='#')  dfs(gr,x,y+1,4), dfs(gr,x,y-1,2);
		else dfs(gr,x+1,y,1);
	}
	else if(dir==2) {
		if(gr[x][y-1]=='#') dfs(gr,x+1,y,1), dfs(gr,x-1,y,3);
		else dfs(gr,x,y-1,2);
	}
	else if(dir==3) {
		if(gr[x-1][y]=='#') dfs(gr,x,y+1,4), dfs(gr,x,y-1,2);
		else dfs(gr,x-1,y,3);
	}
	else if(dir==4) {
		if(gr[x][y+1]=='#') dfs(gr,x+1,y,1) ,dfs(gr,x-1,y,3);
		else dfs(gr,x,y+1,4);
	}
	visited[x][y]=true;

}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		vector<bool> v(m,false);
		visited.push_back(v) ;
	}
	vector<string> gr(n);
	for(int i=0;i<n;i++){
		cin>>(gr[i]);
	}
	
	dfs(gr,1,1,1),dfs(gr,1,1,2),dfs(gr,1,1,3),dfs(gr,1,1,4);
	int ct=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j]) ct ++;
		}
	}
	cout<<ct<<endl;
	


}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t=1;
	// cin>>t;
	// // t=1;
	// // sieve();
	
	while(t--){
		// cout<<endl;
		// cout<<endl;
		// cout<<endl;
		// seive();
		solve ();	
		
	}
	return 0;
}