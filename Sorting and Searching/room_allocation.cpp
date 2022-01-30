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

bool func(const pair<pair<ll,ll>,ll> &a, const pair<pair<ll,ll>,ll> &b){
    if (a.first.first<b.first.first)
        return true;
    else if (a.first.first==b.first.first && a.first.second<b.first.second)
        return true;
    else    
        return false;
    
}

int main(){
    ll n;
    cin >> n;
    vector< pair<pair<ll,ll>,ll>> custs;
    ll a, b;
    map<pair<ll,ll>, ll> ind;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        auto t = make_pair(a,b);
        custs.push_back(make_pair(t,i));
    }
    sort(custs.begin(), custs.end(), func);
    ll res = 1;
    ll cursum = 0;
    ll arr[n] ;
    multiset< pair<ll,ll>> rooms;
    rooms.insert(make_pair(custs[0].first.second, 1));
    for(int i=1; i<n; i++){
        if(custs[i].first.first > rooms.begin()->first){
            int k = rooms.begin()->second;
            rooms.erase(rooms.begin());
            rooms.insert({custs[i].first.second,k});
            arr[custs[i].second] = k;
        }
        else{
            int k = (int)rooms.size()+1;
            rooms.insert({custs[i].first.second,k});
            arr[custs[i].second] = k;
        }
    }
    arr[custs[0].second] = 1;
    cout << int(rooms.size()) << endl;
    for(int i=0; i<n; i++)
        cout << arr[i] << " "; 
    cout << endl;
    return 0;
}