void sieve(){

	isprime[0]=isprime[1]=false;
	for(int i=2;i<N;i++){
		
		if(isprime[i]){
			hp[i]=i;
			for(int j=2*i;j<=N;j+=i){
				isprime[j]=false;
				hp[j]=i;
				// cout<<j<<" "<<hp[j]<<endl;
				if(lp[i]==0){
					lp[j]=i;
				}
			}
		}

	}
	
}
int count_digit(int number) {
   return (int)(log10(number) + 1);
}

template <class ReverseIterator>
typename ReverseIterator::iterator_type make_forward(ReverseIterator rit)
{
    return --(rit.base()); // move result of .base() back by one.
    // alternatively
    // return (++rit).base() ;
    // or
    // return (rit+1).base().
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
ll modMInv(ll a,ll m){
	return binexp(a,m-2,m);
}
int checkpal(vector<int> &v){
	int n=v.size();
	rep(i,0,n/2){
		if(v[i]!=v[n-i-1]){
			return 0;
		}
	}
	return 1;
}
double mean(vector<ll> v){
	double m=0;
	for(auto a:v){
		m+=a;
	}
	return (m/v.size());
}
int check_interval(int s1,int e1,int s2,int e2){
	return (s1<=e2 && e1>=s2)|| (s2<=e1 &&e2>=s1);
}

void reverseStr(string& str)
{
    int len = str.length();
    int n = len-1;
    int i = 0;
    while(i<=n){
        //Using the swap method to switch values at each index
        swap(str[i],str[n]);
        n = n-1;
        i = i+1;
  }
 
}

bool checkpos(int x,int y,int t,int n){
	if(t<min(x,y)){
		return false;
	}
	int ct=0;
	t-=min(x,y);
	ct++;
	ct+=(t/x)+(t/y);
	if(ct>=n) return true;
	else{
		return false;
	}
}
bool isvowel(char s){
	return s=='a'||s=='e'||s=='i'||s=='o'||s=='u';
}
int checkset(int n){
	int setb=0;
	for(int i=1;i<32;i++){

		if(n&1==1){
			setb++;
		}
		n>>=1;
	}
	// cout<<setb <<" they "<<endl;
	return setb;
}
vector<vector<int> > vert;

vector<ll> ans;





// #######################################################################################
// DFS
// ################################################################################################





vector<bool> visited((int)1000043,false);
void reset(){
	for(int i=0;i<1e6;i++){
		visited[i]=false;
		// ans[i]=-1;
	}
	
}

int dfs(vector<vector<pair<int,int>> > &adj,int n){
	int max_val=0;
	for(auto x:adj[n]){
		
		if(!visited[x.first]){
			visited[x.first]=true;
			int val=x.second+ dfs(adj,x.first);
			// cout<<val<<" "<<x.first<<endl;
			max_val=max(max_val,val);
		}

		
	}
 // cout<<n<<" returned "<<max_val<<endl;
	return max_val;
}


int isValid(int x,int y, int m, int n){
        if(y<0 || x<0 || y>=n || x>=m) return 0;
        else return 1;
    }


int ncr(int n,int r){
	int sum=0;
	for(int i = 1; i <= r; i++){
            sum = sum * (n - r + i) / i;
     }
  return sum;
}


// #######################################################################################
// Cycle Detection
// ################################################################################################


// Using DFS

	bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
		vis[node] = 1;
		pathVis[node] = 1;

		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
				if (dfsCheck(it, adj, vis, pathVis) == true)
					return true;
			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				return true;
			}
		}

		pathVis[node] = 0;
		return false;
	}

	bool isCyclic(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if (dfsCheck(i, adj, vis, pathVis) == true) return true;
			}
		}
		return false;
	}


// Using BFS


bool bfsCheck(int src, vector<int> adj[], int vis[]) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  // yes it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
  }


// #######################################################################################
// Topological Sort
// ################################################################################################



// Using DFS

void findTopoSort(int node, vector < int > & vis, stack < int > & st, vector < int > adj[]) {
    vis[node] = 1;

    for (auto it: adj[node]) {
      if (!vis[it]) {
        findTopoSort(it, vis, st, adj);
      }
    }
    st.push(node);
  }

vector < int > topoSort(int N, vector < int > adj[]) {
      stack < int > st;
      vector < int > vis(N, 0);
      for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
          findTopoSort(i, vis, st, adj);
        }
      }
      vector < int > topo;
      while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
      }
      return topo;

    }

