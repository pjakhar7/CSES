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
const int MAXN = (int)1e6+5;
const int N = (int)1e6+1;
int primes[MAXN];

ll calc(ll a, ll b){
    if(a==0 && b==0)
        return 1;
    if(a==0)
        return 0;
    if(b==0)
        return 1;
    if(b==1)
        return a%mod;
    if(b%2==1){
        ll t = calc(a, b/2);
        return ((t*t)%mod*a)%mod;
        }
    else{    
        ll t = calc(a, b/2);
        return (t*t)%mod;
    } 
}

void seive(){
    for(int i=2; i<=N; i++)
        primes[i] = i;
    int i = 2;
    for(int p=2; p*p<=N; p++){
        if(primes[p]==p)
            for(int i=p*p; i<=N; i+=p)
                primes[i] = p;
    }
}


ll sum_of_divisors(ll n){
    ll res = 1;
    while(n>1){
        int a=0;
        int y = primes[n];
        while(n%y==0){
            n /= y;
            a++;
        }
        if(a>0){
            res *= (((calc(y, a+1)-1+mod)%mod)*calc(y-1, mod-2))%mod;
        }
    }
    return res;
}




int main(){
    ll n, q;
    cin >> n;
    seive();
    ll res = 0;
    loop(i, 1, n+1){
        res = (res + sum_of_divisors(i))%mod;
    }
    putl(res);
    return 0;
}