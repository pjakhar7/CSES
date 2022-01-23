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
    vector<ll> arr;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    ll median;
    if(arr.size()%2==1){
        median = arr[n/2];
    }
    else{
        median = (arr[n/2-1]+arr[n/2])/2;
    }
    ll res = 0;
    for(int i=0; i<n; i++){
        res += abs(arr[i]-median);
    }
    cout << res << endl;
    return 0;
}