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
ll d[3][200005];
ll p[200005];
vll adj[200005];
ll pre[200005];
void bfs(ll f, ll s)
{
    queue<ll> q;
    q.push(s);
    d[f][s] = 0;
    unordered_map<ll, ll> vis;
    vis[s] = 1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto i : adj[u])
        {
            if (vis[i] == 0)
            {
                d[f][i] = d[f][u] + 1;
                vis[i] = 1;
                q.push(i);
            }
        }
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        f(0, n + 1) adj[i].clear(), d[0][i] = 0, d[2][i] = 0, d[2][i] = 0;
        f(1, m + 1) cin >> p[i];
        f(0, m)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        bfs(0, a);
        bfs(1, b);
        bfs(2, c);
        sort(p + 1, p + m + 1);
        pre[0] = 0;
        f(1, m + 1)
            pre[i] = pre[i - 1] + p[i];
        ll ans = 1e18;
        f(1, n + 1)
        {
            ll k = d[0][i] + d[1][i] + d[2][i];
            if (k > m)
                continue;
            ans = min(ans, pre[k] + pre[d[1][i]]);
        }
        cout << ans << "\n";
    }
}