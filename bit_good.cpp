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
    ll n;
    cin >> n;
    ll arr[n];
    vll v;
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > 0)
            v.push_back(arr[i]);
        else
            mp[arr[i]] = 1;
    }
    ll c=0;
    sort(v.begin(),v.end());
    ll ans=0;
    for(ll i = v.size()-1;i>=0;i--)
    {
        if(c>=3) (ans+=v[i])%=MAX;
        if(mp[v[i]]==0) c++;
        
    }
    cout<<ans;
}