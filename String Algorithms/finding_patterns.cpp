#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;
const int msize = 5*1e5+5;
unsigned long long p[msize];

typedef long long ll;
typedef long double ld;

ll calcmpow(ll a, ll b){
    if(b==0)
        return 1;
    if(b==1)
        return a%mod;
    ll t = calcmpow(a, b/2);
    t = (t*t)%mod;
    if(b%2)
        t = (t*a)%mod;
    return t;
}


class RollHash{
public:
    ll Hash[1000005];
    RollHash(){
        memset(Hash,0,sizeof Hash);
    }
    void fillRoll(string s)
    {
        ll n = s.length();
        ll x = 131;
        for(ll i=0;i<n;i++)
        {
            Hash[i+1] = (Hash[i] + x*(s[i]-'a'+1))%mod;
            x*=131;
            x%=mod;
        }
    }
    ll power(ll a,ll b)
    {
        if(b == 0)return 1;
     
        ll ans = 1;
        while(b > 0)
        {
           
            if(b%2)
                ans = (ans*a)%mod;
            a = (a*a)%mod;
     
            b/=2;
     
        }
        return ans;
    }
    ll get(ll l,ll r)
    {
        return ((Hash[r] - Hash[l-1] + mod)*p[l-1])%mod;
    }
};
 
signed main()
{   
    string word;
    cin >> word;
    int n = word.length();
    
    p[n - 1] = calcmpow(calcmpow(131, n - 1), mod - 2);
    for(int i = n - 2; ~i; i--)
        p[i] = (p[i + 1] * 131) % mod;
    
    RollHash r;
    r.fillRoll(word);
    int m;
    cin >> m;
    while(m--)
    {
        int flag = 0;
        string s;
        cin >> s;
        ll hash = 0;
        ll x = 131;
 
        for(ll i=0;i<s.length();i++)
        {
            hash = (hash + x*(s[i]-'a'+1))%mod;
            x*=131;
            x%=mod;
        }
 
        for(ll i=1;i+s.length()-1<=n;i++)
        {
            ll x = i;
            ll y = i + s.length() - 1;
            if(r.get(x,y) == hash)
            {
                flag = 1;
                break;
            }
        }
        if(flag)cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}