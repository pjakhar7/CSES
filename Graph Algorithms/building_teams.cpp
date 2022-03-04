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
bool visited[100002];
int colour[100002];
void bfs(int s, vector<int> adj_list[], set<int> &vertices, int n){
    visited[s] = true;
    vertices.erase(s);
    queue<int> qu;
    qu.push(s);
    
    while(!qu.empty()){
        int x = qu.front();
        qu.pop();
        visited[x] = true;
        vertices.erase(x);
        for(int i=0; i<adj_list[x].size(); i++){
            int k = adj_list[x][i];
            if(!visited[k]){
                // cout << k << " == KK  --- " << colour[x] << "  :  " << int(colour[x]^2) << endl;
                colour[k] = int(colour[x]^2);
                qu.push(k);
            }
        }
    }
    
    // for(int i=1; i<=n; i++)
    //     cout << colour[i] << " ";
    // cout << endl;
}

int main(){
    int n, m;
    // cout <<int(1^2) << endl;
    // cout << int((1^2)^2) << endl;
    cin >> n >> m;
    vector<int> adj_list[n+1];
    int x, y;
    vector<pair<int,int>> edges;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        edges.push_back(make_pair(x,y));
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(colour, 0, sizeof(colour));
    vector<int> setleaders;
    set<int> vertices;
    for(int i=1; i<=n; i++)
        vertices.insert(i);
    while(vertices.size()){
        int s = *vertices.begin();
        setleaders.push_back(x);
        colour[s] = 1;
        bfs(s, adj_list, vertices, n);
    }

    for(auto x: edges){
        if(colour[x.first]==colour[x.second]){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for(int i=1; i<=n; i++){
        // cout << colour[i] << " ";
        if(colour[i]==3)
            cout << 2 << " ";
        else 
            cout << 1 << " ";
    }

    return 0;
}