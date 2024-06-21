#include <bits/stdc++.h>
using namespace std;
 
#define fo(i,a,b) for (ll i = a; i <= b; i++)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define vint vector<long long>
#define mii
// const unsigned long long MOD =1e9+7;
const unsigned long long MOD =998244353;
typedef vector<long long> vi;
typedef pair<int,int> pi;
typedef long long ll;
#define int long long
const int N=1e6+10;


void vecIn(vector<long long> &v,long long n){
	for(ll i=0;i<n;i++){
		ll num;
		cin>>num;
		v.push_back(num);
	}
}

vector<vector<int>> levelOrder(int node,vector<vector<int>> &gr,vector<bool> &vis) {
        
        queue<pair<int,int>> q;
        q.push({node,0});
        int lev=0;
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        while(!q.empty()){
            auto cur=q.front();
            q.pop(); 
            cout<<cur.first<<" "<<cur.second<<endl;
            vis[cur.first]=true;
            if(cur.second!=lev){
                ans.push_back(temp);
                temp.clear();
                lev=(lev+1);
            }
            temp.push_back(cur.first);
            for(auto x: gr[cur.first]){
            	if(vis[x]) continue;
            	q.push({x,(lev+1)});
            }
        }
        ans.push_back(temp);
        return ans;
    }

ll binexp(ll a,ll b,ll m){
	ll result=1;
	while(b>0){
		if(b&1!=0){
			result=(result*1LL*a)%m;
		}
		a=(a*1LL*a)%m;
		b>>=1;
	}
	return result;
}
int digCt(int n){
	int ans=0;
	while(n>0){
		ans+=n%10;
		n/=10;
	}
	return ans;
}
template <class T> bool ckmax(T &a, T b) {return a<b ? a=b, true : false;}


int bfs(int s, int t, vector<vector<int>> &gr,vector<int> &parent,vector<vector<int>> &capacity){
	fill(parent.begin(), parent.end(),-1);
	parent[s]=-2;
	int n=gr.size();
	queue<pair<int,int>> q;
	q.push({s,1e9});
	while(!q.empty()){
		int v=q.front().first;
		int flow=q.front().second;
		q.pop();
		for(auto next:gr[v]){
			if(capacity[v][next] && parent[next]==-1){
				parent[next]=v;
				int new_flow=min(flow,capacity[v][next]);
				if(next==t){
					return new_flow;
				}
				q.push({next,new_flow});
			}
		}
	}
	return 0;
}

void solve(){
	
	int n;
	cin>>n;
	vector<vector<int>> dist(n,vector<int> (n,1e9));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int wt;
			cin>>wt;
			dist[i][j]=wt;
		}
	}
	vector<int> order;
	
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		--num;
		order.push_back(num);	
	}
	reverse(order.begin(),order.end());
	vi ans;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dist[i][j]=min(dist[i][j],dist[i][order[k]]+dist[order[k]][j]);
			}
		}
		int sum=0;

		for(int i=0;i<k+1;i++){
			for(int j=0;j<k+1;j++){		
				sum+=dist[order[i]][order[j]];
			}
		}
		ans.push_back(sum);
	}
	reverse(ans.begin(),ans.end());
	for(auto x: ans){
		cout<<x<<" ";
	}
	cout<<endl;

}

  
 
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t=1;
	// cin>>t;
	// t=1;
	// sieve();
	// cout<<setfwPcision(9);
	
	while(t--){
		
		solve();		
		
	}
	return 0;
}
 


 
 
 
 
