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
#include <cstring>
typedef long long ll;
using namespace std;
const int mod = 1e9+7;


int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    ll dp[m+1][n];
    memset(dp, 0, sizeof(dp));
    if(arr[0]!=0){
        dp[arr[0]][0] = 1;
    }
    else{
        for(int i=1; i<=m; i++)
            dp[i][0] = 1;
    }
    for(int i=1; i<n; i++){
        int x = arr[i];
        if(x!=0){
            dp[x][i] = (dp[x-1][i-1]+dp[x][i-1])%mod;
            if(x<m)
                dp[x][i] = (dp[x][i]+dp[x+1][i-1])%mod; 
        }
        else{
        for(int j=1; j<=m; j++){
            dp[j][i] = (dp[j-1][i-1]+dp[j][i-1])%mod;
            if(j<m)
                dp[j][i] = (dp[j][i]+dp[j+1][i-1])%mod;
            }
        }
    }
    if(arr[n-1]!=0)
        cout << dp[arr[n-1]][n-1] << endl;
    else{
        ll res = 0;
        for(int i=1; i<=m; i++){
            res = (res+dp[i][n-1])%mod;
        }
        cout << res << endl;
    }
    return 0;
}