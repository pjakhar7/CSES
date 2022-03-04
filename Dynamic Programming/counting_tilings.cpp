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
const int num = (int)1e6; 
ll dp[11][1001][1200];
int main(){
    memset(dp, 0, sizeof(dp));
    int n, m;
    cin >> n >> m;
    dp[0][0][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for( int p=0; p<(2<<n);p++){
                if (p&(1<<j)){
                    int q = p - (1<<j);
                    if(j+1<n)
                        dp[i][j+1][q] = (dp[i][j+1][q] + dp[i][j][p])%mod;
                }
                else{
                    int q = p + (1<<j);
                    dp[i][j+1][q] = (dp[i][j+1][q] + dp[i][j][p])%mod;
                    if (j+1<n && p&(1<<(j+1))){
                        int q = p + (1<<(j+1));
                        dp[i][j+1][q] = (dp[i][j+1][q] + dp[i][j][p])%mod;
                    }

                }
            }
        }
    }
    
    cout << dp[m-1][n-1][0]<< endl;
    return 0;
}