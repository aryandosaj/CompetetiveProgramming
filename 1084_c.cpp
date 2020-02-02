#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    ll n = s.length();
    ll arr[n + 1];
    arr[n] = 0;
    ll c=0;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'a')
           { arr[i] = arr[i + 1] + 1;c++;}
        else
            arr[i] = arr[i + 1];
    }
    
    // for(ll i = 0; i < n; i++)
    // {
    //     cout<<arr[i];
    // }
    
    ll left=0,ans=1,last=0;
    for(ll i = 0; i < n; i++)
    {
        
        if((s[i] =='b'))
        {
            ans=(ans*(left+1))%MAX;
            left=0;
        }
        else if(s[i]=='a')
        left++;
    }
    ans = (ans*(left+1))%MAX;
    cout<<ans-1;
    
}