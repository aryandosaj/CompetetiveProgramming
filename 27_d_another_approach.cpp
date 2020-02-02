#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
bool chk(ll u, ll v, ll a, ll b)
{
    if ((u <= a && v >= b) || (u >= a && v <= b)||(v<=a)||(u>=b))
        return 0;
    return 1;
}
bool bip[105];
bool vis[105];
vll graph[105];
void dfs(ll u, ll c)
{
    vis[u] = 1;
    bip[u] = c;
    for (auto i : graph[u])
    {
        if (vis[i])
            if (bip[i] == c)
            {
                cout << "Impossible"
                     << "\n";
                exit(0);
            }
        if (!vis[i])
        {
            dfs(i, 1 - c);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> vv;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        if (v < u)
            swap(u, v);
        vv.push_back({u, v});
    }
    for (ll i = 0; i < m; i++)
    {
        for (ll j = i + 1; j < m; j++)
        {
            if (chk(vv[i].first, vv[i].second, vv[j].first, vv[j].second))
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    // for (ll i = 0; i < m; i++)
    // {
    //     cout<<i<<" : ";
    //     for(auto j:graph[i])
    //     cout<<j<<" ";
    //     cout<<"\n";
    // }

    for (ll i = 0; i < m; i++)
    {
        if (!vis[i])
        {
            dfs(i, 0);
        }
    }
    for (ll i = 0; i < m; i++)
    {
        if (bip[i])
            cout << "i";
        else
            cout << "o";
    }
}