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
ll val[200005];
ll rec[200005];
ll flag;
stack<ll> st;
void dfs(ll u)
{
    vis[u] = 1;
    rec[u]=1;
    for (auto i : adj[u])
    {
        if (vis[i] == 1&& rec[i]==1)
            flag = 1;
        else if (vis[i] == 0)   
            dfs(i);
    }
    rec[u]=0;
}
void ts(ll u)
{
    vis[u] = 1;
    for (auto i : adj[u])
    {
        if (vis[i] == 0)
            ts(i);
    }
    st.push(u);
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
        pll edge;
        flag = 0;
        ll n, m;
        cin >> n >> m;
        f(0, n + 1) adj[i].clear(), vis[i] = 0, val[i] = 0;
        ll c = 1;
        f(0, m)
        {
            ll k, u, v;
            cin >> k >> u >> v;
            if (k)
                adj[u].pb(v);
            else
                edge.pb({u, v});
        }
        f(1, n + 1) if (vis[i] == 0)
            dfs(i);
        if (flag)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        f(1, n + 1) vis[i] = 0;
        f(1, n + 1) if (vis[i] == 0) ts(i);
        c = 1;
        while (!st.empty())
            val[st.top()] = c++, st.pop();
        for (auto i : edge)
        {
            if (val[i.first] < val[i.second])
                adj[i.first].pb(i.second);
            else
                adj[i.second].pb(i.first);
        }
        f(1, n + 1) for (auto j : adj[i]) cout << i << " " << j << "\n";
    }
}