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
#include <cstring>
typedef long long ll;
using namespace std;
const int mod = 1e9+7;
int _find_pile(vector<vector<int>>& pile, int l, int r, int x){
    int m = l+(r-l)/2;
    if((r-l)==1){
        if(x<=pile[l][pile[m].size()-1])
            return l;
        else 
            return r;
    }
    if(x>pile[m][pile[m].size()-1])
        return _find_pile(pile, m, r,  x);
    else
        return _find_pile(pile, l, m,  x);
}

int find_pile(vector<vector<int>>& pile, int x){
    if(x>pile[pile.size()-1][pile[pile.size()-1].size()-1])
        return -1;
    if(pile.size()==1)
        return 0;
    int l = 0, r = pile.size()-1;
    return _find_pile(pile, l, r, x);
}
// Complete the longestIncreasingSubsequence function below.
int longestIncreasingSubsequence(vector<int> arr) {
    vector<int> l(arr.size(),1);
    vector<vector<int>> pile;
    pile.push_back(vector<int> (1,arr[0]));
    for(int i=1; i<arr.size(); i++){
        int ind = find_pile(pile, arr[i]);
        if(ind==-1)
            pile.push_back(vector<int> (1,arr[i]));
        else    
            pile[ind].push_back(arr[i]);
    }
    return pile.size();
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    // vector<ll> dp(n,1);

    // for(int i=1; i<n; i++){
    //     for(int j=0; j<i; j++){
    //         if(arr[j]<arr[i])
    //             dp[i] = max(dp[i], dp[j]+1);
    //     }
    // }
    // cout << dp[n-1] << endl;
    cout << longestIncreasingSubsequence(arr) << endl;
    return 0;
}