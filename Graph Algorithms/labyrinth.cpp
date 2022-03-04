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

pair<int,int> start;
pair<int,int> endp;
vector<vector<bool>> visited;

void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<ll>> &dist){
    int n = grid.size();
    int m = grid[0].size();
    visited[i][j] = true;
    // cout << i << " : " << j << endl;
    if(grid[i][j]=='B'){
        dist[i][j] = 0;
        return;
    }
    if(i+1<n && (grid[i+1][j]=='.'||grid[i+1][j]=='B')&& !visited[i+1][j] && dist[i+1][j]==INT_MAX){
        bfs(i+1, j, grid, dist);
        dist[i][j] = min(dist[i][j], 1+dist[i+1][j]);
    }
    if(j+1<m && (grid[i][j+1]=='.'||grid[i][j+1]=='B')&& !visited[i][j+1] && dist[i][j+1]==INT_MAX){
        bfs(i, j+1, grid, dist);
        dist[i][j] = min(dist[i][j], 1+dist[i][j+1]);
    }
    if(i-1>=0 && (grid[i-1][j]=='.'||grid[i-1][j]=='B')&& !visited[i-1][j] && dist[i-1][j]==INT_MAX){
        bfs(i-1, j, grid, dist);
        dist[i][j] = min(dist[i][j], 1+dist[i-1][j]);        
    }
    if(j-1>=0 && (grid[i][j-1]=='.'||grid[i][j-1]=='B')&& !visited[i][j-1] && dist[i][j-1]==INT_MAX){
        bfs(i, j-1, grid, dist);       
        dist[i][j] = min(dist[i][j], 1+dist[i][j-1]);
    }
     if(i+1<n && (grid[i+1][j]=='.'||grid[i+1][j]=='B')){
        dist[i][j] = min(dist[i][j], 1+dist[i+1][j]);
    }
    if(j+1<m && (grid[i][j+1]=='.'||grid[i][j+1]=='B')){
        dist[i][j] = min(dist[i][j], 1+dist[i][j+1]);
    }
    if(i-1>=0 && (grid[i-1][j]=='.'||grid[i-1][j]=='B') ){
        dist[i][j] = min(dist[i][j], 1+dist[i-1][j]);        
    }
    if(j-1>=0 && (grid[i][j-1]=='.'||grid[i][j-1]=='B') ){
        dist[i][j] = min(dist[i][j], 1+dist[i][j-1]);
    }  
}

void bfs2(int i, int j, vector<vector<char>> &grid, vector<vector<ll>> &dist, string &path){
    int n = grid.size();
    int m = grid[0].size();
    if(grid[i][j]=='B'){
        return;
    }
    int curdist = dist[i][j];
    if(i+1<n && (grid[i+1][j]=='.'||grid[i+1][j]=='B') && dist[i+1][j]==curdist-1){
        path += "D";
        bfs2(i+1, j, grid, dist, path);
        return;
    }
    if(j+1<m && (grid[i][j+1]=='.'||grid[i][j+1]=='B')&& dist[i][j+1]==curdist-1){
        path += "R";
        bfs2(i, j+1, grid, dist, path);
        return;
    }
    if(i-1>=0 && (grid[i-1][j]=='.'||grid[i-1][j]=='B')&& dist[i-1][j]==curdist-1){
        path += "U";
        bfs2(i-1, j, grid, dist, path);
        return;        
    }
    if(j-1>=0 && (grid[i][j-1]=='.'||grid[i][j-1]=='B')&& dist[i][j-1]==curdist-1){
        path += "L";
        bfs2(i, j-1, grid, dist, path);
        return ;
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char> (m, ' '));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >> grid[i][j];
    }
    for(int i=0; i<n; i++){
        vector<bool> t(m, false);
        visited.push_back(t  );
        }
    vector<vector<ll>> dist(n, vector<ll> (m, INT_MAX));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='A' ){
                start.first = i;
                start.second = j;
            }
        }
    }
    bfs(start.first, start.second, grid, dist);
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if(dist[i][j]!=INT_MAX)
    //         cout << dist[i][j] << " ";
    //         else 
    //             cout << -1 << " ";
    //     }
    //     cout << endl;
    // }
    if(dist[start.first][start.second]==INT_MAX){
        cout << "NO\n";
        return 0;
    }
    string path = "";
    bfs2(start.first, start.second, grid, dist, path);
    cout << "YES\n";
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    cout << path << endl; 

    return 0;
}