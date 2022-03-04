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
typedef long long ll;
using namespace std;
const int mod = 1e9+7;

bool dfs(vector<int> adj_list[], int n, int dist[], int pred[], bool visited[]){
    queue<int> qu;
    qu.push(1);
    visited[1] = true;
    while(!qu.empty()){
        int k = qu.front();
        qu.pop();
        // cout << k << " ssss   ";
        for(int i=0; i<adj_list[k].size(); i++){
            int x = adj_list[k][i];
            if(!visited[x]){
                visited[x] = true;
                dist[x] = dist[k] + 1;
                pred[x] = k;
                // cout << x << " ";
                qu.push(x);
                if(x==n){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj_list[n+1];
    int x, y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    int dist[n+1];
    int pred[n+1];
    bool visited[n+1];
    for(int i=0; i<=n; i++){
        dist[i] = INT_MAX;
        pred[i] = -1;
        visited[i] = false; 
    }
    dist[1] = 0;
    if(dfs(adj_list, n, dist, pred, visited)){
        cout << dist[n]+1 << endl;
        vector<int> path;
        path.push_back(n);
        int k = pred[n];
        while(k!=-1){
            path.push_back(k);
            k = pred[k];
        }
        reverse(path.begin(), path.end());
        for(auto x: path)
            cout << x << " ";
    }
    else{
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}