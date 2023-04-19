#include <iostream>
using namespace std;
int max_ones=0;
void solve(string s,int st){
    cout<<"     "<<st<<endl;
    int one_c=0;
    if(st!=-1){
    while(s[st]!='0'){
       st--;
       one_c++;
        if(st==-1){
            break;
        }
        
    }
}
if(st!=-1){
    while(s[st]=='0'){
        st--;
        if(st==-1){
            break;
        }     
        continue;
    }
}
    if(st!=-1){
    while(s[st]!='0'){
        st--;
        one_c++;
        if(st==-1){
            break;
        }
        
    }
}
    
        if(max_ones<one_c){
            max_ones=one_c;
        }
        if(st!=-1){
        while(s[st]=='0'){
            st--;
            if(st==-1){
                break;
            } 
            continue;
        }
    }
    if(st!=-1){
        solve(s,st);
    }
    else{
        return
    }
}
int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n;
        cin>>s;
        int st=n-1;
        while(s[--st]!='1'){
            continue;
        }
        for(int i=st;i>=0;i++){


            int one_c=0;
            if(st!=-1){
            while(s[st]!='0'){
            st--;
            one_c++;
                if(st==-1){
                    break;
                }
            
            }
            while()
        }
    }
        
        
        cout<<max_ones<<endl;
        max_ones=0;
    }
    return 0;
}
