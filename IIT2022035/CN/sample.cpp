#include <bits/stdc++.h>

int fin_ans=0;

int vals(Node *tree){
	int ans=0;
	map<int,int> mp;
	for(int i=0;i<(tree->subtrees.size());i++){
		int cur=vals((tree->subtrees)[i]);
		ans+=cur;
		mp[cur]++;
	}
	if(mp.size()<=1) fin_ans++;
	return ans+1;
}

int solution(Node * tree){
	vals(tree);
	return fin_ans;
}