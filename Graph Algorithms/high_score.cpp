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

ll dist[2502];
    
bool dfs(int s, vector<int> adjl[], int n, bool visited[]){
    if(s==n)
        return true;
    visited[s] = true;
    bool res = false;
    for(auto t: adjl[s]){
        if(!visited[t]){
            res |= dfs(t, adjl, n, visited);
        }
    }
    return res;
}

int main(){
    ll n, m, q;
    cin >> n >> m;
    vector<vector<ll> > edges;
    ll x,y,w;
    for(int i=1; i<=n; i++)
        dist[i] = INT32_MAX;
    // cout << n << " " << m << endl;
    for(ll i=0; i<m; i++){
        vector<ll> t(3);
        
        cin >> x >> y >> w;
        t[0] = x;
        t[1] = y;
        t[2] = -w;
        edges.push_back(t);
    }
    dist[1] = 0;
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            vector<ll> t = edges[j];
        // cout << t[0] <<" " << t[1] << " " << t[2] << endl;
            if( dist[t[1]]!=INT32_MAX && dist[t[0]]!=INT32_MAX)
                dist[t[1]] = min(dist[t[1]], dist[t[0]]+t[2]);
            else if(dist[t[1]]==INT32_MAX && dist[t[0]]!=INT32_MAX)
                dist[t[1]] = dist[t[0]]+t[2];

        // for(int i=1; i<=n; i++)
        //     cout << dist[i] << " ";
        // cout << endl;
        }
    }
    ll res = dist[n] ;
    vector<int> changes;
    for(int i=0; i<m; i++){
        vector<ll> t = edges[i];
        ll old = dist[t[1]];
        if(dist[t[1]]!=INT32_MAX && dist[t[0]]!=INT32_MAX)
            dist[t[1]] = min(dist[t[1]], dist[t[0]]+t[2]);            
        else if(dist[t[1]]==INT32_MAX && dist[t[0]]!=INT32_MAX)
            dist[t[1]] = dist[t[0]]+t[2];
        if(old!=dist[t[1]])
            changes.push_back(t[1]);
    }
    vector<int> adjl[n+1];
    for(auto t: edges)
        adjl[t[0]].push_back(t[1]);
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    for(auto t: changes){
        if(dfs(t, adjl, n, visited)){
            cout << -1 << endl;
            return 0;
        }
    }
    
    // for(int i=1; i<=n; i++)
    //     cout << dist[i] << " ";
    // cout << endl;
    cout << -dist[n] << endl;
    return 0;
}