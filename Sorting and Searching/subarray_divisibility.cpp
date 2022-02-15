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
    cin >> n ;
    ll arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    ll res = 0;
    for(int i=0; i<n; i++)
        arr[i] = (arr[i]+n)%n;
    map<ll,ll> sums;
    sums[0]++;
    ll cursum = 0;
    for(int i=0; i<n; i++){
        cursum = (cursum+arr[i]+n)%n;
        res += sums[(cursum)%n];
        sums[cursum]++;
    }
    cout << res << endl;
    return 0;
}