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

void update(ll a, ll b, ll u){
    a += n;
    b += n;
    while(a<=b){
        if(a%2 == 1)    stree[a++] += u;
        if(b%2 == 0)    stree[b--] += u;
        a /= 2; b /= 2;
    }    
}

ll getval(ll k){
    k += n;
    ll suf = 0;
    for(; k>=1; k/=2){
        suf += stree[k];
    }
    return suf;
}

int main(){
    ll q;
    cin >> n >> q;
    ll orign = n;
    n = ll(pow(2,ceil(log2(n))));
    ll x;
    memset(stree, 0, sizeof(stree));
    vl nums(orign, 0);
    geta(nums, 0, orign);
    
    ll a, b, qi, k, u;
    loop(i, 0, q){
        cin >> qi;
        if(qi==2){
            cin >> k;
            putl(getval(k-1)+nums[k-1]);
        }
        else{
            cin >> a >> b >> u;
            update(a-1, b-1, u);       
        }        
    }
   
    return 0;
}