//IIT2022035 Devam Desai 
//DAA Assignment Q4

#include<bits/stdc++.h>
using namespace std;


bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s * s == x);
}
bool isFibonacci(int n)
{
    return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}
void nearestFibonacci(int num)
{
    if (num == 0) {
        cout << 0;
        return;
    }
    int first = 0, second = 1;
    int third = first + second;
    while (third <= num) {
        first = second;
        second = third;
        third = first + second;
    }
    int ans = ((abs(third - num)>= abs(second - num)))? second: third;
    cout << ans;
}


void solve(int n){
    vector<pair<int,int>> arr;
    int maxi = 1e5;

    for (int i = 0;i < n;i++){
        arr.push_back({rand()%(maxi),rand()%maxi});   
    }
    collinearPoints(arr); 
}
signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    solve(1000);
    return 0;
}
