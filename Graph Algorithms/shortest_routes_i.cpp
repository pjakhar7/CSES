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
#include <cstring>
// #define ll ll long long
typedef long long ll;
using namespace std;
bool visited[100002];
ll dist[100002];
multiset<pair<ll,ll> > rem_vex;
set<ll> vex;
    
int main(){
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll> > adjl[n+1];
    ll x,y,w;
    for(ll i=0; i<m; i++){
        cin >> x >> y >> w;
        adjl[x].push_back(make_pair(y, w));
    }
    memset(visited, false, sizeof(visited));
    memset(dist, 999999, sizeof(dist));
    dist[1] = 0;
    for(ll i=1; i<=n; i++)
        rem_vex.insert(make_pair(dist[i], i));
    while(!rem_vex.empty()){
        auto t = *rem_vex.begin();
        rem_vex.erase(rem_vex.begin());
        for(ll i=0; i<adjl[t.second].size(); i++){
            ll y = adjl[t.second][i].first;
            ll w = adjl[t.second][i].second;
            if(t.first+w<dist[y]){
                rem_vex.erase(make_pair(dist[y], y));
                dist[y] = t.first+w;
                rem_vex.insert(make_pair(dist[y], y));
            }
        }
    }

    for(ll i=1; i<=n; i++)
        cout << dist[i] << " ";
    cout << endl;
    return 0;
}