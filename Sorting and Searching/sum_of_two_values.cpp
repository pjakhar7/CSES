#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>

#define ll long long

using namespace std;

int main(){
    ll n, x;
    cin >> n >> x;
    vector< pair<ll, ll> > nums;
    ll t;
    for(ll i=0; i<n; i++){
        cin >> t ;
        nums.push_back(make_pair(t, i));
    }
    sort(nums.begin(), nums.end());
    ll i =0, j = n-1;
    while(i<j){
        if(nums[i].first+nums[j].first==x){
            cout << min(nums[i].second,nums[j].second)+1<<" " << max(nums[i].second,nums[j].second)+1 << endl;
            return 0;
        }
        else if(nums[i].first+nums[j].first<x){
            i++;
        }
        else{
            j--;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}