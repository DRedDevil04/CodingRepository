// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>

// using namespace std;
// set<set<int>> visited;
// // bool nfa(vector<int> table[][2],string &s,int idx,vector<int> &finalStates, int state) {
// //     if (idx == s.size()) return find(finalStates.begin(),finalStates.end(),state) == finalStates.end() ? false : true;

// //     for (int &ele : table[state][s[idx] - '0']) {
// //         if (ele == -1) return false;
// //         if (nfa(table,s,idx+1,finalStates,ele)) return true;
// //     }
// //     return false;
// // }

// int main() {
//     cout<<"Enter String: ";
//     string s; cin>>s;
//     vector<int> table[4][2] = {
//         {{0},{0,1}} , {{-1},{2}} , {{2},{2}}  , {{-1},{-1}}
//     };
//     vector<int> table[8][3] ;
//     for(int i=0;i<3;i++){
//         for(int j=0;j<2;j++){
//             visited.insert(table[i][j]);
//             if(visited.find(table[i][j])==visited.end()){
//                 for(auto x:table[i][j]){
//                     cout<<x<<",";
//                 }
//                 cout<<" ";
//                 for(auto x:table[i][j]){

//                 }
//             }
//         }
//     }
//     vector<int> finalStates = { 2 };
//     if (nfa(table,s,0,finalStates,0)) cout<<"Accepted\n";
//     else cout<<"Rejected\n";
// }














































#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<vector<int> > > table){
   
    char a='a';
    for(int i=0;i<table[0].size()-1;i++){
        cout<<"   "<<a++<<"   |";
    }
    cout<<"   ^   "<<endl<<endl;
    for(int i=0;i<table.size();i++){
        cout<<"       "<<i<<"      ";
        for(int j=0;j<table[i].size();j++){
            cout<<" | ";
            for(int k=0;k<table[i][j].size();k++){ 
                cout<<table[i][j][k]<<" ";
                
            }
        }
        cout<<endl;
    }
}

void printdfa(vector<vector<int> > states, vector<vector<vector<int> > > dfa){
    
    char a='a';
    for(int i=0;i<dfa[0].size();i++){
        cout<<"|   "<<a++<<"   ";
    }
    cout<<endl;
    for(int i=0;i<states.size();i++){
        cout<<"{ ";
        for(int h=0;h<states[i].size();h++)
            cout<<states[i][h]<<" ";
        if(states[i].empty()){
            cout<<"^ ";
        }
        cout<<"} ";
        for(int j=0;j<dfa[i].size();j++){
            cout<<" | ";
            for(int k=0;k<dfa[i][j].size();k++){
                cout<<dfa[i][j][k]<<" ";
                
            }
            if(dfa[i][j].empty()){
                cout<<"^ ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int n,alpha;
    
    cout<<"Enter total number of states in NFA : ";
    cin>>n;
    cout<<"Enter number of elements in alphabet : ";
    cin>>alpha;
    vector<vector<vector<int> > > table;
    for(int i=0;i<n;i++){
        cout<<"For state "<<i<<endl;
        vector< vector< int > > v;
        char a='a';
        int y,yn;
        for(int j=0;j<alpha;j++){
            vector<int> t;
            cout<<"Enter no. of output states for input "<<a++<<" : ";
            cin>>yn;
            cout<<"Enter output states :"<<endl;
            for(int k=0;k<yn;k++){
                cin>>y;
                t.push_back(y);
            }
            v.push_back(t);
        }
        
    }
    cout<<"NFA"<<endl;
    print(table);
   cout<<"DFA"<<endl;
    vector<vector<vector<int> > > dfa;
    vector<vector<int> > states;
    states.push_back({0});
    queue<vector<int> > q;
    q.push(states[0]);
    while(!q.empty()){
        vector<int> f=q.front();
        q.pop();
        vector<vector<int> > v;
        for(int i=0;i<alpha;i++){
            vector<int> t;
            set<int> s;
            
            for(auto u=s.begin(); u!=s.end();u++)
                t.push_back(*u);
            v.push_back(t);
            if(find(states.begin(),states.end(),t)==states.end())
            {   
                states.push_back(t);
                q.push(t);
            }
        }
        dfa.push_back(v);
    }
    printdfa(states,dfa);
}