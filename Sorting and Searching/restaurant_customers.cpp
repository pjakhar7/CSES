#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>

#define ll long long

using namespace std;

int main(){
    ll n;
    vector< pair<ll,ll> > arr;
    ll x , y;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        arr.push_back( make_pair(x,1));
        arr.push_back( make_pair(y,2));
    }
    sort(arr.begin(), arr.end());
    ll res = 0;
    ll ans = -1;
    for(auto t : arr){
        // cout << t.first << "  " << t.second << endl;
        if(t.second == 1)
            res++;
        else 
            res--;
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}