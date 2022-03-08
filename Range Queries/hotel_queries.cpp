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
#define seea(A, a, b) for(int i=a; i<b; i++){cout << A[i];}

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
ll n;
ll stree[2*(int)1e6+2];

ll findhotel(ll x){
    ll k=1;
    ll res = inf;
    while(k<n){
        if(stree[2*k]>=x){
            k = 2*k;
        }
        else{
            k = 2*k+1;
        }
    }
    return k-n;
}

void update(ll k, ll x){
    k += n;
    stree[k] = x;
    for(k /= 2; k>=1; k/=2){
        stree[k] = max(stree[2*k],stree[2*k+1]);
    }
}

int main(){
    ll q;
    cin >> n >> q;
    ll orign = n;
    n = ll(pow(2,ceil(log2(n))));
    // putl(n);
    // putl(2*ll(1e6)+2);
    ll x;
    memset(stree, 0, sizeof(stree));
    loop(i, 0, orign){
        cin >> x;
        update(i, x);
    }
    ll a, b, t;
    loop(i, 0, q){
        cin >> t;
        if(t>stree[1]){
            put(0);
        }
        else{
            ll k = findhotel(t); 
            put(k+1);
            update(k, stree[n+k]-t);
        }
    }
   
    return 0;
}