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
    vector<ll> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    ll sum = 0;
    for(auto t: nums)
        sum += t;
    ll ans;
    if(*nums.rbegin()*2>sum)
        ans = *nums.rbegin()*2;
    else 
        ans = sum;
    cout << ans << endl;
    return 0;
}