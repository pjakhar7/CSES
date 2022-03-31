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
int n;
int ancestor[200005][50];
int depths[200005];
vi adjl[200005];

// int findpar(int cur, int k){
//     if(k>depths[cur])
//         return 0;
//     return ancestor[ancestor[cur][k-1]][k-1];
// }

// int findpar1(int cur, int k){
//     if(k>depths[cur])
//         return -1;
//     if(k==1)
//         return ancestor[cur][0];
//     if(floor(log2(k))==ceil(log2(k)))
//         return ancestor[cur][int(log2(k))];
//     return findpar1(ancestor[cur][int(log2(k))], k-pow(2,int(log2(k))));
// }


// void dfs1(int cur, int par, int depth){
//     ancestor[cur][0] = par;
//     depths[cur] = depth;
//     for(int i=1; i<=log2(depth); i++){
//         ancestor[cur][i] = ancestor[ancestor[cur][i-1]][i-1];
//     }
//     for(auto u: adjl[cur]){
//         if( u != par){
//             dfs1(u, cur, depth+1);
//         }
//     }
// }
const int SZ = 200005;
int jump[21][SZ];
int parents[SZ];
int L[SZ]; 

void dfs(int u, int p, int l) 
{
    jump[0][u] = p;
    L[u] = l;
	
	for (int v: adjl[u]) 
		if(v != p) 
		dfs(v, u, l+1);
}
 
void preprocess_LCA()
{	
	dfs(1, -1, 0);
		
	for (int i = 1; 1<<i <= n ; i++) 
	for (int j = 0; j <= n ; j++)
	jump[i][j] = jump[i-1][jump[i-1][j]];
}
 
int main(){
    // cout << log2(200005);
    int q;
    cin >> n >> q;
    int a, b;
    loop(i,2,n+1){
        cin >> a >> b;
        // parents[i] = t;
        adjl[a].pb(b);
        adjl[b].pb(a);
    }
    // dfs(1, 0, 0);
    int u, k, v;
    preprocess_LCA();
    while(q--) {
        cin >> u >> v;
        int a = u, b = v;
        int k = abs(L[u]-L[v]);
        int boss = v;
        if(L[u]>L[v]){
            int t = u;
            u = v;
            v = t;
        }
		for(int i=0; i<=20; i++)
		    if(k & (1<<i))
		        v = jump[i][v];
        if(v!=u){   
            for (int i = 20; i >= 0; i--) {
                if (jump[i][v] != jump[i][u]) {
                    v = jump[i][v];
                    u = jump[i][u];
                }
            }
            v = jump[0][v];
            u = jump[0][u];
        }
        putl(L[a]+L[b]-2*L[u]); 
    }
    return 0;
}