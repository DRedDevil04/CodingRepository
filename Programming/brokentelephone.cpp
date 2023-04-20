#include <iostream>
using namespace std;
void print_arr(unsigned long int *,int);

int main() {
    int T,N;
	cin>>T;
	cout<<"\n";

	for(;T>=1;T--){
	    unsigned long int arr[100000];
	    int curr,last,count=0;
	    cin>>N;
	    cout<<"\n";
	    for(;N>=1;N--){
	        
	        cin>>arr[N];
	        
	    }
	    print_arr(arr,N);
	    arr[0]=arr[1];
	    for(int i=1;i<=N;i++){
	        curr=arr[i];
	        last=arr[i-1];
	        if(last!=curr){
	            int j=1;
	            while(curr!=last){
	                curr=arr[i];
	                last=arr[i-1];
	                i++,j++;
	                
	            }
	            count+=j;
	            
	        }
	    }
	    
	   cout<<count<<endl; 
	}
	
	return 0;
}
void print_arr(unsigned long int *p,int n){
    for(;n>=1;n--){
        cout<<" "<<p+n<<" ";
    }
}