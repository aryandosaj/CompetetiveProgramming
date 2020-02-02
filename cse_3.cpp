#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    map<ll,ll> visit;
    
    
    ll j=1;
    for(ll i = 0; i < n; i++)
    {
        if(arr[i]>n)
        {
            while(mp[j]!=0)
            j++;
            arr[i]=j++;continue;
        }
        if(visit[arr[i]]==0)
        {
            visit[arr[i]]=1;continue;
        }
        if(mp[arr[i]]>1)
        {
            while(mp[j]!=0)
            j++;
            arr[i]=j++;
        }
    }
    
    for(ll i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}