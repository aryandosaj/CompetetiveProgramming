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
vll graph[300005];
ll dsu[300005];
unordered_map<ll, ll> vis;
unordered_map<ll, ll> visit;
queue<ll> qu;
ll find(ll u)
{
    while (dsu[u] != u)
        u = dsu[u];
    return u;
}
ll dfs(ll u, ll p)
{
    // cout<<u<<" ";
    vis[u] = 1;
    dsu[u] = p;
    ll ml = 0;
    ll m1 = 0, m2 = 0;
    for (ll i = 0; i < graph[u].size(); i++)
    {

        ll v = graph[u][i];
        if (!vis[v])
        {
            if (u != p)
                ml = max(ml, dfs(v, p));
            else
            {
                ll mm = dfs(v, p);
                if (mm > m1)
                {
                    m2 = m1;
                    m1 = mm;
                }
                else if (mm > m2)
                {
                    m2 = mm;
                }
            }
        }
    }
    if (u == p)
        return m1 + m2;
    else
    {
        return ml + 1;
    }
}
void d(ll u)
{
    vis[u] = 1;
    if (graph[u].size() <= 1)
    {
        qu.push(u);
    }
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!vis[v])
        {
            d(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    unordered_map<ll, ll> len;
    for (ll i = 0; i < 300005; i++)
        dsu[i] = i;
    for (ll i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            d(i);
            while (qu.size() > 1)
            {
                ll u = qu.front();
                visit[u] = 1;
                qu.pop();
                for (ll i = 0; i < graph[u].size(); i++)
                {
                    ll v = graph[u][i];
                    if (!visit[v])
                    {
                        qu.push(v);
                    }
                }
            }
            ll p = qu.front();
            qu.pop();
            vis.clear();
            len[p] = dfs(p, p);
            // cout << len[p] << "\n";
        }
    }
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x;
            cin >> x;
            ll p = find(x);
            cout << len[p] << "\n";
        }
        else
        {
            ll x, y;
            cin >> x >> y;
            ll fx = find(x);
            ll fy = find(y);
            if(fx==fy)continue;
            ll lx = len[fx];
            ll ly = len[fy];
            ll oo = (ll)(ceil((lx / 2.0)) + ceil(ly / 2.0) + 1);
            dsu[fx] = dsu[fy];
            len[fy] = max(lx,max(ly,oo));
            
        }
    }
}