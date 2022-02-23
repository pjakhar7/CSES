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
const int mod = (int)1e9+7;
int dp[1001][1001];
int main(){
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char> (n, '.'));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    }
    if(grid[n-1][n-1]=='*' || grid[0][0]=='*'){
        cout << 0 << endl;
        return 0;
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++)
    //         cout << grid[i][j];
    //     cout << endl;
    // }
    
    memset(dp, 0, sizeof(dp));
    dp[n-1][n-1] = 1;
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(j+1<n && grid[i][j+1] != '*')
                dp[i][j] =(dp[i][j] + dp[i][j+1])%mod;
            if(i+1<n && grid[i+1][j] != '*')
                dp[i][j] = (dp[i][j] + dp[i+1][j])%mod;
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[0][0]<<endl;
    return 0;
}