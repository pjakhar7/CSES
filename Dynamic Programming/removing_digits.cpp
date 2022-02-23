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
int main(){
    int x;
    cin >> x ;
    // memset(dp, INT_MAX, sizeof(dp));
    for(int i=0; i<1000001; i++)
        dp[i] = INT_MAX;
    for(int i=1; i<=9; i++)
        dp[i] = 1;
    for(int i=10; i<=x; i++){
        int curmin=INT_MAX;
        int n = i;
        // cout << dp[10] <<" LSLS  ";
        while(n){
            // cout << curmin << "  :  "<< n <<endl;
            curmin = min(curmin, dp[i-(n%10)]);
            // cout << curmin << "  :  "<< n <<endl;
            n /= 10;
        }
        dp[i] = 1+curmin;
    }
    cout << dp[x]<<endl;
    return 0;
}