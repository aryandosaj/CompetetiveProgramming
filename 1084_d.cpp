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
#define MAX 1000000000000
ll w[300005];
vll graph[300005];
map<ll, ll> vis;
map<ll, map<ll, ll>> mp;

ll ans = 0;
ll dfs(ll u)
{
    // cout<<a<<"-";
    // cout<<ans<<" "<<u<<"\n";

    ll best = 0;
    ll a = w[u];
    vis[u]=1;
    ll m1=0,m2=0;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!vis[v])
        {
            best = dfs(v);
            if((best-mp[u][v])>=m1)
            {
                m2=m1;
                m1=best-mp[u][v];
            }
            else if((best-mp[u][v])>=m2)
            {
                m2=best-mp[u][v];
            }
        }
        
    }
    ans = max(ans, m1+m2+w[u]);
    return a+m1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    w[0] = 0;
    ll s = 0;
    ll mm = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v, ww;
        cin >> u >> v >> ww;
        graph[u].push_back(v);
        graph[v].push_back(u);
        mp[u][v] = ww;
        mp[v][u] = ww;
    }
    if (n == 1)
    {
        cout << w[1];
        return 0;
    }
    ll t =dfs(1);
    ans= max(t,ans);
    cout << ans<<"\n";    
    // for(ll i = 1; i <= n; i++)
    // {
    //     cout<<w[i]<<" ";
    // }
    
}