#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,a;
	    cin>>n>>a;
	    int c[3001],d[3001],cost[3001];
	    cost[0]=0;
	    for(int i=1;i<=n;i++){
	        cin>>c[i]>>d[i];
	        cost[i]=cost[i-1]+c[i];
	    }
	    int p,profit=0;
	   for(int i=1;i<=n;i++){
	       int c_sum=0;
	       int d_min=d[i],d_max=d[i];
	       for(int j=i;j<=n;j++){
	           int coins=(j-i+1)*a;
	           if(d[j]>d_max)d_max=d[j];
	           if(d[j]<d_min)d_min=d[j];
	           c_sum=cost[j]-cost[i-1];
	           p=coins-c_sum-(d_max-d_min)*(d_max-d_min);
	           profit=max(p,profit);
	       }
	       
	       
	   }
	   cout<<profit<<endl;
	}
	    
	
	return 0;
}
