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

using namespace std;

#define vi vector<int>
#define pii pair<int,int>
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

ll dist[2501];

void printcycle(int s, vi &parent, int start){
    if(s==start)
        return;
    printcycle(parent[s], parent, start);
    put(s);
}

int main(){
    ll n, m;
    get(n);
    get(m);
    // put(n);
    // put(m);
    vector< tuple<ll,ll,ll> > edges;
    ll x,y,w;
    loop(i, 0, m){
        cin >> x >> y >> w;
        edges.pb(make_tuple(x,y,w));
    }
    loop(i, 0, n+1)
        dist[i] = inf;
    dist[1] = 0;
    vector<int> parent(n+1, -1);
    int change = 0;
    loop(i, 1, n+1){
        change = 0;
        for(auto [x,y,w]: edges){
            if(dist[y]>dist[x]+w){
                dist[y] = dist[x] + w;
                parent[y] = x;
                change = y;
            }
        }
    }
    if(!change){
        putl("NO");
        return 0;
    }
    vi ans;
    loop(i, 0, n)
        change = parent[change];
    putl("YES");
    put(change);
    printcycle(parent[change], parent, change);
    put(change);
    put("\n");
    return 0;
}