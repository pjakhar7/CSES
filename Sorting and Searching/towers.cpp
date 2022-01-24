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
    cin >> n;
    ll arr[n];
    for(ll i=0; i<n; i++)
        cin >> arr[i];
    multiset<ll> towers;
    towers.insert(arr[0]);

    for(int i=1; i<n; i++){
        multiset<ll>::iterator it = towers.upper_bound(arr[i]);
        if(it == towers.end()){
            towers.insert(arr[i]);
        }
        else{
            towers.erase(it);
            towers.insert(arr[i]);
        }
    }
    cout << towers.size() << endl;
    return 0;
}