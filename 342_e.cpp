#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define L 20
#define NUM 100005
set<ll> graph[NUM];
vll d_graph[NUM];
ll child[NUM];
ll n, m;
ll dad[NUM];
ll up[NUM][L+1];
ll tin[NUM], tout[NUM];
ll lev[NUM];
ll nearest_red[NUM];
ll red[NUM];
ll tim;
ll dfs(ll u, ll p)
{
    ll ans = 0;
    child[u] = 0;
    for (auto i : graph[u])
        if (i != p)
            ans += dfs(i, u);
    child[u] = ans + 1;
    return ans + 1;
}
ll reposition(ll u, ll p, ll num)
{
    for (auto i : graph[u])
        if (i != p && (child[i] > num / 2))
            return reposition(i, u, num);
    return u;
}
bool is_ancestor(ll u, ll v)
{
    if(u==0)return 1;
    if ((tin[u] < tin[v]) && (tout[v] < tout[u]))
        return 1;
    return 0;
}
ll lca(ll u, ll v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = L; i >= 0; i--)
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}
void dfs_lca(ll u, ll p)
{
    tin[u] = tim++;
    // if (p != -1)
        up[u][0] = p;
    for (int i = 1; i <= L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto i : d_graph[u])
        if (i != p)
            lev[i] = lev[u] + 1, dfs_lca(i, u);
    tout[u] = tim++;
}
ll dist(ll u, ll v)
{
    ll l_c_a = lca(u, v);
    ll d = (lev[u] - lev[l_c_a]) + (lev[v] - lev[l_c_a]);
    return d;
}
void decom(ll u, ll p)
{
    ll num = dfs(u, p);
    ll centroid = reposition(u, p, num);
    if (p == 0)
        dad[centroid] = centroid;
    else
        dad[centroid] = p;
    for (auto i : graph[centroid])
    {
        graph[i].erase(centroid);
        decom(i, centroid);
    }   
    graph[centroid].clear();
}
ll query(ll u)
{
    ll start = u;
    ll ans = nearest_red[u];
    while (dad[u] != u)
    {
        u = dad[u];
        ans = min(ans, dist(start, u) + nearest_red[u]);
    }
    return ans;
}
void update(ll u)
{
    ll start = u;
    red[u] = 1;
    nearest_red[u] = 0;
    while (u != dad[u])
    {
        u = dad[u];
        nearest_red[u] = min(nearest_red[u], dist(u, start));
    }
    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[v].insert(u);
        graph[u].insert(v);
        d_graph[v].push_back(u);
        d_graph[u].push_back(v);
    }
    
    for (int i = 0; i < NUM; i++)
        nearest_red[i] = MAX;
    
    dfs_lca(1, 0);
    decom(1, 0);
    update(1);
    while (m--)
    {
        ll t, u;
        cin >> t >> u;
        if (t == 1)
            update(u);
        else
            cout << query(u) << "\n";
    }
}