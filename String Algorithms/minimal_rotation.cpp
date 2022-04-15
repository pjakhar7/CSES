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
const int msize = 1e6+1;

ll H[msize];
ll p[msize];

ll calcmodpow(ll a, ll b){
    if(b==0)
        return 1;
    if(b==1)
        return a%mod;
    ll t = calcmodpow(a, b/2)%mod;
    ll res = t*t % mod;
    if(b%2)
        res = (res*a)%mod;
    return res;
        
}

ll gethash(int l, int r){
    return ((H[r+1]-H[l]+mod)%mod * p[l]%mod) % mod;
}

int main(){
    int n;
    string s;
    cin >> s;
    n = s.sz;
    ll x = 1;
    H[0] = 0;
    for(int i=0; i<n; i++){
        H[i+1] = (H[i] + x*(int(s[i]-'a')))%mod;
        x *= 131;
        x %= mod;
    }
    x = 1;
    
    for(int i=0; i<n; i++){
        p[i] = calcmodpow(x, mod-2);
        x *= 131;
        x %= mod;
    }

    s += s;
    int res = 0;
    for(int i=1; i<n; i++){
        int low = 0, hi = n-1;
        while(low <= hi){
            int mid = (low + hi)/2;
            if(gethash(res,res+mid)==gethash(i, i+mid))
                low = mid + 1;
            else  
                hi = mid - 1 ;
        }
        if(low <n)
            if(s[res + low]>s[i + low])
                res = i;
    }
    cout << s.substr(res, n);
    // string ans = s.substr(res, n);
    // putl(ans);
    return 0;
}