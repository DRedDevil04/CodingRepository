#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool nfa(vector<int> table[][3],string &s,int idx,vector<int> &finalStates, int state,set<int> clos[4]) {
    if (idx == s.size()) return find(finalStates.begin(),finalStates.end(),state) == finalStates.end() ? false : true;

    for (int &ele : table[state][s[idx] - 'a']) {
        if (ele == -1) return false;
        if (nfa(table,s,idx+1,finalStates,ele,clos)) return true;
    }
     for (auto p : clos[state]) {
        for (int &ele : table[p][s[idx] - 'a']) {
        if (ele == -1) return false;
        if (nfa(table,s,idx+1,finalStates,ele,clos)) return true;
    }
    }
    return false;
}
void epsilon_closure(vector<int> table[][3],set<int> closure[4],int state){
    if(closure[state].size()==0){
        for(auto x: table[state][2]){
            epsilon_closure(table,closure,x);
            closure[state].insert(x);
            for(auto y: closure[x]){
                closure[state].insert(y);
            }
        }
    }
    else{
        return;
    }
}
int main() {
    cout<<"Enter String: ";
    string s; cin>>s;
    vector<int> table[4][3] = {
        {{1},{2},{}} , {{1,3},{1},{}} , {{2},{2,3},{} },{{-1},{-1},{}}
    };
    set<int> clos[4];

    epsilon_closure(table,clos,0);
    epsilon_closure(table,clos,1);
    epsilon_closure(table,clos,2);
    epsilon_closure(table,clos,3);
    clos[0].insert(0);
    clos[1].insert(1);
    clos[2].insert(2);
    clos[3].insert(3);
    vector<int> finalStates = { 3 };
    if (nfa(table,s,0,finalStates,0,clos)) cout<<"Accepted\n";
    else cout<<"Rejected\n";
    for(auto x: clos[0]){
        cout<<x<<" ";
    }
    return 0;
}