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
ll tower[200005];
ll p[200005];
vll adj[200005];
ll getp(ll u)
{
    return p[u] = (u == p[u]) ? u : getp(p[u]);
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
    ll ans = n - 1;
    f(0, m + 1) p[i] = i;
    f(1, n + 1)
    {
        ll x;
        cin >> x;
        tower[i] = x;
        adj[x].pb(i);
        if (i)
            ans = ans - (tower[i] == tower[i - 1]);
    }
    cout << ans << "\n";
    ll q = m - 1;
    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        u = getp(u);
        v = getp(v);
        if (adj[u].size() > adj[v].size())
            swap(u, v);
        for (auto i : adj[u])
        {
            if (tower[i + 1] == v)
                ans--;
            if (tower[i - 1] == v)
                ans--;
        }
        for (auto i : adj[u])
            adj[v].pb(i), tower[i] = v;
        p[u] = v;
        cout << ans << "\n";
    }
}