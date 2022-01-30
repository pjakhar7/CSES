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

bool func(const pair<ll,ll> &a, const pair<ll,ll> &b){
    if (a.first<b.first)
        return true;
    else if((a.first==b.first) && (a.second>b.second))
        return true;
    else 
        return false;
}

bool funcrev(const pair<ll,ll> &a, const pair<ll,ll> &b){
    if (a.first>b.first)
        return true;
    else if((a.first==b.first) && (a.second<b.second))
        return true;
    else 
        return false;
}
int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> intervals;
    ll a, b;
    // cout << n << endl;
    map< pair<ll, ll>, ll> pos;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        intervals.push_back(make_pair(a,b));
        pos[make_pair(a,b)] = i;
    }
    sort(intervals.begin(), intervals.end(), func);
    // for(auto t: intervals)
    //     cout << t.first << ":" << t.second << "    ";
    // cout << endl;
    ll last = intervals[0].second;
    ll arr2[n]={0};
    for(int i=1; i<n; i++){
        if(intervals[i].second<=last){
            arr2[pos[intervals[i]]] = 1;
        }
        last = max(last, intervals[i].second);
    }
    sort(intervals.begin(), intervals.end(), funcrev);
    // for(auto t: intervals)
    //     cout << t.first << ":" << t.second << "    ";
    // cout << endl;
    ll last1 = intervals[0].second;
    ll arr1[n] = {0};
    
    for(int i=1; i<n; i++){
        if(intervals[i].second>=last1)
            arr1[pos[intervals[i]]] = 1;
        last1 = min(last1, intervals[i].second);
    }
    for(int i=0; i<n; i++)
        cout << arr1[i] << " ";
    cout << endl;
    for(int i=0; i<n; i++)
        cout << arr2[i] << " ";
    cout << endl;
    
    return 0;
}