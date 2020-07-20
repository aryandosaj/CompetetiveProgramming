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
ll child[200005];
ll dep[200005];
void dfs(ll u, ll p, ll d)
{
    for (auto i : adj[u])
    {
        if (i != p)
        {

            dfs(i, u, d + 1);
            child[u] += child[i] + 1;
        }
    }
    dep[u] = d;
}
ll a = 0;
ll mark[200005];
void dfs1(ll u, ll p, ll v)
{
    if (mark[u] == 1)
        a += v;
    else
        v++;
    for (auto i : adj[u])
    {
        if (i != p)
            dfs1(i, u, v);
    }
}
pll ss;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    f(0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vll ans;
    dfs(1, 0, 0);
    f(1, n + 1) ss.pb({dep[i] - child[i], i});
    sort(ss.begin(), ss.end(), greater<pl>());
    // for (auto i : ss)
    // {
    //     cout << i.first << " " << i.second << "\n";
    // }
    f(0, k)
        mark[ss[i].second] = 1;
    dfs1(1, 0, 0);
    cout << a;
}