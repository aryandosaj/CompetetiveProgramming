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
ll p[200005];
ll dist[200005];
vll adj[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, a, b, c;
        map<pl, ll> edge;
        cin >> n >> m >> a >> b >> c;
        f(0, n + 1) adj[i].clear(), dist[i] = 1e18;
        f(1, m + 1) cin >> p[i];
        sort(p + 1, p + m + 1);

        f(0, m)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        unordered_map<ll, ll> vis;
        unordered_map<ll, ll> parent;
        queue<ll> q;
        q.push(b);
        parent[b] = b;
        vis[b] = 1;
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (auto i : adj[u])
            {
                if (vis[i] == 0)
                {
                    parent[i] = u;
                    vis[i] = 1,
                    q.push(i);
                }
            }
        }
        ll x = a;
        vll v;
        ll e = 1;
        v.pb(a);
        while (parent[x] != x)
            x = parent[x], v.pb(x);
        reverse(v.begin(), v.end());
        ll ans = 0;
        f(0, v.size() - 1)
        {
            ans += p[e];
            edge[{v[i], v[i + 1]}] = p[e];
            edge[{v[i + 1], v[i]}] = p[e++];
        }
        // cout << e << "\n";   
        vis.clear();    
        set<pair<pl, ll>> s;    
        s.insert({{0, b}, e});
        dist[b] = 0;
        while (!s.empty())
        {
            ll u = (*s.begin()).first.second;
            ll w = (*s.begin()).first.first;
            ll y = (*s.begin()).second;
            s.erase(s.begin());
            // cout << u << " " << w << "\n";
            for (auto i : adj[u])
            {
                ll ew = p[y];
                if (edge.find({u, i}) != edge.end())
                {
                    ew = edge[{u, i}];
                    if (dist[i] > dist[u] + ew)
                    {
                        dist[i] = dist[u] + ew;
                        s.insert({{dist[i], i}, y});
                    }
                }
                else if (dist[i] > dist[u] + ew)
                {
                    dist[i] = dist[u] + ew;
                    s.insert({{dist[i], i}, y + 1});
                }
            }
        }
        cout << ans + dist[c] << "\n";
    }
}