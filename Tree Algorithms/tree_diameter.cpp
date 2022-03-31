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

void dfs(ll s, vi edges[], vi &visited, vl &depth, ll &res){
    ll curdia = 1;
    ll maxdepth = 0;
    visited[s] = 1;
    priority_queue<ll> pq;
    loop(i, 0, edges[s].size()){
        ll k = edges[s][i];
        if(!visited[k]){
            dfs(k, edges, visited, depth, res);
            pq.push(depth[k]);
        }
    }
    if(!pq.empty()){
        depth[s] = pq.top()+1;
        pq.pop();
    }    
    else 
        depth[s] = 1;
    if(!pq.empty()){
        res = max(res, depth[s]+pq.top());
        return ;
    }
    res = max(res, depth[s]);
}

int main(){
    cin >> n;
    vi edges[n+1];
    ll a,b;

    loop(i, 0, n-1){
        cin >> a >> b; 
        edges[a].pb(b);
        edges[b].pb(a);
    }
    vi visited(n+1, 0);
    vl depth(n+1, 0);
    ll res=0;
    dfs(1, edges, visited, depth, res);
    putl(res-1);
    return 0;
}