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
    ll i=0,j=0;
    ll res = 0;
    ll cursum = arr[0];
    while(i<n && j<n){
        if(cursum==x){
            res++;
            i++;
            cursum -= arr[i-1];
        }
        else if(cursum<x){
            j++;
            if(j<n)
                cursum += arr[j];
        }
        else{
            i++;
            cursum -= arr[i-1];
        }
    }

    cout << res << endl;
    return 0;
}