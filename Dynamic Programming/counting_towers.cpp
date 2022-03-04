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
const int num = (int)1e6; 
ll dpa[num+1];
ll dpb[num+1];
int main(){
    dpa[1] = 1;
    dpb[1] = 1;
    for(int i=2; i<=num; i++){
        dpa[i] = (2*dpa[i-1]+dpb[i-1])%mod;
        dpb[i] = (4*dpb[i-1]+dpa[i-1])%mod;
    }
    int t;
    cin >> t;
    int x;
    for(int i=0; i<t; i++){
        cin >> x;
        cout << (dpa[x]+dpb[x])%mod << endl;
    }
    return 0;
}