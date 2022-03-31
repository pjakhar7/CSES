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
#define SZ 600005
const ll mod = 1e9+7;
const ll inf = 1LL<<60;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
int N;
ll vals[SZ];
map<ll,ll> indices;
ll nstrees[SZ];
vi valss;
vl pathsums;
vi adjl[SZ];
ll stree[2*SZ];

void dfs(int cur, int par, int sum){
    sum += vals[cur];
    valss.pb(cur);
    pathsums.pb(sum);
    int nsubtrees = 1;
    for(auto u: adjl[cur]){
        if(u!=par){
            dfs(u, cur, sum);
            nsubtrees += nstrees[u];
        }
    }
    nstrees[cur] = nsubtrees;
}

void update(int s, int x){
    s += N;
    int oldx = stree[s];
    while(s){
        stree[s] += x-oldx;
        s /= 2;
    }
}

ll find(int s){
    int l = N+indices[s];
    int r = l + nstrees[s]-1;
    // cout << l <<"  " << r << endl;
    ll res = 0;
    while(l<=r){
        if(l%2==1) { res += stree[l++]; }
        if(r%2==0) { res += stree[r--];}
        l /= 2;
        r /= 2;
        // cout << endl;
    }
    // cout << res << endl;
    return res;
}

int main(){
    ll n, q;
    cin >> n >> q;
    int a, b; 
    N = pow(2, ceil(log2(n)));
    loop(i, 1, n+1)
        cin >> vals[i];
    loop(i, 1, n){
        cin >> a >> b; 
        adjl[a].pb(b);
        adjl[b].pb(a);
    }
    dfs(1,0,0);
    loop(i, 0, n){
        update(i, pathsums[i]);
        indices[valss[i]] = i;
    }
    // seea(stree, 0, 2*N);
    // seea(indices,0,N);
    // seea(nstrees, 0, N);
    int j=1;
    // loop(i, 0, log2(N)+1){
    //     loop(k, 0, pow(2,i)){
    //         put(stree[j]);
    //         j++;
    //     }
    //     cout << endl;
    // }
    int c;
    while(q--){
        cin >> a >> b;
        if(a==2){
            putl(find(b));
        }
        else{
            cin >> c; 
            update(indices[b], c);
        }
    }
    return 0;
}