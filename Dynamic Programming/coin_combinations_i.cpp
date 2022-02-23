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

int dp[1000001];
int coins[101];
const int mod = 1000000007;
int main(){
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++)
        cin >> coins[i];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=1; i<=x; i++){
        for(int w=0; w<n; w++){
            if(i-coins[w]>=0)
                dp[i] = (dp[i] + dp[i-coins[w]])%mod;
        }
    }
    cout << dp[x];
    return 0;
}