#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <queue>
#include <map>
#include <set>
// #define ll int long long
typedef long long ll;
using namespace std;

ll func(int x, int i, int *coins, vector<vector<ll>> &dp){
    if(x==0)
        return 0;
    if(i==0)
        return INT64_MAX;
    if(dp[x][i]!=-1)
        return dp[x][i];
    ll a = func(x, i-1, coins, dp);
    if(x-coins[i]>0){
        ll b = func(x-coins[i], i, coins, dp);
        dp[x][i] = min(a, b+1);
        return dp[x][i];
    }
    dp[x][i] = dp[x][i-1];
    return dp[x][i];
}

int main(){
    int n, x;
    cin >> n >> x;
    int coins[n];
    for(int i=0; i<n; i++)
        cin >> coins[i];
    ll dp[x+1][n+1];
    vector<vector<ll>> dp(x+1, vector<ll> (n+1,-1));
    for(int i=0; i<=x; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = -1;

    ll res = func(x, i, coins, dp);
    return 0;
}