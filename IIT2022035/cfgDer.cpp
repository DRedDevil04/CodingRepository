#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> grammer={
	{
		"A1B"
	},
	{
		"0A","^"
	},
	{
		"0B","1B","^"
	}
};
string A(string &s,int i,string &b){
	string a="";
	while(s[i]=='0'){
		a+="0";
		i++;
	}
	return a;

}
void S(string &s){
	string a=" ",b=" ";
	cout<<"A is: "<<A(s,0,a)<<endl;
	// cout<<"B is: "<<B(s,k,b)<<endl;
}

// string B(string &s,int i,string &b){
// 	return "0" + B(s) | "1" + B(s)| "^";
// }
// void Derive(s,&v,0){
// 	for(auto x: grammer[0]){
// 		for(auto y:x){
// 			if(x!='A' || x!='B'){

// 			}
// 			else{
// 				Derive(s,)
// 			}
// 		}
// 	}
// }



int main(){

	string s;
	cin>>s;
	S(s);
	string k="1";
	k+="0";
	cout<<k<<endl;
	
	return 0;
}