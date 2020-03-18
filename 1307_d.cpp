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
ll d1[200005];
ll dn[200005];
ll vis[200005];
ll sp[200005];
vll s;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    f(0, k)
    {
        ll x;
        cin >> x;
        sp[x] = 1;
        s.pb(x);
    }
    f(0, m)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<ll> q;
    q.push(1);
    vis[1]=1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        
        
        for (auto i : adj[u])
        {
            if (vis[i] == 0)
            {
                vis[i]=1;
                d1[i] = d1[u] + 1;
                q.push(i);
            }
        }
    }

    f(0, n + 1) vis[i] = 0;
    q.push(n);
    vis[n]=1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        
        for (auto i : adj[u])
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                dn[i] = dn[u] + 1;
                q.push(i);
            }
        }
    }
    // f(1, n + 1) cout << dn[i] << " "<<d1[i]<<"\n";
    // cout << "\n";
    ll ans = 0;
    ll temp = 0;
    pll v;
    for (auto i : s)
        v.pb({d1[i] - dn[i], i});
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll yb = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            ans = max(ans, d1[v[i].second] + 1 + yb);
        yb = max(yb, (dn[v[i].second]));
    }
    cout << min(ans, dn[1]);
}