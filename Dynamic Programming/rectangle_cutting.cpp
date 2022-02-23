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
    int a, b;
    cin >> a >> b;
    vector<vector<ll>> dp(501, vector<ll> (501, INT_MAX));
    for(int i=1; i<=max(a,b); i++)
        dp[i][i] = 1;

    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            for(int k=1; k<i; k++)
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]);
            for(int k=1; k<j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]);
        }
    }
    // for(int i=0; i<=a; i++){
    //     for(int j=0; j<=b; j++){
    //         if(dp[i][j]!=INT_MAX)
    //         cout << dp[i][j] << " ";
    //         else cout << 0 << " ";}
    //     cout << endl;
    // }
    cout << dp[a][b]-1 << endl;
    return 0;
}