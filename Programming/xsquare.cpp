#include <iostream>

#include <string>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int hsh[26];
		for(int i=0;i<s.length();i++){
			hsh[s[i]-'a']++;
		}
		int flag=0;
		for(int j=0;j<26;j++){
			if(hsh[j]>=2){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

