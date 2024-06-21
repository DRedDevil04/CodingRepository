//IIT2022035 Devam Desai 
//DAA Assignment 

#include<bits/stdc++.h>
using namespace std;

void collinearPoints(vector<pair<int,int>> &points){
	map<int,unordered_set<int>> xs,ys;
	for(auto p: points){
		int xi=p.first;
		int yi=p.second;
		xs[xi].insert(yi);
		ys[yi].insert(xi);
	}

	// resulting map contains all the points
	for(auto yi:ys){
		if(yi.second.size()<2) continue;
		for(auto x:yi.second){
			cout<<x<<" "<<yi.first<<endl;
		}
	}
	for(auto xi:xs){
		if(xi.second.size()<2) continue;
		for(auto y:xi.second){
			cout<<y<<" "<<xi.first<<endl;
		}
	}

	cout<<"COMPLETE"<<endl;
}
void solve(int n){
    vector<pair<int,int>> arr;
    int maxi = 1e5;

    for (int i = 0;i < n;i++){
        arr.push_back({rand()%(maxi),rand()%maxi});   
    }
    collinearPoints(arr); 
}
signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    solve(1000);
    return 0;
}







