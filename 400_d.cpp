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
ll kt[1000];
ll dsu[100005];
vll graph[100005];
vll graph1[100005];
unordered_map<ll, ll> vis;
unordered_map<ll, ll> cnt;
unordered_map<ll, ll> ind;
unordered_map<ll, unordered_map<ll, ll>> w;
ll dp[501][501];

void dfs(ll u)
{
    cnt[dsu[u]]++;
    vis[u] = 1;
    for (ll i = 0; i < graph1[u].size(); i++)
    {
        ll v = graph1[u][i];
        if (!vis[v])
            dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, kk;
    cin >> n >> m >> kk;
    ll ii = 1;
    for (ll i = 1; i <= kk; i++)
    {
        cin >> kt[i];
    }

    ll c = 0;
    for (ll i = 1; i <= n; i++)
    {
        ind[ii] = i;
        dsu[i] = ii;
        c++;
        if (c == kt[ii])
            ii++, c = 0;
    }
    //    for(ll i=1;i<=n;i++)cout<<dsu[i]<<" ";
    for (ll i = 0; i < 501; i++)
        for (ll j = 0; j < 501; j++)
            dp[i][j] = MAX;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, x;
        cin >> u >> v >> x;
        if (x == 0)
            graph1[u].push_back(v), graph1[v].push_back(u);
        if (dsu[u] != dsu[v])
            graph[dsu[u]].push_back(dsu[v]), graph[dsu[v]].push_back(dsu[u]), dp[dsu[u]][dsu[v]] = min(x, dp[dsu[u]][dsu[v]]), dp[dsu[v]][dsu[u]] = min(x, dp[dsu[v]][dsu[u]]);
    }
    for (ll i = 1; i <= kk; i++)
    {
        dfs(ind[i]);
        if (cnt[i] != kt[i])
        {
            // cout<<kt[i]<<" "<<cnt[i]<<" "<<i<<" ";

            cout << "No";
            return 0;
        }
        vis.clear();cnt.clear();
    }
    for (ll k = 1; k <= kk; k++)
    {
        for (ll i = 1; i <= kk; i++)
        {
            for (ll j = 1; j <= kk; j++)
            {
                if (i != k && i != j && j != k)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    cout << "Yes\n";
    for (ll i = 1; i <= kk; i++)
    {
        for (ll j = 1; j <= kk; j++)
        {
            if (i != j)
            {
                if (dp[i][j] != MAX)
                    cout << dp[i][j] << " ";
                else
                    cout << "-1 ";
            }
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}