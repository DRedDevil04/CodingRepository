#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
 
#define fo(i,a,b) for (ll i = a; i <= b; i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define vint vector<long long>
#define mii
const unsigned long long MOD =(1e9)+7;
// const unsigned long long MOD =998244353;
typedef vector<long long> vi;
typedef pair<int,int> pi;
typedef long long ll;
#define int long long
const int N=1e6+10;
using namespace __gnu_pbds;


typedef tree < int ,  null_type ,  less_equal<int> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;

void vecIn(vector<long long> &v,long long n){
	for(ll i=0;i<n;i++){
		ll num;
		cin>>num;
		v.push_back(num);
	}
}

vector<pair<int,int>> dirs={{1,0},{0,-1},{-1,0},{0,1}};
bool checkCo(int i, int j, int n, int m){
	if((i<0) || (i>=n) || (j<0) || (j>=m)) return false;
	return true;
}
pair<int,int> dfs(int v, int par,vector<vector<int>> &gr,vector<int> &l,vector<int> &r){
	int ct=0;
	int moves=0;
	int maxi=0;
	for(auto ch:gr[v]){
		
		pair<int,int> p=dfs(ch,v,gr,l,r);
		int move=p.first;
		int mx=p.second;
		if(move==0) continue;
		maxi+=mx;
		moves+=move;
	}	
	if(maxi<l[v]) {
		moves++;
		maxi=r[v];
	}
	else{
		maxi=min(r[v],maxi);
	}
	return {moves,maxi};
}

void solve(){

	int n;
	cin>>n;

	priority_queue<pair<int,int>> pq;

	vi a;
	vecIn(a,n);
	vector<pair<int,int>> ans;

	for(int i=0;i<n;i++){
		if(a[i]>0) pq.push({a[i],i+1});
	}

	while(pq.size()>=2){
		auto f=pq.top();
		pq.pop();
		auto s=pq.top();
		pq.pop();

		f.first--;
		s.first--;
		
		ans.push_back({f.second,s.second});

		if(f.first!=0) pq.push(f);
		if(s.first!=0) pq.push(s);
	}

	cout<<ans.size()<<endl;

	for(auto p:ans){
		cout<<p.first<<" "<<p.second<<endl;
	}

}



int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t=1;
	cin>>t;
	// t=1;
	// sieve();
	// cout<<setfwPcision(9);
	
	while(t--){
		solve();		
		
	}
	return 0;
}
 


 
 
 
 
