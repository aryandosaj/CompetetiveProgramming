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
ll dsu[200005];
ll siz[200005];
ll id[200005];
ll leaf[200005];
ll vis[200005];
vll tree[200005];
vector<pair<ll, pair<ll, ll>>> ans;
int c;
ll find(ll u)
{
    while (u != dsu[u])
        u = dsu[u];
    return u;
}
void insert(ll u, ll v)
{
    u = find(u);
    v = find(v);
    if (siz[u] < siz[v])
        swap(u, v);
    dsu[v] = dsu[u];
    siz[u]++;
}
void dfs(ll u, ll p)
{
    vis[u] = 1;
    for (auto i : tree[u])
    {
        if (i != p)
            dfs(i, u);
    }
    int e = 0;
    ll v, w;
    for (auto i : tree[u])
    {
        if (i != p)
        {
            if (leaf[i])
            {
                if (e == 0)
                {
                    v = i;
                    e = 1;
                }
                else
                {
                    e = 0;
                    ans.push_back({id[v], {id[u], id[i]}});
                }
            }
        }
    }
    if (e == 1)
    {
        leaf[u] = 0;
        if (p != -1)
            ans.push_back({id[v], {id[u], id[p]}});
    }
    else
        leaf[u] = 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 200005; i++)
        dsu[i] = i, siz[i] = 1, id[i] = i;
    int n, m;
    cin >> n >> m;
    c = n + 1;
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        if (find(u) != find(v))
        {
            tree[u].push_back(v);
            tree[v].push_back(u);
            insert(u, v);
        }
        else
        {
            id[c] = v;
            tree[u].push_back(c);
            tree[c].push_back(u);
            insert(u, c);
            c++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, -1);
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
}