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
int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), p(n);
    map<int,int> compress;
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i] >> p[i] ;
        b[i]++;
        compress[a[i]];
        compress[b[i]];
    }
    int t=0;
    for(auto &v : compress)
        v.second = t++;
    vector<vector<pair<int,int>>> project(t);
    for(int i=0; i<n; i++){
        project[compress[b[i]]].emplace_back(make_pair(compress[a[i]], p[i]));
    }
    vector<ll> dp(t, 0);
    for(int i=0; i<t; i++){
        if(i>0)
            dp[i] = dp[i-1];
        for(auto v: project[i]){
            dp[i] = max(dp[i], dp[v.first]+v.second);
        }
    }
    cout << dp[t-1]  << endl;

    return 0;
}