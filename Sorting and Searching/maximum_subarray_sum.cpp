#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>

#define ll long long

using namespace std;

int main(){
    ll n, t;
    vector< ll > nums;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t;
        nums.push_back(t);
    }
    ll res = INT64_MIN;
    ll cursum =0;
    ll i =0;
    bool flag = true;
    ll minnum = INT64_MIN;
    for(int i=0; i<n; i++){
        if(nums[i]>0){
            flag = false;
            break;
        }
        minnum = max(nums[i], minnum);
    }
    if(flag){
        cout << minnum << endl;
        return 0;
    }
    while(i<n){
        if((cursum + nums[i])<0){
            i++;
            cursum = 0;
        }
        else{
            cursum += nums[i];
            res = max(res, cursum);
            i++;
        }
    }
    cout << res << endl;
    return 0;
        
}