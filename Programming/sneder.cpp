void solve(){
	
	int n;
	cin>>n;
	vi wt;
	vi val;
	int maxWt;
	
	vecIn(wt,n);
	vecIn(val,n);
	cin>>maxWt;
	vector<pair<float,int>> ratio;
	for(int i=0;i<n;i++){
		ratio.push_back({(float)val[i]/wt[i],i});
	}
	sort(ratio.begin(),ratio.end());
	int ind =n-1;
	int remWt=maxWt;
	int ans=0;
	while(remWt>0 && ind >=0){
		int cur=min(remWt,wt[ratio[ind].second]);
		ans=ans+cur*ratio[ind].first;
		remWt-=cur;
		ind--;
	}
	cout<<ans<<endl;

}
