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
#define seea(A, a, b) for(int i=a; i<b; i++){cout << A[i]<<" ";}cout<< "\n";

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

void update(ll i){
    ll k = i+n;
    stree[k] = 1;
    for(k /= 2; k>=1; k/=2){
        stree[k] = stree[2*k]+stree[2*k+1];
    }

}

ll delfind(ll x){
    
    ll k=1;
    ll res = inf;
    while(k<n){
        if(stree[2*k]>=x){
            k = 2*k;
        }
        else{
            x -= stree[2*k];
            k = 2*k+1;
        }
    }
    ll ind = k-n;
    stree[k] = 0;
    for(k /= 2; k>=1; k/=2){
        stree[k] = stree[2*k]+stree[2*k+1];
    }
    return ind;
}

int main(){
    ll q;
    cin >> n ;
    q = n;
    ll orign = n;
    n = ll(pow(2,ceil(log2(n))));
    ll x;
    memset(stree, 0, sizeof(stree));
    vl nums(orign,0);
    // cout << n << endl;
    // cout << orign << endl;
    loop(i, 0, orign){
        cin >> x;
        nums[i] = x;
        update(i);
    }
    ll t, ou;
    // seea(nums,0, orign);
    // seea(stree, 0, 2*n);
    loop(i, 0, orign){
        cin >> t;
        ou = delfind(t);
        // putl(ou);
        // cout <<ou <<" : "<< nums[ou] << "  SS   \n";
        put(nums[ou]);
    }
   
    return 0;
}