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
ll cc = 0;
#define MAX 998244353
vll graph[300005];
unordered_map<ll, ll> vis;
unordered_map<ll, ll> bp;
ll c1 = 0, c0 = 0;
bool dfs(ll u, ll p)
{
    vis[u] = 1;
    bp[u] = p;
    ll ans = 0;
    cc++;
    if (p)
        c1++;
    else
        c0++;

    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (vis[v])
        {
            if ((bp[v] ^ p) == 0)
            {
                return 1;
            }
        }
        else
        {
            ans = ans | dfs(v, p ^ 1);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        for (ll i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        ll b = 0;
        ll ans = 1;
        ll flag = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, 0))
                {
                    flag = 1;
                    break;
                }
                else
                {
                    ans = (ans * (power(2, c0, MAX)+power(2,c1,MAX)) % MAX) % MAX;
                    
                    cc = 0;
                    c0=0;c1=0;
                }
            }
        }
        if (flag == 0)
            cout << ans << "\n";
        else
            cout << "0\n";

        for (ll i = 0; i <= n; i++)
        {
            graph[i].clear();
        }

        vis.clear();
        cc = 0;
        bp.clear();
        c1=0;c0=0;
    }
}