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

int dp[100001][1001];
int dp2[1001][100001];
int pages[5001];
int price[5001];
int main(){
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++)
        cin >> price[i];
    for(int i=0; i<n; i++)
        cin >> pages[i];
    // for(int i=0; i<=x; i++){
    //     for(int j=1; j<=n; j++){
    //         if(i-price[j-1]>=0)
    //             dp[i][j] = max(dp[i][j-1], pages[j-1]+dp[i-price[j-1]][j-1]); 
    //         else 
    //             dp[i][j] = dp[i][j-1];  
    //     }
    // }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            //option1 = book number i-1 is not included, hence no pages added.
            //option2 = book number i-1 is included, hence pages are added.
            //option1 = dp[i-1][j] ...book not included so total price(j) remains same.
            //option2 = dp[i-1][j-price[i-1]] + page[i-1]....total price(j) decreased and pages are counted for book i-1.
            
            dp2[i][j] = dp2[i-1][j];
            if(j >= price[i-1])
            {
                dp2[i][j] = max (dp2[i][j],dp2[i-1][j-price[i-1]] + pages[i-1]); //max of both the boxes included in dp[i][j]. 
            }
        }
    }
    cout << dp2[n][x] <<endl;;
    return 0;
}