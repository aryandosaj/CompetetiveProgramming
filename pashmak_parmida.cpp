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
ll con = 1000005;
ll tree[1000005];
void add(ll node, ll val)
{
    for(ll i = node+1;i<con;i+=i&(-i)) tree[i]+=val;
}
ll get(ll node)
{
    ll ret = 0;
    for(ll i = node+1;i>0;i-=i&(-i)) ret+=tree[i];
    return ret; 
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll arr[n];
    map<ll, vll> mp;
    ll ans=0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<ll, ll> f;
    ll x = 0;
    ll r[n];
    for (ll i = n - 1; i >= 0; i--)
    {
        f[arr[i]]++;
        add(f[arr[i]],1);
        r[i] = f[arr[i]];
    }
    f.clear();
    
    for(ll i = 0; i < n; i++)
    {
        f[arr[i]]++;
        add(r[i],-1);
        ans+=(get(f[arr[i]]-1)-get(0));
    }
    cout<<ans<<"\n";
    


}