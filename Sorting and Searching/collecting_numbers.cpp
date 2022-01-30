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
    ll n, t;
    cin >> n;
    vector<ll> arr;
    for(ll i=0; i<n; i++){
        cin >> t;
        arr.push_back(t);
    }
    unordered_map<ll, int> umap;
    for(ll i=0; i<n; i++){
        if(umap.find(arr[i]-1)!=umap.end()){
            umap[arr[i]] = umap[arr[i]-1]+1;
        }
        else{
            umap[arr[i]] = 0;
        }
    }
    ll res = 0;
    for(auto i: umap){
        if(i.second==0)
            res++;
    }
    cout << res << endl;

    return 0;
}