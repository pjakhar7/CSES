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

bool check(ll mid, ll arr[], ll k, ll n){
    // cout << mid << endl;
    ll cnt = 1, cursum=0;
    for(int i=0; i<n; i++){
        if(arr[i]>mid){
            return false;
        }
        cursum += arr[i];
        if(cursum > mid){
            // cout << cursum << " ";
            cnt++;
            cursum = arr[i];
        }
    }
    // cout << "cnt : " << cnt << endl;
    if(cnt<=k)
        return true;
    return false;
}

int main(){
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    ll lo=1, hi=0, mid;

    for(int i=0; i<n; i++){
        cin >> arr[i];
        hi += arr[i];
    }
    ll res = 0;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(check(mid, arr, k, n)){
            res = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    cout << res << endl;
    
    return 0;
}