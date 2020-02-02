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

ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll mm=0;
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    ll ans=0;
    for(ll i=1;i<n-1;i++)
    {
        if((arr[i]<arr[i-1])||(arr[i]<arr[i+1]))
        continue;
        unordered_map<ll,ll>mp;
        for(ll j=i+1;arr[j]<arr[i]&&j<n;j++)
            mp[arr[j]]=1;
        for(ll j=i-1;arr[j]<arr[i]&&j>=0;j--)
            if(mp[arr[i]-arr[j]])
                ans++;
        
    }
    cout<<ans;
    
    

}