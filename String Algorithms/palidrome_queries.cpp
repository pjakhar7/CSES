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

const int msize = 2*(1e5)+5;

ll Hpref[msize];
ll Hsuf[msize];
unsigned long long int p[msize];
ll streepref[3*msize];
ll streesuf[3*msize];
int orign, N;

ll calcmpow(ll a, ll b){
    if(b==0)
        return 1;
    if(b==1)
        return a%mod;
    ll t = calcmpow(a, b/2);
    t = (t*t)%mod;
    if(b%2)
        t = (t*a)%mod;
    return t;
}

void update(ll i, char s){
    ll hpnew = (int(s-'a'+1) * calcmpow(131, i) )%mod;
    ll hsnew = (int(s-'a'+1) * calcmpow(131, orign-i-1))%mod;
    ll pos = i + N;
    ll change1 = hpnew - streepref[pos];
    ll change2 = hsnew - streesuf[pos];
    while(pos){
        streepref[pos] = (streepref[pos] + change1)%mod;
        streesuf[pos] = (streesuf[pos] + change2)%mod;
        pos /= 2;
    }    
}

bool find(int l, int r){
    int il = l, ir = r;
    ll sum1 = 0, sum2 = 0;
    l += N, r+=N;
    while(l<=r){
        if(l%2) {sum1 = (sum1 + streepref[l])%mod; sum2 = (sum2 + streesuf[l]);}
        if(r%2==0) {sum1 = (sum1 + streepref[r])%mod; sum2 = (sum2 + streesuf[r]);}
        l++; r--;
        l /= 2; r /= 2;
    }
    sum1 = (sum1 * p[il])%mod;
    sum2 = (sum2 * p[orign-ir-1])%mod;
    // putl(sum1);
    // putl(sum2);
    return (sum1==sum2);
}


int main(){
    int n, q;
    cin >> n >> q;
    string s;
    orign = n;
    N = ll(pow(2, ceil(log2(n))));
    cin >> s;
    int qi, a, b;
    int x = 1;
    // putl(N);
    loop(i, 0, n){
        update(i, s[i]);
        x = (x * 131)%mod;
    }
    p[n - 1] = calcmpow(calcmpow(131, n - 1), mod - 2);
    for(int i = n - 2; ~i; i--)
        p[i] = (p[i + 1] * 131) % mod;
    // seea(streepref, N, N+n);
    // seea(streesuf, N, N+n);
    while(q--){
        cin >> qi ;
        if(qi==1){
            cin >> a ;
            char x;
            cin >> x;
            update(a-1, x);
        }
        else{
            cin >> a >> b;
            if(find(a-1, b-1))
                putl("YES");
            else 
                putl("NO");
        }
    }
    return 0;
}