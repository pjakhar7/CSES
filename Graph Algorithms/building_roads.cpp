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
void dfs(int s, vector<int> adj_list[], set<int> &vertices, int n){
    visited[s] = true;
    vertices.erase(s);
    for(int i=0; i<adj_list[s].size(); i++){
        int k = adj_list[s][i];
        if(!visited[k]){
            dfs(k, adj_list, vertices, n);
        }
    }
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
    memset(visited, false, sizeof(visited));
    vector<int> setleaders;
    set<int> vertices;
    for(int i=1; i<=n; i++)
        vertices.insert(i);
    while(vertices.size()){
        setleaders.push_back(*vertices.begin());
        dfs(*vertices.begin(), adj_list, vertices, n);
    }
    cout << setleaders.size()-1 << endl;
    if(setleaders.size()>1){
        for(int i=0; i<setleaders.size()-1; i++){
            cout << setleaders[i] << " " << setleaders[i+1]  << "\n";
        }
    }
    return 0;
}