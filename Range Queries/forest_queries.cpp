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

int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    loop(i,0,n){
        loop(j,0,n){
            cin >> grid[i][j];
        }
    }
    vector<vl > prefsum(n+1, vl(n+1, 0));
    loop(i, 1, n+1)
        prefsum[1][i] = (grid[0][i-1]=='*')+prefsum[1][i-1];
    loop(i, 1, n+1)
        prefsum[i][1] = (grid[i-1][0]=='*')+prefsum[i-1][1];

    loop(i, 2, n+1){
        loop(j, 2, n+1){
            prefsum[i][j] = (grid[i-1][j-1]=='*') + prefsum[i][j-1] + prefsum[i-1][j] - prefsum[i-1][j-1];
        }
    }
    ll a, b, c, d;
    loop(i, 0, q){
        cin >> a >> b >> c >> d;
        ll forests = prefsum[c][d] - prefsum[a-1][d] - prefsum[c][b-1] + prefsum[a-1][b-1];
        putl(forests);
    }
    return 0;
}