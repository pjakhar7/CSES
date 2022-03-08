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

ll finmin(ll a, ll b){
    a += n;
    b += n;
    ll res = inf;
    while(a<=b){
        if(a%2 == 1)    res = min(res, stree[a++]);
        if(b%2 == 0)    res = min(res, stree[b--]);
        a /= 2; b /= 2;
    }
    return res;
}

void add(ll k, ll x){
    k += n;
    stree[k] = x;
    for(k /= 2; k>=1; k/=2){
        stree[k] = min(stree[2*k],stree[2*k+1]);
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
        add(i, x);
    }
    ll a, b, t;
    loop(i, 0, q){
        cin >> t >> a >> b;
        // putl(t);
        if(t==2){
            
            // cout << t << " " << a << " " << b << "\n";
            cout << finmin(a-1, b-1) << "\n";
            // putl(sum(a-1,b-1));
        }
        else{
            add(a-1, b);
        }
    }
   
    return 0;
}