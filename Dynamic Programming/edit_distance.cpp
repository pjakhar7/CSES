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

int dp[5001][5001];

const int mod = 1000000007;
int main(){
    int n, m;
    string a, b;
    cin >> a ;
    cin >> b;
    n = a.size();
    m = b.size();
    // cout << a << endl;
    // cout << b << endl;
    // cout << n << endl;
    // cout << m << endl;
    memset(dp, 50000, sizeof(dp));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1+min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m] <<endl;;
    return 0;
}