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
#include <tuple>
#include <stack>

using namespace std;

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define sz size()
#define NL cout << "\n";
#define loop(i, a, b) for(int i=a; i<b; i++)
#define loopr(i, a, b) for(int i=a; i>b; i--)
#define geta(A, a, b) for(int i=a; i<b; i++){cin >> A[i];}
#define getv(v, a, b) for(int i=a; i<b; i++){int x; cin >> x; v.push_back(x);}
#define gets(s, a, b) for(int i=a; i<b; i++){int x; cin >> x; s.insert(x);}
#define seea(A, a, b) for(int i=a; i<b; i++){cout << A[i]<<" ";}cout <<"\n";

// template<typename... T> 
// void put(T&... args){
//     cout << a << " ";
// }
template<typename... T>
void get(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}

typedef long long ll;
typedef long double ld;

const ll mod = 1e9+7;
const ll inf = 1LL<<60;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
int heights[200005];
int dist[200005];

void dfs1(int cur, int par, vi adjl[]){
    int depth=0;
    loop(i, 0, adjl[cur].sz){
        int u = adjl[cur][i];
        if(u != par){
            dfs1(u, cur, adjl);
            depth = max(depth, heights[u]);
        }
    }
    heights[cur] = depth + 1;
}

void dfs2(int cur, int par, vi adjl[]){
    int max1 = 0, max2 = 0;
    
    for(auto u: adjl[cur]){
        if (u != par){
            if(heights[u]>=max1){
                max2 = max1;
                max1 = heights[u];
            }
            else if(heights[u]>max2){
                max2 = heights[u];
            }
        }
    }

    for(auto u: adjl[cur]){
        if(u != par){

            if(max1 == heights[u]){
                dist[u] = 1 + max(1+max2, dist[cur]);
            }
            else 
                dist[u] = 1 + max(1+max1, dist[cur]);
            dfs2(u, cur, adjl);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vi adjl[n+1];
    int a, b;
    memset(heights, 0, sizeof(heights));
    memset(dist, 0, sizeof(dist));

    loop(i, 1, n){
        cin >> a >> b; 
        adjl[a].pb(b);
        adjl[b].pb(a);
    }
    dfs1(1, 0, adjl);
    dfs2(1, 0, adjl);
    // seea(heights, 1, n+1);
    // seea(dist, 1, n+1);
    loop(i, 1, n+1){
        put(max(dist[i], heights[i])-1);
    }
    return 0;
}