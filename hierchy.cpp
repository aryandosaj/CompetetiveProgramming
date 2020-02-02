#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000007
unordered_map<ll, ll> vis;
unordered_map<ll, ll> com;
ll l[200001];
vll graph[100001];
ll dfs(ll u, ll p)
{
    vis[u] = 1;
    ll s = 0;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!vis[v])
        {
            s += dfs(v, u);
        }
    }
    l[s]++;
    return s + 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vis.clear();com.clear();
        for (ll i = 0; i <= 100000; i++)
        {
            l[i] = 0;
            graph[i].clear();
        }
        for (ll i = 0; i < n - 1; i++)
        {
            ll u, v;
            cin >> u >> v;
            com[v] = 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        ll root;
        for (ll i = 1; i <= n; i++)
            if (!com[i])
            {
                root = i;
                break;
            }
        dfs(root, -1);

        ll s = 0, w = 0;
        ll pre[n + 1];
        pre[0] = l[0];
        for (ll i = 1; i <= n; i++)
        {
            s += l[i] * i;
            pre[i] = pre[i - 1] + l[i];
            // cout<<pre[i]<<" ";
        }

        for (ll i = 0; i + k < n; i++)
        {
            w += pre[i] * l[i + k];
        }
        cout << s << " " << w << "\n";
    }
}