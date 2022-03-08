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

ll minimums[int(2*1e5+1)][32];
map< pair<int,int>, ll> minimums2;
ll findmin(int l, int r){
    int d = r-l;
    if( ceil(log2(d))==floor(log2(d)))
        return minimums[l][(int)log2(d)];
    
    int k = floor(log2(d));
    return min(minimums[l][k], minimums[r-(int)pow(2,k)][k]);
}


int main(){
    int n, q;
    cin >> n >> q;
    
    vl nums(n, 0);
    geta(nums,0,n);
    
    loop(a,0,n-1){
        minimums[a][0] = min(nums[a], nums[a+1]);     
    }
    // putl(log2(1e9)+1);
    
    // putl(log2(921726510)+1);
    // putl(log(1e5+1));
    // putl(log10(1e9)+1);
    // putl(log10(1e5+1));
    // cout << pow(2,6) << endl;
    // cout << floor(log2(73)) << endl;
    loop(k, 1, 32){
        if(pow(k,2)>n)
            break;
        loop(a,0,n){
            if(a+(ll)pow(2,k)>=n){
                // cout << " lol why\n" << k;
                break;
            }
                
            minimums[a][k] = min(minimums[a][k-1], minimums[a+(int)pow(2,k-1)][k-1]);      
        }
    }

    // loop(i,0,n){
    //     loop(j,0,22){
    //         cout << minimums[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    loop(i,0,q){
        int l, r;
        cin >> l >> r;
        if(l==r)
            putl(nums[l-1]);
        else{
            int d = r-l;
            int k = floor(log2(d));
            // cout << "llol\n";
            cout << min(minimums[l-1][k], minimums[r-1-(int)pow(2,k)][k]) << "\n";
        }
            // putl(findmin(l-1,r-1));
    }
    
    return 0;
}