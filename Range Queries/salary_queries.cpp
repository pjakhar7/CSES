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

int main(){
    ll n, q;
    cin >> n >> q;
    multiset<pll > mset;
    map<ll, ll> mp;
    ll t;
    loop(i, 0, n){
        cin >> t;
        mp[i+1] = t;
        mset.insert(make_pair(t, i+1));
    }
    char qt;
    ll a, b;
    loop(qi, 0, q){
        cin >> qt;
        cin >> a >> b;
        if(qt=='!'){
            mset.erase(make_pair(mp[a], a));
            mp[a] = b;
            mset.insert(make_pair(b, a)); 
        }
        else{
            putl(int(mset.upper_bound({b,0})-mset.cbegin())-(mset.lower_bound({a,0})-mset.cbegin());
        }
    } 
    
    return 0;
}