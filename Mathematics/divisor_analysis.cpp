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

// unsigned long long int calc(unsigned long long int a, unsigned long long int b){
//     if(a==0 && b==0)
//         return 1;
//     if(a==0)
//         return 0;
//     if(b==0)
//         return 1;
//     if(b==1)
//         return a%mod;
//     if(b%2==1){
//         ll t = calc(a, b/2);
//         return ((t*t)%mod*a)%mod;
//         }
//     else{    
//         ll t = calc(a, b/2);
//         return (t*t)%mod;
//     } 
// }

ll calc(ll base, ll pow) {
	ll ans = 1;
	while (pow) {
		if (pow & 1) ans = ans * base % mod;
		base = base * base % mod;
		pow >>= 1;
	}
	return ans%mod;
}

int main(){
    ll n, q;
    cin >> n;
    ll p, a;
    ll count=1, sum=1, product=1, num=1, count1=1;
    ll div_sum = 1;
    while(n--){
        cin >> p >> a;
        count = (count *(a+1))%mod;
        sum = sum * ((calc(p, a+1)-1) % mod * calc(p-1, mod - 2)%mod) % mod;
		div_sum = div_sum * (calc(p, a + 1) - 1) % mod * calc(p - 1, mod - 2) % mod;
        // put(sum);       
        num = (num*calc(p, a))%mod;
        product = (calc(product, a+1)*calc(calc(p, (a*(a+1)/2)), count1))%mod;
        count1 = (count1*(a+1))%(mod-1);
        // putl(num);
    }
    // putl("");
    // putl(num);
    putl(count);
    putl(sum);    
    putl(product);
    // putl(div_sum);
    return 0;
}