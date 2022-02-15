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
    ll n, k;
    cin >> n >> k;
    ll a, b;
    vector<pair<ll,ll>> intervals;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        intervals.push_back(make_pair(a,b));
    }
    sort(intervals.begin(), intervals.end());
    multiset<ll> members;
    ll res = 1;
    members.insert(intervals[0].second);
    for(int i=1; i<n; i++){
        cout << intervals[i].first << ":" << intervals[i].second ;
        if(intervals[i].first>*members.begin()){
            members.erase(members.begin());
            members.insert(intervals[i].second);
            res++;
        }
        if((ll)members.size()<k){
            members.insert(intervals[i].second);
            res++;
        }
        cout << "  " << res << endl;
    }

    cout << res << endl;
    return 0;
}