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
    ll n, x;
    cin >> n >> x;
    ll arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    // ll i=0,j=0;
    // ll res = 0;
    // multiset<ll> dists;
    // dists.insert(arr[0]);
    // ll curcount = 1;;
    // while(i<n && j<n){
    //     if(curcount==x){
    //         cout << res << endl;
    //         res += (j-i);
    //         j++;
    //         if(j<n){
    //             if(dists.find(arr[j])==dists.end())
    //                 curcount++;
    //             dists.insert(arr[j]);
    //         }
    //     }
    //     else if(curcount<x){
    //         j++;
    //         if(j<n){
    //             if(dists.find(arr[j])==dists.end())
    //                 curcount++;
    //             dists.insert(arr[j]);
    //         }
                
    //     }
    //     else{
            
    //     }
    // }
    // if(j==n)
    //     res += (((j-i)*(j-i-1))/2);
    map<ll,ll> cnt;
    ll l=0, r=0, c=0, res=0;
    while(l<n){
        while(r<n && c + (cnt[arr[r]]==0)<=x){
            cnt[arr[r]]++;
            c += (cnt[arr[r]]==1);
            r++;
        }
        res += r-l;
        c -= (cnt[arr[l]]==1);
        cnt[arr[l]]--;
        l++;
    }
    cout << res << endl;
    return 0;
}