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
#define MAX 998244353
struct dt
{
    ll l, r;
};
bool comp(dt a, dt b)
{
    return (a.r - a.l) < (b.r - b.l);
}
ll dsu[3001];
ll ans[3001];
ll fact[3001];
ll inv(ll n)
{
    return power(n, MAX - 2, MAX);
}
ll ncr(ll n, ll r)
{
    ll ret = (((fact[n] * inv(fact[n - r])) % MAX) * inv(fact[r])) % MAX;
    return ret;
}
ll find(ll u)
{
    while (u != dsu[u])
        u = dsu[u];
    return u;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    dt arr[n];
    fact[0] = 1;
    for (ll i = 1; i < 3001; i++)
        fact[i] = (fact[i - 1] * i) % MAX;
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
        cin >> arr[i].l >> arr[i].r, dsu[i] = i,mp[i]=1;
    sort(arr, arr + n, comp);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i != j)
            {
                if ((arr[i].l <= arr[j].l) && (arr[j].r <= arr[i].r))
                {
                    // ll f = find(i);
                    // mp[f]++;
                    // dsu[j] = f;
                    mp[i]+=mp[j];
                    mp.erase(j);
                }
            }
        }
    }
    for (ll j = 1; j <= n; j++)
    {
        for (auto i : mp)
        {
            if (i.second >= j)
            {
                (ans[j] += ncr(i.second, j)) %= MAX;
            }
        }
    }
    // cout << ncr(5, 2);
    for(ll i=1;i<=n;i++)cout<<ans[i]<<"\n";
}