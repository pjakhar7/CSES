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

int findparent(int x, vector<int> &parents){
    if(parents[x]==-1)
        return x;
    parents[x] = findparent(parents[x], parents);
    return parents[x];
}

bool func(vector<ll> &a, vector<ll> &b){
    return a[2]<b[2];
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<ll> > edges;
    ll a, b, c;
    loop(i, 0, m){
        cin >> a >> b >> c;
        vector<ll> t = {a,b,c};
        edges.pb(t);
    }
    sort(edges.begin(), edges.end(), func);
    vector<int> parents(n+1,-1);
    ll res = 0;
    loop(i, 0, m){
        int a, b;
        vector<ll> x = edges[i];
        a = findparent(x[0], parents);
        b = findparent(x[1], parents);
        if(a!=b){
            parents[b] = a;
            res += x[2];
        }        
    }
    int cnt=0;
    loop(i, 1, n+1)
        cnt += (parents[i]==-1? 1:0);
    if(cnt>1){
        put("IMPOSSIBLE\n");
        return 0;
    }
    put(res);
    return 0;
}