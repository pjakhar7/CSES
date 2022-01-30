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
    vector<pair<ll,ll>> arr(n);
    ll t;
    for(int i=0; i<n; i++){
        cin >> t;
        arr[i] = make_pair(t,i);
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int lo=j+1, hi=n-1,mid;
            ll cursum = arr[i].first+arr[j].first;
            if(cursum>x)
                break;
            ll req = x-cursum;
            while(lo<=hi){
                mid=(lo+hi)/2;
                if(arr[mid].first==req){
                    cout << arr[i].second+1 << " " << arr[j].second+1 << " " << arr[mid].second+1 << "\n";
                    return 0;
                }
                if(arr[mid].first<req)
                    lo = mid+1;
                else 
                    hi = mid-1;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}