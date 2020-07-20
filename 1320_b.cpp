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
vll adj[200005];
ll vis[200005];
ll dis[200005];
ll paths[200005];
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
    f(0, m)
    {
        ll u, v;
        cin >> u >> v;
        // adj[u].pb(v);
        adj[v].pb(u);
    }
    ll k;
    cin >> k;
    vll p;
    f(0, k)
    {
        ll x;
        cin >> x;
        p.pb(x);
    }
    ll s = p[p.size() - 1];
    queue<ll> bfs;
    bfs.push(s);
    vis[s] = 1;
    while (!bfs.empty())
    {
        ll u = bfs.front();
        bfs.pop();
        for (auto i : adj[u])
        {
            if (vis[i] == 0)
            {
                dis[i] = dis[u] + 1;
                vis[i] = 1;
                bfs.push(i);
            }
            else
            {
                ll d = dis[u] + 1;
                if (d == dis[i])
                {
                    vis[i]++;
                    // bfs.push(i);
                }
            }
        }
    }
    ll d = k - 1;
    ll ma = 0;
    ll mi = 0;
    ll m_len = dis[p[0]];
    ll last = 0;
    for (auto i : p)
    {
        // cout << i << " " << vis[i] << " " << m_len << " " << dis[i] << " "<<mi<<" "<<ma<<"\n";
        if (dis[i] > m_len)
        {
            m_len = dis[i];
            mi++;
            ma++;
        }
        else if (last != 0 && vis[last] > 1)
            ma++;
        last = i;
        m_len--;
    }
    cout << mi << " " << ma;
}