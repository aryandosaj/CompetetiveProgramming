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
vll graph[2000];
ll parent[2000];
ll md;
vector<ll> v;
void get_dfs(ll u, ll p, ll d, ll rd)
{
    if (d == rd)
    {
        v.pb(u);
        return;
    }
    for (auto i : graph[u])
    {
        if (i != p)
            get_dfs(i, u, d + 1, rd);
    }
}
void dfs(ll u, ll p, ll d)
{
    parent[u] = p;
    md = max(md, d);
    for (auto i : graph[u])
    {
        if (i != p)
            dfs(i, u, d + 1);
    }
}
pl query()
{
    cout << "? " << v.size() << " ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    ll d, u;
    cin >> u >> d;
    return {u, d};
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        md = 0;
        v.clear();
        f(0, 2000) graph[i].clear(), parent[i] = 0;
        ll n;
        cin >> n;
        f(0, n-1)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        cout << "? " << n << " ";
        f(1, n + 1) cout << i << " ";
        cout << endl;
        ll start, d;
        cin >> start >> d;
        dfs(start, 0, 0);
        ll l = 0, h = md;   
        ll last = start;
        ll k = 0;
        ll ans = 0;
        while (l <= h)
        {
            ll m = (l + h) / 2;
            v.clear();
            get_dfs(last, parent[last], 0, m);
            pl q = query();
            if (q.second == d)
            {
                l = m + 1;
                ans = q.first;
                // k = m;
                // last = q.first;
            }
            else
                h = m - 1;
        }
        v.clear();
        get_dfs(ans, 0, 0, d);
        pl q = query();
        cout << "! " << ans << " " << q.first << endl;
        string ret;
        cin >> ret;
        if (ret.compare("Correct") != 0)
            return 0;
    }
}