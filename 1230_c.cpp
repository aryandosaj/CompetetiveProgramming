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
vll graph[10];
ll d[10];
ll vis[10];
ll freq[10];
void dfs(ll u)
{
    vis[u] = 1;
    // for(auto i:)
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    ll md = 0;
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        d[u]++;
        d[v]++;
        md = max(md, d[u]);
        md = max(md, d[v]);
    }
    if (n < 7)
    {
        cout << m << "\n";
        return 0;
    }
    ll ans=0;

    // for (int i = 1; i <= n; i++)
    // {
    //     if (graph[i].size() < mm)
    //     {
    //         mm = graph[i].size();
    //         ms = i;
    //     }
    // }
    for (int ms = 1; ms <= 7; ms++)
    {
        for(int i=0;i<=7;i++)freq[i]=0;
        ll mm = MAX;
        for (auto i : graph[ms])
        {
            for (int y = 0; y <= n; y++)
                vis[y] = 0;
            for (auto j : graph[i])
            {
                vis[j] = 1;
            }
            for (int j = 1; j <= n; j++)
            {
                if (vis[j] == 0)
                    freq[j]++;
            }
        }
        ll x = 0;
        mm = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i != ms)
            {
                if (mm < freq[i])
                {
                    mm = freq[i];
                    x = i;
                }
            }
        }
        // cout<<m - d[ms] + mm<<"\n";
        ans = max(ans, m - d[ms] + mm);
    }
    cout<<ans<<"\n";
    
}