#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <queue>
#include <unordered_map>
// #define ll int long long
typedef long long ll;
using namespace std;


int main(){
    ll n, t;
    vector<ll> arr;
    cin >> n;
    for(ll i=0; i<n; i++){
        cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    ll res = 1;
    for(ll i=0; i<n; i++){
        if(arr[i]<=res)
            res = res + arr[i];
    }
    cout << res << endl;

    return 0;
}