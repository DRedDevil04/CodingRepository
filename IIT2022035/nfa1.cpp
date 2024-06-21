#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool nfa(vector<int> table[][3],string &s,int idx,vector<int> &finalStates, int state) {
    if (idx == s.size()) return find(finalStates.begin(),finalStates.end(),state) == finalStates.end() ? false : true;

    for (int &ele : table[state][s[idx] - 'a']) {
        if (ele == -1) return false;
        if (nfa(table,s,idx+1,finalStates,ele)) return true;
    }
    return false;
}

int main() {
    cout<<"Enter String: ";
    string s; cin>>s;
    vector<int> table[4][3] = {
       {{1},{2},{}} , {{1,3},{1},{}} , {{2},{2,3},{} },{{-1},{-1},{}}
    };
    vector<int> finalStates = { 3 };
    if (nfa(table,s,0,finalStates,0)) cout<<"Accepted\n";
    else cout<<"Rejected\n";
}