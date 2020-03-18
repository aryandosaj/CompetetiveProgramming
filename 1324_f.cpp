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
vll graph[200005];
ll a[200005];
ll pre[200005];
ll ans[200005];
ll dfs1(ll u, ll p)
{

    ll ans = a[u];
    for (auto i : graph[u])
        if (i != p)
            ans += max(0ll, dfs1(i, u));
    pre[u] = ans;
    return ans;
}
void dfs2(ll u, ll p, ll v)
{
    ans[u] = pre[u] + max(0ll, v);
    ll val = ans[u];
    for (auto i : graph[u])
    {
        if (i != p)
            dfs2(i, u, val - max(0ll, pre[i]));
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
    ll n;
    cin >> n;
    f(1, n + 1)
    {
        cin >>
            a[i];
        if (a[i] == 0)
            a[i]--;
    }
    f(0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    f(1, n + 1) cout << ans[i] << " ";
}