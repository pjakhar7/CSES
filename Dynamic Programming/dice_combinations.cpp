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
#include <stdio.h>
// #define ll int long long
typedef long long ll;
using namespace std;


int main(){
    int n;
    cin >> n;
    ll mod = 1000000007;
    vector<ll> dp(max(7,n+2), 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 1;
    for(int i=1; i<6; i++)
        dp[6] += dp[i];
    for(int i=7; i<=n; i++){
        for(int j=1; j<7; j++)
            dp[i] = (dp[i] + dp[i-j])%mod;
    }
    cout << dp[n] << endl;
    return 0;
}