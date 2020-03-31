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

vll g[100005], gr[100005];
vector<bool> used;
vector<int> order, component;
ll parent[100005];
ll siz[100005];
ll vis[100005];
vll cg[100005];
void make_set(int v)
{
    parent[v] = v;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
void dfs1(int v)
{
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i)
        if (!used[g[v][i]])
            dfs1(g[v][i]);
    order.push_back(v);
}

void dfs2(int v)
{
    used[v] = true;
    component.push_back(v);
    for (size_t i = 0; i < gr[v].size(); ++i)
        if (!used[gr[v][i]])
            dfs2(gr[v][i]);
}
void dfs3(ll u)
{
    vis[u] = 1;
    ll p = find_set(u);
    for (auto i : g[u])
    {
        ll c = find_set(i);
            if (c != p)
                cg[p].pb(c);
        if (vis[i] == 0)
            dfs3(i);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    f(0, n) parent[i] = i, siz[i] = 1;
    f(0, m)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    used.assign(n, false);
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    vll pp;
    for (int i = 0; i < n; ++i)
    {
        int v = order[n - 1 - i];
        if (!used[v])
        {
            dfs2(v);
            ll p = component[0];

            for (auto j : component)
                 union_sets(p, j);
           
            pp.pb(find_set(p));
            component.clear();
        }
    }
    f(0, n)
    {
        if (vis[i] == 0)
            dfs3(i);
    }
    ll ans = 0;
    for (auto i : pp)
    {
        // cout<<i<<" "<<cg[i].size()<<" "<<ans<<" "<<n<<"\n";
        ans += siz[i] * (n - siz[i]) - cg[i].size();
        n-=siz[i];
    }
    cout << ans;
}