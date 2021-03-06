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

ll dp[1000001];
int coins[101];

int main(){
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++)
        cin >> coins[i];
    for(int i=0; i<1000001; i++)
        dp[i] = 0;
    for(int i=1; i<=x; i++){
        for(int w=0; w<n; w++){
            if(i-coins[w]>=0)
                dp[i] = min(dp[i], 1 + dp[i-coins[w]]);
        }
    }
    cout << (dp[x] == INT32_MAX ? -1 : dp[x]);
    return 0;
}