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
ll tree[1000005];
ll tree1[1000005];
ll con = 1000005;
void add(ll node, ll val)
{
    for (ll i = node + 1; i < con; i += i & (-i))
        tree[i] += val;
}
ll get(ll node)
{
    ll ret = 0;
    for (ll i = node + 1; i > 0; i -= i & (-i))
        ret += tree[i];
    return ret;
}
void add1(ll node, ll val)
{
    for (ll i = node + 1; i < con; i += i & (-i))
        tree1[i] += val;
}
ll get1(ll node)
{
    ll ret = 0;
    for (ll i = node + 1; i > 0; i -= i & (-i))
        ret += tree1[i];
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll arr[n], brr[n];
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        brr[i] = arr[i];
        mp[arr[i]] = i;
    }
    sort(brr, brr + n);

    for (ll i = 0; i < n; i++)
    {
        arr[mp[brr[i]]] = i + 1;
    }
    
    // for(ll i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    
    for (ll i = 1; i < n; i++)
    {
        add1(arr[i], 1);
    }
    add(arr[0], 1);
    ll ans = 0;
    for (ll i = 1; i < n - 1; i++)
    {
        add1(arr[i],-1);
        ans+=(get(1000004)-get(arr[i]))*(get1(arr[i]-1)-get1(0));
        add(arr[i],1);
    }
    cout<<ans;
}