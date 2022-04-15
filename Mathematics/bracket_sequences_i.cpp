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

const ll maxsize = 1000005;
ll facts[maxsize];

ll calc(ll a, ll b){
    if(b==0)
        return 1;
    if(b==1)
        return a%mod;
    ll t = calc(a, b/2);
    t = (t*t)%mod;
    if(b%2)
        t = (t*a)%mod;
    return t;
}

void calcfact(){
    facts[0] = 1;
    facts[1] = 1;
    loop(i, 2, maxsize-4){
        facts[i] = (facts[i-1]*i)%mod;
    }
}

int main(){
    ll n;
    cin >> n;
    ll a, b; 
    calcfact();
    if(n%2){
        putl(0);
        return 0;
    }
    n /= 2;
    a = 2*n; b = n;

    cin >> a >> b; 

    ll res = facts[a] % mod * calc(facts[b], mod-2)%mod * calc(facts[a-b], mod-2)%mod %mod;
    res = (res * calc(n+1, mod-2))%mod;
    putl(res);

    return 0;
}