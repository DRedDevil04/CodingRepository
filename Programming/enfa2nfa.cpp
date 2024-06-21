/* Devam Desai
IIT2022035	Lab Assignment 4*/






/*

Input for NFA given in assignment :
3
2
1
0
2
0 1
0
1
2
1
2
1
2


*/


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
    // cout<<"  STATE/INPUT  ";
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
vector<int> closure(int s,vector<vector<vector<int> > > v){
    vector<int> t;
    queue<int> q;
    t.push_back(s);
    int a=v[s][v[s].size()-1].size();
    for(int i=0;i<a;i++){
        t.push_back(v[s][v[s].size()-1][i]);
        //cout<<"t[i]"<<t[i]<<endl;
        q.push(t[i]);
    }
    while(!q.empty()){
        int f=q.front();
        q.pop();
        if(!v[f][v[f].size()-1].empty()){
            int u=v[f][v[f].size()-1].size();
            for(int i=0;i<u;i++){
                int y=v[f][v[f].size()-1][i];
                if(find(t.begin(),t.end(),y)==t.end()){
                    //cout<<"y"<<y<<endl;
                    t.push_back(y);
                    q.push(y);
                }
            }
        }
    }
    return t;
}
int main(){
    int n,alpha;
    
    cout<<"Enter total number of states in NFA : ";//3
    cin>>n;
    cout<<"Enter number of elements in alphabet : "; //2
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
        vector<int> t;
        cout<<"Enter no. of output states for input ^ : ";
        cin>>yn;
        cout<<"Enter output states :"<<endl;
        for(int k=0;k<yn;k++){
            cin>>y;
            t.push_back(y);
        }
        v.push_back(t);
        table.push_back(v);
    }
    cout<<"Epsilon-NFA"<<endl;
    print(table);
   cout<<"NFA"<<endl;
    vector<vector<vector<int> > > nfa;
    for(int i=0;i<n;i++){
        set<int>
    }
    
    printdfa(states,nfa);
}