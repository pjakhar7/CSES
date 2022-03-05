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

using namespace std;

#define vi vector<int>
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
#define seea(A, a, b) for(int i=a; i<b; i++){cout << A[i]<<" ";}


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

vi res;
int state[100002];
int dist[100002];
bool flag;

void topological_sort(int s, vi adjlist[]){
    state[s] = 1;
    // cout << "start : " << s << "\n";
    int cures = INT_MIN;
    loop(i, 0, adjlist[s].sz){
        int x = adjlist[s][i];
        // cout << s <<" : " << x << " ";
        if(state[x]==0)
            topological_sort(x, adjlist);
        cures = max(cures, dist[x]);
    }
    if(cures!=INT_MIN)
        dist[s] = cures+1;
    // cout << "\n";
    state[s] = 2;
}

void printpath(int s, vi adjlist[]){
    // put(s);
    cout << s << " ";
    int maxi=-1, maxdist=INT_MIN, x;
    loop(i, 0, adjlist[s].sz){
        x = adjlist[s][i];
        if(dist[x]>maxdist){
            maxi = x;
            maxdist = dist[x];
        }
            
    }
    if(maxi!=-1){
        // cout <<" -"<< dist[s] << "-  ";   
        printpath(maxi, adjlist);
    }
}

int main(){
    ll n, m, x, y;
    cin >> n >> m;
    vi adjlist[n+1];
    flag = false;
    loop(i, 0, m){
        cin >> x >> y;
        adjlist[x].pb(y);
    }
    memset(state, 0, sizeof(state));
    loop(i,0,100002)
        dist[i] = INT_MIN;
    dist[n] = 1;
    topological_sort(1, adjlist);
    if(dist[1]==INT_MIN)
        put("IMPOSSIBLE\n");
    else{
        // seea(dist,1,n+1);
        // cout << endl;
        cout << dist[1] << endl;
        printpath(1, adjlist);
    }
    return 0;
}