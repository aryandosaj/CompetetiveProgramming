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
ll flag;
void rec(ll u, ll k)
{
    vis[u] = k;
    for (auto i : adj[u])
    {
        if (vis[i] == k)
        {
            flag = 1;
            return;
        }
        else if (vis[u] == 0)
            rec(i, k);
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
    ll n, m;
    cin >> n >> m;
    f(0, m)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    f(1, n + 1)
    {
        if (vis[i] == 0)
            rec(i, i);
    }
    if (flag)
    {
        cout << "-1\n";
    }
    else
    {
        cout << n - 1 << "\n";
        f(0, n - 1) cout << 'A';
        cout << "E\n";
    }
}