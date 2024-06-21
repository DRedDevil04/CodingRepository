#include <bits/stdc++.h>
using namespace std;
 




#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <set>
#include <string>
#include <cctype>
#include <numeric>
#include <string>
#include <climits>
#include <bitset>
#include <chrono>
 
using namespace std;
 
#ifndef ONLINE_JUDGE    
#define debug(x) cerr << #x << " ";  _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
// #define ll long long int
// #define int long long int
#define vint vector<int>
#define vlong vector<ll>
#define mod1 1000000007
#define mod2  998244353
#define pi 3.141592653589793238462643
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
#define all(x)  x.begin(), x.end()
#define iint(n) int n; cin >> n;
#define ill(n) ll n; cin >> n;
#define istr(n) string n; cin >> n;
#define print(n) cout << (n) << endl
#define prll(n) cout << (n) << endl
#define prstr(s) cout << (s) << endl
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define mp make_pair
#define vpii vector<pii>
#define vpll vector<pll>
#define vstr vector<string>
#define ipii(p) pii p; cin >> p.ff >> p.ss;
#define pyes cout << "YES" << endl
#define pno cout << "NO" << endl
#define getSet(x) __builtin_popcountll(x)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); 

#define sz(v) (int) v.size()
#define ivec1(v,n) vint v; loop(,0,n-1) {iint(_); v.pb(__);}
#define input1(v,n) loop(,0,n-1) {iint(_); v.pb(__);}
#define ivec2(v,n) vlong v; loop(,0,n-1) {ill(_); v.pb(__);}
#define input2(v,n) loop(,0,n-1) {ill(_); v.pb(__);}
#define prvec(arr,n) loop(,0,n-1){ cout << arr[] << " ";} cout << endl;
#define vsort(vc) sort(all(vc))
#define vrsort(vc) sort(vc.rbegin(),vc.rend())
 
void _print(bool t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(deque <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(deque <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//set in decreasing order
/*
auto cmp = [](pii const &x, pii const &y) {
            return x > y;
};
set<pii, decltype(cmp)> v(cmp);

bool cmp(pair<string,int> p1,pair<string,int> p2){
    if (p1.ss != p2.ss)
        return p1.ss > p2.ss;
    return p1.ff < p2.ff;
}
remove all consecutive duplicacy
v.erase(unique(all(v)),v.end());
count unique;
distance(v.begin(),unique(all(v)));
*/

//-------------------------------------------------------------------------------------------------
using namespace std::chrono;


// C++ program for Merge Sort
#include <bits/stdc++.h>
using namespace std;
long long swap_ct=0;

void swap(vint &arr, int i, int j) {
    swap_ct++;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Returns number of ways to
// reach s'th stair
int numberOfPaths(int n, int m, vector<vector<int>> &DP)
{
 
    if (n == 1 || m == 1)
        return DP[n][m] = 1;
 
    // Add the element in the DP table
    // If it was not computed before
    if (DP[n][m] == 0)
        DP[n][m] = numberOfPaths(n - 1, m, DP)
                   + numberOfPaths(n, m - 1, DP);
 
    return DP[n][m];
}
void printArray(vint &arr, int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


void solve(int n){
    // cout << n << endl;
    swap_ct=0;
    vector<vector<int>> dp (n+1,vector<int> (n+1,0));
    // vector<int> arr;
    // int maxi = 1e5;

    // for (int i = 0;i < n;i++){
    //     // arr.push_back(rand()%(maxi));
    //     arr.push_back(i+1);
    // }
    // int ans=0;
    
    auto start = high_resolution_clock::now();
    int ans=numberOfPaths(n,n,dp);
    auto stop = high_resolution_clock::now();
    // cout<<endl;
    // printArray(arr,n);
    // auto start1 = high_resolution_clock::now();
    
    // ans=countInversions(arr,n);
    // auto stop1 = high_resolution_clock::now();
    // cout<<ct<<endl;
    auto duration = duration_cast<microseconds>(stop - start);
    // auto duration1=  duration_cast<microseconds>(stop1 - start1);
    cout << (duration).count() << endl;
    // cout<<swap_ct<<endl;
}

//-------------------------------------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt","w",stderr);
#endif   
    int t; 
    cin >> t;

    for (int j = 1;j <= t;j++){
        // cout<<j<<endl;
        solve(j*1);
    }
    // solve2();

    return 0;
}

