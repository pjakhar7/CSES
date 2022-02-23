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


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    set<int> S;
    S.insert(nums[0]);
    for(int i=1; i<n; i++){
        int x = nums[i];
        vector<int> temp;
        for(auto t: S)
            temp.push_back(t+x);
        for(auto t: temp)
            S.insert(t);
        S.insert(x);
    }
    cout << S.size() << endl;
    for(auto t: S)
        cout << t << " ";
    cout << endl;

    return 0;
}