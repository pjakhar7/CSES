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
    ll n, t;
    cin >> n >> t;
    ll arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    ll res = 0;
    ll low=0, mid, high=__INT64_MAX__;

    while(low<=high){
        mid = (low+high)/2;
        ll cur = 0;
        for(int i=0; i<n; i++){
            cur += ll(mid/arr[i]);
            if(cur>t) 
                break;   
        }
        if(cur < t){
            low = mid+1;
        }
        else {
            res = mid;
            high = mid-1;
        }
    }

    cout << res << endl;

    return 0;
}