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
ll d[200005];
vll adj[200005];
pll ans;
ll T;
void rec(ll u, ll p, ll t)
{
    ans.pb({u, t});
    ll ti = t;
    ll f = 0;
    for (auto i : adj[u])
    {
        if (i != p)
        {
            ti++;
            
            if (ti % (T + 1) == 0)
            {
                if (d[u] - 1 - f < t - 1)
                    ti = t - d[u] + f;
                else
                    ti = ti % (T + 1);
                ans.pb({u, ti});
                ti++;
            }
            rec(i, u, ti);
            f++;
        }
    }
    //came at t, leave at t-1 to p,t
    if (u == 1)
        return;
    if (ti != (t - 1 + T + 1) % (T + 1))
        ans.pb({u, (t - 1 + T + 1) % (T + 1)});

    ans.pb({p, t});
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
    cin >> n;

    f(0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        d[u]++, d[v]++;
        T = max(T, d[u]);
        T = max(T, d[v]);
    }
    rec(1, 0, 0);
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i.first << " " << i.second << "\n";
}