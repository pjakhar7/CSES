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

int dp[101][1000001];
int coins[101];
const int mod = 1000000007;
int main(){
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++)
        cin >> coins[i];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=x; j++){
            dp[i][j] = dp[i-1][j];
            if(j>=coins[i-1])
                dp[i][j] = (dp[i][j] + dp[i][j-coins[i-1]])%mod;
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<=x; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;}
    cout << dp[n][x] << endl;;
    return 0;
}