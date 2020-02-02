#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
ll dista[1003], distb[1003];
vll graph[1003];
ll a, da, b, db;
ll flag, node;
void dfsa(ll u, ll p)
{
    if (dista[u] >= da)
        return;
    for (auto i : graph[u])
    {

        if (i != p)
        {
            dista[i] = dista[u] + 1;
            dfsa(i, u);
        }
    }
}
void dfsb(ll u, ll p)
{
    if (flag)
        return;
    if (distb[u] == db && dista[u] == da)
    {
        flag = 1;
        node = u;
        return;
    }
    if (distb[u] > db)
        return;
    for (auto i : graph[u])
    {

        if (i != p)
        {
            distb[i] = distb[u] + 1;
            dfsb(i, u);
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        for (int i = 0; i <= n; i++)
            dista[i] = 0, distb[i] = 0, graph[i].clear();
        for (int i = 0; i < n - 1; i++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        while (q--)
        {
            for (int i = 0; i <= n; i++)
            dista[i] = 0, distb[i] = 0;
            flag = 0;
            cin >> a >> da >> b >> db;
            dfsa(a, -1);
            dfsb(b, -1);
            if (flag)
            {
                cout << node << "\n";
            }
            else
                cout << "-1\n";
        }
    }
}