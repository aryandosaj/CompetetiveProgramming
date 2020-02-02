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
vll graph[100005];
ll arr[100005];
ll ans;
ll dfs(ll u, ll p, ll cur_max)
{
    ll m1 = 0, m2 = 0;
    cur_max += arr[u];
    // max_till_now = max(cur_max, max_till_now);
    for (auto v : graph[u])
    {
        if (v != p)
        {
            ll val = dfs(v, u, 0);
            if (val < m2)
                continue;
            else if (val > m1)
                m2 = m1, m1 = val;
            else
                m2 = val;
        }
    }
    ans = max(ans,arr[u]+m1+m2);
    return m1+arr[u];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >>
            u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    dfs(1,0,0);
    cout<<ans+k;

}