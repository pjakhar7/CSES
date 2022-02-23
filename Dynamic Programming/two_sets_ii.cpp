
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

ll power(int b, int p){
    if(p==0)
        return 1;
    else if(p==1)
        return b;
    else if(p%2==0)
        return (((power(b, p/2)%mod)*(power(b, p/2)%mod))%mod);
    else 
        return (power(b, p-1)%mod*b%mod);
}

ll inv(int b){
    return power(2, mod-2)%mod;
}
int main(){
    int n;
    cin >> n;
    int x = (n*(n+1))/2;
    if(x%2 == 1){
        cout << 0 << endl;
        return 0;
    }
    x /= 2;
    ll dp[n+1][x+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=x; j++){
            if(j==0)
                dp[i][j] = 1;
            else{
                dp[i][j] = dp[i-1][j]%mod;
                if(j-i>=0)
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-i])%mod;
            }
        }
    }
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=x; j++){
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }
    // cout << inv(2) << endl;
    cout << (((dp[n][x])%mod)*(500000004%mod))%mod << endl;

    return 0;
}