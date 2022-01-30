#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <queue>
#include <unordered_map>
// #define ll int long long
typedef long long ll;
using namespace std;


int main(){
    ll n, m;
    cin >> n >> m;
    ll arr[n+1] = {0};
    ll pos[n+1] = {0};
    ll t, x, y;
    for(int i=0; i<n; i++){
        cin >> t ;
        arr[i] = t;
        pos[t] = i;
    }

    return 0;
}