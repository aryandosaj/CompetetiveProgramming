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
vll graph[1005];
vll rgraph[1005];
vll vecgraph[1005];
ll p[1005];
unordered_map<ll, ll> vis;
ll dfs2(ll u, ll f)
{
    vecgraph[f].push_back(p[u]);
    vis[u] = 1;
    for (auto i : graph[u])
    {
        if (!vis[i])
        {
            dfs2(i, f);
        }
    }
}

ll dfs1(ll u, ll f)
{
    if (u != f)
        vecgraph[f].push_back(p[u]);
    vis[u] = 1;
    for (auto i : rgraph[u])
    {
        if (!vis[i])
        {
            dfs1(i, f);
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
        rgraph[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++)
        cin >> p[i];
    vll out;
    for (ll i = 1; i <= n; i++)
    {
        if (graph[i].size() == 0)
        {
            out.push_back(i);
            dfs1(i, i);
        }
    }
    vll temp;
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            temp.push_back(i);
            dfs2(i, i);
        }
    }
    ll ans = 0;
    for (auto i : out)
    {
        double avg = p[i];
        sort(vecgraph[i].begin(), vecgraph[i].end(), greater<ll>());
        ll count = 1;
        for (auto j : vecgraph[i])
        {
            if ((avg * count + j) / ((count + 1) * 1.0) > avg)
            {
                 avg = (avg * count + j) / ((count + 1) * 1.0);
                 count++;
            }
        }
        ans += count;
    }
    ans+=temp.size();
    cout << ans;
}