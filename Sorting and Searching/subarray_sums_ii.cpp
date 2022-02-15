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


int main(){
    ll n, x;
    cin >> n >> x;
    ll arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    ll res = 0;
    map<ll,ll> sums;
    // cout << sums[arr[0]] << endl;
    sums[0]++;
    // cout << sums[arr[0]] << endl;
    ll cursum = 0;
    for(int i=0; i<n; i++){
        cursum += arr[i];
        res += sums[cursum-x];
        sums[cursum]++;
    }
    cout << res << endl;
    return 0;
}