// Using BFS

vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}


// #######################################################################################
// Single Source Shortest
// ################################################################################################


// Dijkstra


void dijkstra(int s, vector<vector<pair<int,int>>> &gr,vector<int> &dist,vector<int> &vis){

	set<pair<int,int>> st; 
    
	st.insert({0,s});
	dist[s]=0;
	while(!st.empty()){
		auto it = st.begin();
		int v=(*it).second;
		int d=(*it).first;
		st.erase(it);
		if(vis[v]==1) continue;
		vis[v]=1;
		for(auto x: gr[v]){
			int ch=x.first;
			int w=x.second;
			if(dist[v]+w<dist[ch]){
				dist[ch]=dist[v]+w;
				st.insert({d+w,ch});
			}
		}
	}
}


// Bellman Ford

void bellman_ford(int s, int n,vector<vector<pair<int,int>>> &gr){
	vector<int> dist(n+1,1e8);
	dist[src]=0;
	for(int i=0;i<n-1;i++){
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}
	for (auto it : edges) {
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
			return { -1};
		}
	}
	return dist;

}



// #######################################################################################
// Multi Source Shortest Path
// ################################################################################################

// Floyd Warshall

void floyd_warshall(int n, vector<vector<pair<int,int>>> &gr){
	vector<vector<int>> dist(n+1,vector<int> (n+1,1e9));
	for(int i=0;i<n;i++){
		for(auto x:gr[i]){
			dist[i][x.first]=min(dist[i][x.first],x.second);
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dist[i][k]!=1e9 && dist[k][j]!=1e9)
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}


// Johnsons




const int M = 500;
/*
   Adjacency List
   edge = {u, v, w}
   g[u].push_back({v, w})
*/
vector <pair<int, int>> G[M];

vector <int> bellmanFord(int &N, vector <vector<int>> edges){
   for(int i = 1; i <= N; i++){
       edges.push_back({0, i, 0});
   }
   vector <int> d(N + 1, INT_MAX);
   d[0] = 0;
   while(true){
       bool check = false;
       for(auto e : edges){
           int u = e[0];
           int v = e[1];
           int w = e[2];
           if(d[v] > d[u] + w){
               d[v] = d[u] + w;
               check = true;
           }
       }
       if(!check)
           break;
   }
   return d;
}


void Dijkstra(int src, vector <vector<int>> &path, int &N){
   
   priority_queue<pair<int, int>> pq;
   vector <int> vis(N + 1);
   path[src][src] = 0;
   pq.push({0, src});
   while(!pq.empty()){
       int f = pq.top().second;
       pq.pop();
       if(!vis[f]){
           vis[f] = true;
           for(auto u : G[f]){
               int s = u.first;
               int w = u.second;
               if(path[src][f] + w < path[src][s]){
                   path[src][s] = path[src][f] + w;
                   pq.push({-path[src][s], s});
               }
           }
       }
   }
}

signed main(){
   //vertices, edges
   int N, M;
   cin >> N >> M;
   
   vector <vector<int>> edges;
   for(int i = 1; i <= M; i++){
       int u, v, w;
       cin >> u >> v >> w;
       edges.push_back({u, v, w});
   }
   
   vector <int> C = bellmanFord(N, edges);
   for(int i = 0; i < M; i++){
       int u = edges[i][0];
       int v = edges[i][1];
       
       edges[i][2] += (C[u] - C[v]);
   }
   
   vector <vector<int>> path(N + 1, vector <int> (N + 1, INT_MAX));
   
   for(auto e : edges){
       G[e[0]].push_back({e[1], e[2]});
   }
   
   for(int i = 1; i <= N; i++){
       Dijkstra(i, path, N);
   }
   for(int i = 1; i <= N; i++){
       for(int j = 1; j <= N; j++){
           //If there is no path between i and j output -1
           if(path[i][j] == INT_MAX)
               cout << -1 << " ";
           //shortest path from vertex i to j
           else
               cout << path[i][j] - (C[i] - C[j]) << " ";
       }
       cout << "\n";
   }
   return 0;
}   









// bellman and dijkstra from all vertices 


// #######################################################################################
// MST
// ################################################################################################

// Prims

int prims(int n, vector<vector<pair<int,int>>> &gr){
	vector<int> vis(n+1,0);
	set<pair<int,int>> st;
	st.insert({0,0});
	while(!st.empty()){
		auto it=st.begin();
		int v=(*it).second;
		int wt=(*it).first;
		st.erase(it);
		if(vis[v]) continue;
		vis[v]=1;
		sum+=wt;
		for(auto p: gr[v]){
			int adj=p.first;
			int w=p.second;
			if(!vis[p]){
				st.insert({w,adj});
			}
		}
	}
	return sum;
}


// Kruskals


int kruskals(int n, vector<pair<int,pair<int,int>>> &gr){
	vector<pair<int,pair<int,int>>> edges;
	for(int i=0;i<n;i++){
		dsu_make(i);
	}
	for(int i=0;i<n;i++){
		for(auto x:gr[i]){
			edges.push_back({x.second,{i,x.first}});
		}
	}
	sort(edges.begin(),edges.end());
	int sum=0;
	for(auto x: edges){
		int wt=x.first;
		int from=x.second.first;
		int to=x.second.second;
		if(dsu_find(from)!=dsu_find(to)){
			sum+=wt;
			dsu_union(from,to);
		}
	}
	return sum;

}



// #######################################################################################
// DSU
// ################################################################################################



vector<int> parent((int)1e6+5,-1);
vector<int> size_dsu((int)1e6+5,0);
int dsu_find(int n){
	if(parent[n]==n) return n;
	else return parent[n]=dsu_find(parent[n]);
}
void dsu_make(int n){
	parent[n]=n;
	size_dsu[n]=1;
}
void dsu_union(int a,int b){
	a=dsu_find(a);
	b=dsu_find(b);
	if(a==b) return;
	if(size_dsu[a]<size_dsu[b]){
		swap(a,b);
	}
	parent[b]=a;
	size_dsu[a] += size_dsu[b];
}



vector<pair<int,int>> dirs={{-1,0},{0,1},{1,0},{0,-1}};

int isValid(int x,int y, int m, int n){
        if(y<0 || x<0 || y>=n || x>=m) return 0;
        else return 1;
    }
    int dp_solve(int i,int j,vector<int> &cs,vector<vector<int>> &dp){
        if(j-i==1){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        else{
            int ans=1e9;
            int ct=0;
            for(int k=0;k<cs.size();k++){
                if(cs[k]<j && cs[k]>i){
                    ct++;
                    ans=min(ans,dp_solve(i,cs[k]-1,cs,dp)+dp_solve(cs[k]+1,j,cs,dp)+j-i);
                }
            }
            if(ct==0) return dp[i][j]=0;
            return dp[i][j]=ans;
        }
    }
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(n+2,vector<int> (m+2,-1));
        return dp_solve(0,n-1,cuts,dp);
    }
 void solve2(){
	 vector<int> c={1,3,4,5};
	 cout<<minCost(7,c)<<endl;
}



// #######################################################################################
// Maximum Flow
// ################################################################################################



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

void edmonds_karp(int n, vector<vector<int>> &gr(n+1)){
	

	int n;
	cin>>n;
	int s,t;
	cin>>s>>t;
	vector<vector<int>> gr(n+1);
	vector<vector<int>> capacity(n+1,vector<int> (n+1,0));
	vector<int> parent(n+1,-1);
	int e;
	cin>>e;
	for(int i=0;i<e;i++){
		int u,v,cap;
		cin>>u>>v>>cap;
		gr[u].push_back(v);
		gr[v].push_back(u);
		capacity[u][v]=cap;
	}
	int max_flow=0;
	int new_flow;
	while((new_flow=bfs(s,t,gr,parent,capacity))){
		max_flow+=new_flow;
		int cur=t;
		while(cur!=s){
			int prev=parent[cur];
			capacity[prev][cur]-=new_flow;
			capacity[cur][prev]+=new_flow;
			cur=prev;
		}
	}
	cout<<max_flow<<endl;

}

// Minimum cut = max flow
// to get the cut, take all vertices reachable from s and the other vertices
// as the 2 partitions and make a cut between them

// for Max Bipartite matching do the same for every edge having c = 1 
// and s and t become the 2 extended vertices connected to the 2 bipartitions







// #######################################################################################
// Strongly Connected Components (Kosaraju)
// ################################################################################################





void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }

    void dfs3(int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }

    //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                // i -> it
                // it -> i
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }


