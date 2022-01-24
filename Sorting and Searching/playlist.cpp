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
#include <queue>
// #define ll int long long
typedef long long ll;
using namespace std;


int main(){
    ll n, t;
    cin >> n;
    ll arr[n];
    for(ll i=0; i<n; i++){
        cin >> t;
        arr[i] = t;
    }
    ll res = 1;
    unordered_map<ll,bool> um;
    set<ll> numset;
    numset.insert(arr[0]);
    ll start =0;
    for(int i=1; i<n; i++){
        if(numset.find(arr[i])==numset.end()){
            numset.insert(arr[i]);
            res = max(res, i-start+1);
        }
        else{
            while(arr[start]!=arr[i]){
                numset.erase(arr[start]);
                start++;
            }
            start++;
            numset.insert(arr[start]);
        }
    }
    // for(int i=1; i<n; i++){
    //     if(um.find(arr[i])==um.end() || um[arr[i]]==0){
    //         um[arr[i]] = true;
    //         res = max(res, i-start+1);
    //     }
    //     else{
    //         while(arr[start]!=arr[i]){
    //             um[arr[start]] = false;
    //             start++;
    //         }
    //         start++;
    //     }
    // }
    cout << res << endl;
    return 0;
}