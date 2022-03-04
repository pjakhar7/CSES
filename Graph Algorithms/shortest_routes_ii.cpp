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

ll dist[501][501];
    
int main(){
    ll n, m, q;
    cin >> n >> m >> q;
    vector<pair<ll,ll> > adjl[n+1];
    ll x,y,w;
    memset(dist, -1, sizeof(dist));
    for(int i=1; i<=n; i++)
        dist[i][i] = 0;

    for(ll i=0; i<m; i++){
        cin >> x >> y >> w;
        if(dist[x][y]!=-1)
            dist[x][y] = min(dist[x][y], w);
        else
            dist[x][y] = w;
        if(dist[y][x]!=-1)
            dist[y][x] = min(dist[y][x], w);
        else
            dist[y][x] = w;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][k]!= -1 && dist[k][j]!= -1 && dist[i][j]!=-1)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                if(dist[i][k]!= -1 && dist[k][j]!= -1 && dist[i][j]==-1)
                    dist[i][j] = (dist[i][k]+dist[k][j]);
                
            }
        }
    }
    int a, b;
    while(q--){
        cin >> a >> b;
        if(dist[a][b]!=INT32_MAX)
            cout << dist[a][b] << endl;
        else
            cout << -1 << endl;
    }
    cout << endl;
    return 0;
}