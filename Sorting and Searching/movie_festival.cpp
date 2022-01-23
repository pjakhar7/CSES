#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>

#define ll long long

using namespace std;

int main(){
    int n;
    cin >> n;
    ll x , y;
    
    vector< pair<ll,ll> > times;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        times.push_back(make_pair(x,y));
    }
    sort(times.begin(), times.end());
    ll end =times[0].second;
    ll res = 1;
    for(int i=1; i<n; i++ ){
        if(times[i].first >= end){
            res++;
            end = times[i].second;
        }
        else{
            end = min(end, times[i].second);
        }
    }
    cout << res << endl;
    return 0;
}