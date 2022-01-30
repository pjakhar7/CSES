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
// #define ll int long long
typedef long long ll;
using namespace std;


int main(){
    ll n;
    ll a, b;
    cin >> n;
    vector<pair<ll,ll>> tasks;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        tasks.push_back(make_pair(a,b));
    }
    sort(tasks.begin(), tasks.end());
    ll reward=0, cur=0;
    for(auto t: tasks){
        cur += t.first;
        reward += t.second-cur;
    }
    cout << reward << endl;

    return 0;
}