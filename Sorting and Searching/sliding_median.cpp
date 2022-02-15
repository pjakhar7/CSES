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

void balance(multiset<ll> &minset, multiset<ll> &maxset){
    if((minset.size()+maxset.size())%2==1){
        if(minset.size()>maxset.size()+1){
            ll t = *minset.rbegin();
            minset.erase(minset.find(t));
            maxset.insert(t);
        }
        if(maxset.size()>minset.size()+1){
            ll t = *maxset.begin();
            maxset.erase(maxset.find(t));
            minset.insert(t);
        }
    }
    else{
        if(minset.size()>maxset.size()){
            ll t = *minset.rbegin();
            minset.erase(minset.find(t));
            maxset.insert(t);
        }
        if(maxset.size()>minset.size()){
            ll t = *maxset.begin();
            maxset.erase(maxset.find(t));
            minset.insert(t);
        }
    }
}

ll newmedian(multiset<ll> &minset, multiset<ll> &maxset){
    if(minset.size()==maxset.size())
        return min(*minset.rbegin(),*maxset.begin());
    else if(minset.size()>maxset.size())
        return *minset.rbegin();
    else
        return *maxset.begin();
}

int main(){
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    multiset<ll> minset, maxset;
    ll median = 0;
    for(int i=0; i<k; i++){
        if(arr[i]>median)
            maxset.insert(arr[i]);
        else
            minset.insert(arr[i]);
        balance(minset, maxset);
        median = newmedian(minset, maxset);
    }
    cout << median << " ";
    for(int i=k; i<n; i++){
        if(arr[i]>median)
            maxset.insert(arr[i]);
        else
            minset.insert(arr[i]);
        balance(minset, maxset);
        if(maxset.find(arr[i-k])!=maxset.end())
            maxset.erase(maxset.find(arr[i-k]));
        else    
            minset.erase(minset.find(arr[i-k]));
        balance(minset, maxset);
        median = newmedian(minset, maxset);
        cout << median << " ";
    }
    return 0;
}