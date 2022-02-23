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

void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited){
    visited[i][j] = true;
    int n = grid.size();
    int m = grid[0].size();
    if(i+1<n && grid[i+1][j]=='.' && !visited[i+1][j])
        bfs(i+1, j, grid, visited);
    if(j+1<m && grid[i][j+1]=='.' && !visited[i][j+1])
        bfs(i, j+1, grid, visited);
    if(i-1>=0 && grid[i-1][j]=='.' && !visited[i-1][j])
        bfs(i-1, j, grid, visited);
    if(j-1>=0 && grid[i][j-1]=='.' && !visited[i][j-1])
        bfs(i, j-1, grid, visited);
        
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char> (m, ' '));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >> grid[i][j];
    }
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    int res = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='.' && !visited[i][j]){
                // cout << i << " : " << j << endl;
                bfs(i, j, grid, visited);
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}