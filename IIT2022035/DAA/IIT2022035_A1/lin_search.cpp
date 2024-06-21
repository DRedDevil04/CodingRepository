#include <iostream>
#include <vector>
using namespace std;



int main(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		v.push_back(num);
	}
	int k;
	cin>>k;
	for(int i=0;i<n;i++){
		if (v[i]==k){
			cout<<"FOUND at position "<<i+1<<endl;
			return 0;
		}
	}
	cout<<"NOT FOUND"<<endl;
	return 0;

}