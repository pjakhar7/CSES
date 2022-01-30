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
    for(int k=0; k<n; k++){
        for(int i=k+1; i<n; i++){
            ll cursum = arr[k].first + arr[i].first;
            ll req = x - cursum;
            int a=i+1, b=n-1;
            while(a<b){
                ll checksum = arr[a].first+arr[b].first;
                if(checksum==req){
                    cout << arr[i].second+1 << " " << arr[k].second+1 << " " << arr[a].second+1 <<" " << arr[b].second+1 << "\n";
                    return 0;
                }
                if(checksum>req)
                    b--;
                else 
                    a++;
            }
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}