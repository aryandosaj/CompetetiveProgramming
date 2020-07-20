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
pll adj[1000006];
ll dp[10004][1003];
vll v;
ll l;
ll g, r;
ll rec(ll u, ll t)
{
    // cout << u << " " << t << " " << dp[u][t] << "\n";
        if (dp[u][t] != -1)
        return dp[u][t];
    if (u == l - 1)
        return dp[u][t] = t;
    dp[u][t] = 1e18;
    ll f = 0;
    if (t == g)
        t = 0, f = 1;
    ll ans = 1e18;
    if (u < l - 1)
    {
        ll u1 = u + 1;
        if (t + v[u1] - v[u] <= g)
            ans = min(ans, rec(u1, t + v[u1] - v[u]));
    }
    if (u > 0)
    {
        ll u1 = u - 1;
        if (t + v[u] - v[u1] <= g)
            ans = min(ans, rec(u1, t + v[u] - v[u1]));
    }
    // cout << u << " " << t << " " << dp[u][t] << " " << ans << "\n";

    if (f)
    {
        dp[u][g] = ans + g + r;
        return dp[u][g];
    }
    dp[u][t] = ans;
    return dp[u][t];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    ll n, m;
    cin >> n >> m;
    f(0, m)
    {
        ll x;
        cin >> x;
        v.pb(x);
    }

    sort(v.begin(), v.end());
    l = v.size();
    f(0, l - 1)
    {
        adj[i + 1].pb({i, v[i + 1] - v[i]});
        adj[i].pb({i + 1, v[i + 1] - v[i]});
    }
    cin >> g >> r;
    ll ans = rec(0, 0);
    if (ans >= 1e18)
        cout << "-1";
    else
        cout << ans;
}