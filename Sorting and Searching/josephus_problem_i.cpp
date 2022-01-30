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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr;
    set<ll> nums;
    k++;
    for(ll i=1; i<=n; i++)
        nums.insert(i);
    int mod = k-1;
    while(nums.size()>1){
        auto it=nums.begin();
        int i=0;
        vector<ll> toerase;
        // cout << "Round . "<<mod << "  --- "<<nums.size()<<endl;
        for(; it!=nums.end(); it++){
            if(i%k==mod){
                cout << *it << " ";
                toerase.push_back(*it);
            }
            i++;
        } 
        if(*nums.rbegin()==toerase[toerase.size()-1]){
            mod = 1;
        }
        else 
            mod = 0;
        for(auto i: toerase)
            nums.erase(i);
        
    }
    cout << *nums.begin()<<endl;
    return 0;
}