// #######################################################################################
// Fenwick Tree (Binary Indexed Tree)
// ################################################################################################

#define N 1e5
vector<int> bit(N,0);
vector<int> a(N,0);
//1 indexed

long long sum(int i){
	int ans=0;
	for(;i>0;i-=(i&(-i))){
		ans+=bit[i];
	}
	return ans;
}

void update(int i, int val){
	for(;i<=N;i+=(i&(-i))){
		bit[i]+=val;
	}
}


struct fenwick_tree{
	vector<int> bit;
	void init(int n){
		while(n--){
			bit.push_back(0);
		}
	}
	long long sum(int i){
		int ans=0;
		for(;i>0;i-=(i&(-i))){
			ans+=bit[i];
		}
		return ans;
	}

	void update(int i, int val){
		for(;i<=N;i+=(i&(-i))){
			bit[i]+=val;
		}
	}

	void clear(){
		fill(bit.begin(), bit.end(), 0);
	}
	// int bit_search(int v){
	// 	int sum = 0;
	// 	int pos = 0;
		
	// 	for(int i=log2(n); i>=0; i--)
	// 	{
	// 		if(pos + (1 << i) < N and sum + bit[pos + (1 << i)] < v)
	// 		{
	// 			sum += bit[pos + (1 << i)];
	// 			pos += (1 << i);
	// 		}
	// 	}

