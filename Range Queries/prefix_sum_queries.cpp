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

ll stree[2*(ll)1e6+2];
ll n;
ll finmax(ll a, ll b){
    ll l = 1, r = 1;
    while(l)
}

void update(ll x, ll u){
    ll k = x+n;
    ll v = stree[k];
    while(floor(log2(k+1)!=ceil(log2(k+1)))){
        stree[k++] += v-u;
        k /= 2;
    }
}

void updatetree(ll k){
    k += n;
    for(k/=2; k>=1; k/=2){
        stree[k] = max(stree[2*k], stree[2*k+1]);
    }
}

int main(){
    int  q;
    cin >> n >> q;
    ll orign = n;
    n = pow(2, ceil(log2(n)));
    memset(stree, 0, sizeof(stree));
    vl nums(n,0);
    geta(nums,0,orign);
    stree[n] = nums[0];
    loop(i,1,orign){
        stree[n+i] = stree[n+i-1] + nums[i];
    }
    loop(i,0,orign){
        updatetree(i);
    }
    ll t, a, b;
    loop(qi,0,q){
        cin >> t >> a >> b; 
        if(t==1){
            update(a-1, b);
        }
        else{
            putl(finmax(a-1,b-1));
        }
    }
    return 0;
}