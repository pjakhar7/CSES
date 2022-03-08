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
#define seea(A, a, b) for(int i=a; i<b; i++){cout << A[i]<<" ";}cout << "\n";

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
stack<int> st;
vector<int> vlist;
int n;
void dfs(int s, vi adjlist[], vi &visited){
    visited[s] = true;
    loop(i,0,adjlist[s].sz){
        int x = adjlist[s][i];
        if(!visited[x])
            dfs(x, adjlist, visited);
    }
    st.push(s);
    vlist.pb(s);
}

void dfs2(int s, vi adjlist[], vi &visited){
    visited[s] = true;
    loop(i,0,adjlist[s].sz){
        int x = adjlist[s][i];
        if(!visited[x])
            dfs2(x, adjlist, visited);
    }
}

bool findpath(int a, int b, vi adjlist[], vi &visited){
    if(a==b)
        return true;
    visited[a] = true;
    bool res = false;
    loop(i,0,adjlist[a].sz){
        int x = adjlist[a][i];
        if(!visited[x]){
            res |= findpath(x, b, adjlist, visited);
            if(res)
                return true;
        }
    }
    return res;
}
int main(){
    int m, x, y;
    cin >> n >> m;
    vi adjlist[n+1];
    vi adjlistr[n+1];
    loop(i, 0, m){
        cin >> x >> y;
        adjlist[x].pb(y);
        adjlistr[y].pb(x);
    }
    vi visited(n+1, false);
    loop(i, 1, n+1){
        if(!visited[i])
            dfs(i, adjlist, visited);
    }
    fill(visited.begin(), visited.end(), false);
    // seea(vlist,0,n);
    // seea(visited,1,n+1);
    int a, b;
    a = st.top();
    dfs2(a, adjlistr, visited);
    
    // seea(visited,1,n+1);
    bool flag=true;
    loop(i,1,n+1){
        if(!visited[i]){
            flag = false;
            break;
        }
    }
    if(flag){
        putl("YES");
        return 0;
    }
    loop(i,1,n+1){
        if(!visited[i]){
            flag = false;
            b = i;
            break;
        }
    }
    vi visit(n+1, false);
    putl("NO");
    if(!findpath(a,b,adjlist, visit)){
        cout << a << " " << b<< "\n";
    }
    else{
        cout << b << " " << a << "\n";
    }
    
    
    return 0;
}