	// 	return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
	// }	
};



// #######################################################################################
// Segment Tree
// ################################################################################################

int n;
int a[N], b[N]; 

// 
struct SegTree
{
     int N;
     vector<int> st;
    
     void init(int n)
     {
          N = n;
          st.resize(4 * N + 5);
     }

     

     void Build(int node, int L, int R)
     {
          if (L == R)
          {
               st[node] = b[L];
               return;
          }
          int M = (L + R) / 2;
          Build(node * 2, L, M);
          Build(node * 2 + 1, M + 1, R);
          st[node] = max(st[node * 2], st[node * 2 + 1]);
     }

     void Update(int node, int L, int R, int pos, int val)
     {
          if (L == R)
          {
               st[node] += val;
               return;
          }
          int M = (L + R) / 2;
          if (pos <= M)
               Update(node * 2, L, M, pos, val);
          else
               Update(node * 2 + 1, M + 1, R, pos, val);

          st[node] = max(st[node * 2], st[node * 2 + 1]);
     }

     int Query(int node, int L, int R, int i, int j)
     {
          if (j < L || i > R)
               return 0;
          if (i <= L && R <= j)
               return st[node];
          int M = (L + R) / 2; 
          return max(Query(node * 2, L, M, i, j), Query(node * 2 + 1, M + 1, R, i, j));
          
     }

     

     int query(int l, int r) { return Query(1, 1, N, l, r); }

     void update(int pos, int val) { Update(1, 1, N, pos, val); }

     void build() { Build(1, 1, N); }

};
SegTree seg;

void solve()
{
  seg.init(4 * n);
  seg.build();
}




// #######################################################################################
// Stable Marriage Problem
// ################################################################################################


bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prefer[w][i] == m1)
            return true;
        if (prefer[w][i] == m)
           return false;
    }
}
 
void stableMarriage(int prefer[2*N][N])
{   
    int wPartner[N]; 
    bool mFree[N];
    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;
 
    while (freeCount > 0)
    {     
        int m;
        for (m = 0; m < N; m++)
            if (mFree[m] == false)
                break;
        for (int i = 0; i < N && mFree[m] == false; i++)
        {
            int w = prefer[m][i];
 
            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }
            else  
            {  
                int m1 = wPartner[w-N];
                if (wPrefersM1OverM(prefer, w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            } 
        } 
    }
    cout << "Woman   Man" << endl;
    for (int i = 0; i < N; i++)
       cout << " " << i+N << "\t" << wPartner[i] << endl;
}




/*Given that I am on the edge of completing the Machine Learning specialisation course by the same course creators. I think this course will further enhance my knowledge in the field of deep learning. Gaining an intuitive understanding of deep learning concepts is key in becoming an AI researcher and this course will provide me with a platform to transform my currently rudimentary ML skills to match an industry standard with exposure to cutting edge technology such as Sequence models, transformers , LSTMs etc. I also plan to create some projects and maybe start to delve into the research part of this particular domain. This will greatly contribute in my applications to colleges in the future. I promise to be a diligent student and complete all the assignments, quizzes and labs on time. Artificial Intelligence is the present and the future. It is an exciting field and i hope to be able to contribute to it after gaining some valuable knowledge from this course.
Regards 
Devam*/
