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
        ll n;
        cin >> n;
        vector<ll> arr;
        for(ll i=0; i<n; i++){
            ll x;
            cin >> x;
            arr.push_back(x);
        }
    vector<ll> arr2;
    sort(arr.begin(), arr.end());
    arr2.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i]!=arr2[arr2.size()-1])
            arr2.push_back(arr[i]);
    }

    cout << arr2.size() << endl;

        
    


    return 0;
}