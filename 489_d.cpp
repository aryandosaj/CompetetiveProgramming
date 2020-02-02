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
unordered_map<ll, ll> mp;
unordered_map<ll, ll> visit;

vll graph[3001];
void dfs(ll u, ll d, ll dad)
{
    if (d == 2)
        mp[u]++;
    else
    {
        for (ll i = 0; i < graph[u].size(); i++)
        {
            ll v = graph[u][i];
            if (v != dad)
            {
                dfs(v, d + 1, u);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        mp.clear();
        dfs(i, 0, 0);
        for (auto j : mp)
        {
            if (j.second >= 2)
                ans += ((j.second) * (j.second - 1)) / 2;
            // cout << j.second << " ";
        }
        // cout << "\n";
    }
    cout << ans;
}