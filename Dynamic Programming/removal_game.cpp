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

ll dp[5001][5001];

int main(){
    int n;
    cin >> n;
    vector<ll> list(n);
    for(int i=0; i<n; i++)
        cin >> list[i];
    if(n==1){
        cout << list[0] << endl;
        return 0;
    }
    int sum = 0;
    vector<ll> pref(n+1);
    pref[0] = 0;
    for(int i=1; i<=n; i++)
        pref[i] = pref[i-1] + list[i-1];
    memset(dp, 0, sizeof(dp));
    for(int l=n-1; l>=0; l--){
        for(int r=l; r<n; r++){
            if(l==r){
                dp[l][r] = list[l];
            }
            else {
                if(l+1<n)
                    dp[l][r] = list[l] + (pref[r+1]-pref[l+1]) - dp[l+1][r];
                if(r-1>=0)
                    dp[l][r] = max(dp[l][r] , list[r] + (pref[r]-pref[l]) - dp[l][r-1]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i=0; i<n; i++){
    //     for(int j=i; j<n; j++)
    //         cout << pref[j+1]-pref[i] << " ";
    //     cout << endl;
    // }
    return 0;
}