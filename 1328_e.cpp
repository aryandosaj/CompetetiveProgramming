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
ll tin[200005];
ll tout[200005];
vll adj[200005];
ll lev[200005];
ll par[200005];
ll t;
bool comp(ll a, ll b)
{
    return lev[a] > lev[b];
}
void dfs(ll u, ll p)
{
    par[u] = p;
    tin[u] = t++;
    for (auto i : adj[u])
        if (i != p)
            lev[i] = lev[u] + 1, dfs(i, u);
    tout[u] = t++;
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
    t = 0;
    cin >> n >> m;
    f(0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    f(0, m)
    {
        ll k;
        cin >> k;
        vll v;
        fi(0, k)
        {
            ll x;
            cin >> x;
            v.pb(x);
        }
        sort(v.begin(), v.end(), comp);
        ll ti = tin[v[0]];
        ll to = tout[v[0]];
        bool ans = 1;
        f(1, k)
        {
            ll p = par[v[i]];
            if (tin[v[i]] <= ti && tout[v[i]] >= to)
                ti = tin[v[i]],
                to = tout[v[i]];
            else if (tin[p] <= ti && tout[p] >= to)
                ti = tin[p],
                to = tout[p];
            else
            {
                ans = 0;
                break;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}