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
vector< vl > F = { {1, 1}, {1, 0}};

vector< vl> multiplymat(vector< vl > A, vector< vl > B){
    vector< vl > res = { {0, 0}, {0, 0}};
    res[0][0] = ( A[0][0]*B[0][0] + A[0][1]*B[1][0] ) % mod;
    res[0][1] = ( A[0][0]*B[0][1] + A[0][1]*B[1][1] ) % mod;
    res[1][0] = ( A[1][0]*B[0][0] + A[1][1]*B[1][0] ) % mod;
    res[1][1] = ( A[1][0]*B[0][1] + A[1][1]*B[1][1] ) % mod;
    return res;
}

int main(){
    ll n;
    cin >> n;
    vector<vl> base = {{1,0}, {0,1}};
	vector<vl> m = {{1,1}, {1,0}};

	for(; n > 0; n /= 2, m = multiplymat(m, m)) {
		if(n & 1) base = multiplymat(base, m);
	}   
    
    putl(base[1][0]);
    return 0;
}