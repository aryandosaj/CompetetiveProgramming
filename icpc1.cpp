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
vll graph[1005];
map<ll, ll> vis;
bool dfs(ll u, ll p)
{
    vis[u] = 1;
    bool a = 0;
    for (auto i : graph[u])
    {
        if (i == p)
            continue;
        if (vis[i] == 0)
        {
            a = a | dfs(i, u);
        }
        else
        {
            a = 1;
        }
    }
    return a;
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
        ll n;
        cin >> n;
        ll l[n], r[n], v[n];
        set<ll, ll> s;
        map<ll, vector<pair<ll, pair<ll, ll>>>> mp;
        map<ll, ll> dir;
        for (int i = 0; i < n; i++)
        {
            cin >> l[i] >> r[i] >> v[i];
            mp[v[i]].push_back({i, {l[i], r[i]}});
        }
        ll f = 0;
        for (auto i : mp)
        {
            for (int j = 0; j < i.second.size(); j++)
                graph[j].clear();
            vis.clear();
            for (int j = 0; j < i.second.size(); j++)
            {
                ll l1 = i.second[j].second.first;
                ll r1 = i.second[j].second.second;
                int c = 0;
                for (int k = j+1; k < i.second.size(); k++)
                {
                    if (j != k)
                    {
                        ll l2 = i.second[k].second.first;
                        ll r2 = i.second[k].second.second;
                        if (!(r1 < l2 || r2 < l1))
                        {
                            graph[j].push_back(k);
                            graph[k].push_back(j);
                        }
                    }
                }
            }
            for (int k = 0; k < i.second.size(); k++)
            {
                ll h = 0;
                if (vis[k] == 0)
                    h = dfs(k, -1);
                if (h)
                {
                    f = 1;
                    break;
                }
            }
        }
        if (f == 0)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}