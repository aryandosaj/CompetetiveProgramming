#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)

vll graph[100005];
ll l;
ll lev[100005];
unordered_map<ll, ll> vis;
unordered_map<ll, ll> tin;
unordered_map<ll, ll> tout;
ll tim;
ll up[100005][60];
void dfs(ll u, ll p)
{
    tim++;
    tin[u] = tim;
    vis[u] = 1;
    up[u][0] = p;
    for (ll i = 1; i <= l; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    vis[u] = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!vis[v])
            lev[v] = lev[u] + 1, dfs(v, u);
    }
    tout[u] = ++tim;
}
bool is_ancestor(ll u, ll v)
{
    if ((tin[v] >= tin[u]) && (tout[u] >= tout[v]))
        return true;
    return false;
}
ll lca(ll u, ll v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; i--)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    l = 20;
    cin >> n;
    f(0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, 1);
    ll q;
    cin >> q;
    while (q--)
    {
        ll x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        ll ab = lca(a, b);
        ll dab = lev[a] - lev[ab] + lev[b] - lev[ab];
        if (((dab ^ k) & 1) == 0)
            if (dab <= k)
            {
                cout << "YES\n";
                continue;
            }
        ll xy = lca(x, y);
        ll dxy = 1;
        ll ax = lca(a, x);
        ll by = lca(b, y);
        ll dab1 = lev[a] - lev[ax] + lev[x] - lev[ax] + lev[b] - lev[by] + lev[y] - lev[by] + dxy;
        if (((dab1 ^ k) & 1) == 0)
            if (dab1 <= k)
            {
                cout << "YES\n";
                continue;
            }
        ll ay = lca(a, y);
        ll bx = lca(b, x);
        ll dab2 = lev[a] - lev[ay] + lev[y] - lev[ay] + lev[x] - lev[bx] + lev[b] - lev[bx] + dxy;
        if (((dab2 ^ k) & 1) == 0)
            if (dab2 <= k)
            {
                cout << "YES\n";
                continue;
            }
        // cout << dab << " " << dab1 << " " << dab2 << " " << k << "\n";
        cout << "NO\n";
    }
}