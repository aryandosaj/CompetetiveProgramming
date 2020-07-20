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
vll adj[100005];
ll child[100005];
ll d;
ll f;
void dfs(ll u, ll p)
{
    for (auto i : adj[u])
    {
        if (i != p)
        {
            dfs(i, u);
            child[u] += child[i] + 1;
        }
    }
}
void dfs1(ll u, ll p)
{
    ll o = 0;
    for (auto i : adj[u])
        if (child[i] == 0)
            o++;
    if (o)
        d += o - 1;
    for (auto i : adj[u])
    {
        if (i != p && child[i] > 1)
            dfs1(i, u);
    }
}
ll dfs2(ll u, ll p)
{
    // cout<<u<<"\n";
    ll c = 0;
    vll v;
    for (auto i : adj[u])
    {
        if (i != p)
            v.pb(dfs2(i, u));
    }

    f(0, (ll)v.size() - 1)
    {
        if (v[i] != v[i + 1])
        {
            f = 1;
            return 0;
        }
    }
    if (v.size()>0)
        return 1 - v[0];
    return 0;
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
    ll root;
    f(0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        if (adj[u].size() > 1)
            root = u;
        if (adj[v].size() > 1)
            root = v;
    }
    dfs(root, 0);
    dfs1(root, 0);
    // f(1,n+1)cout<<child[i]<<" ";
    // cout << root << "\n";
    ll mx = n - 1 - d;
    ll mn = 1;
    dfs2(root, 0);
    if (f)
        mn = 3;

    cout << mn << " " << mx;
}