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

void printcycle(int s, vector<int> &parent, int start){
    if(s==start){
        return;
    }
    printcycle(parent[s], parent, start);
    cout << s << " ";
}

void dfs(int s, vector<pair<ll, ll>> adjl[], int n, vector<bool> visited, int start, vector<int> path, vector<int> &res, ll cyclesum){
    
    path.push_back(s);
    if(s==start && path.size()>1 && cyclesum<0 ){
        // cout << path.size()<<endl;
        // for(auto x: path)
        //     cout << x << " ";
        // cout << endl;
        res = path;
        return ;
    }
    if(s==start && path.size()>1)
        return;
    cout << path.size()<<endl;
    for(auto x: path)
        cout << x << " ";
    cout << endl;
    visited[s] = true;
    for(auto t: adjl[s]){
        if(t.first==start)
            dfs(t.first, adjl, n, visited, start, path, res, cyclesum+t.second);
        if(!visited[t.second] ){
            dfs(t.first, adjl, n, visited, start, path, res, cyclesum+t.second);
        }
    }
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
        t[2] = w;
        edges.push_back(t);
    }
    dist[1] = 0;
    vector<int> parent(n+1, -1);
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            vector<ll> t = edges[j];
        // cout << t[0] <<" " << t[1] << " " << t[2] << endl;
            if( dist[t[1]]!=INT32_MAX && dist[t[0]]!=INT32_MAX){
                if(dist[t[0]]+t[2]< dist[t[1]])
                    parent[t[1]] = t[0];
                dist[t[1]] = min(dist[t[1]], dist[t[0]]+t[2]);
            }
            else if(dist[t[1]]==INT32_MAX && dist[t[0]]!=INT32_MAX){
                parent[t[1]] = t[0];
                dist[t[1]] = dist[t[0]]+t[2];
            }

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
        if(dist[t[1]]!=INT32_MAX && dist[t[0]]!=INT32_MAX){
            if(dist[t[0]]+t[2]< dist[t[1]])
                parent[t[1]] = t[0];
            dist[t[1]] = min(dist[t[1]], dist[t[0]]+t[2]);            
            }
        else if(dist[t[1]]==INT32_MAX && dist[t[0]]!=INT32_MAX){
            parent[t[1]] = t[0];
            dist[t[1]] = dist[t[0]]+t[2];
            }
        if(old!=dist[t[1]])
            changes.push_back(t[1]);
    }
    vector<pair<ll, ll> > adjl[n+1];
    for(auto t: edges)
        adjl[t[0]].push_back(make_pair(t[1], t[2]));
    
    vector<bool> visited(n+1, false);
    // cout << changes[0] << endl;
    if(changes.size()){
        vector<int> ans;
        vector<int> path;
        // dfs(changes[0], adjl, n, visited, changes[0], path, ans, 0);
        int c = changes[0];
        for(int i=1; i<=n; i++)
            c = parent[c];
        // for(int i=1; i<=n; i++)
        //     cout << i << ":" << parent[i] << "   ";
        // cout << endl;
        cout << "YES\n";
        cout << c << " ";
        printcycle(parent[c], parent, c);
        cout << c << " ";
        cout << endl;
    }
    else{
        cout << "NO\n"; 
    }

    return 0;
}