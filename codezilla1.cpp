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
ll dp[100005][4][4];
vll graph[100005];
ll n;
ll dfs(ll u, ll p, ll x, ll px)
{
    if (u == n)
    {
        if (x==px)
            return 1;
        else
            return 0;
    }
    ll ans = 0;
    if (dp[u][x][px] != -1)
        return dp[u][x][px];
    ll ans2 = 0;
    for (ll j = 0; j < 4; j++)
    {
        ans = 1;
        for (auto i : graph[u])
        {
            if (i != p)
            {
                ans =(ans* dfs(i, u, x ^ j, px))%MAX;
            }
        }
        ans2 += ans;
        ans2 = ans2%MAX;
    }

    return dp[u][x][px] = ans2;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        for (ll i = 0; i < 100005; i++){graph[i].clear();
            for (ll j = 0; j < 4; j++)
                for (ll k = 0; k < 4; k++)
                    dp[i][j][k] = -1;
        }
        cin >> n;
        for (ll i = 0; i < n - 2; i++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(n==2){cout<<"4\n";continue;}
        // cout<<n<<"\n";
        for(ll i=2;i<=n-1;i++)
        {
            if(graph[i].size()==1){
                graph[i].push_back(n);
                // graph[n].push_back(i);
            }
        }
        
        ll ans = 0;
        ans += dfs(1, -1, 0, 0);
        // cout<<ans<<"\n";
        ans += dfs(1, -1, 0, 1);
        // cout<<ans<<"\n";
        ans += dfs(1, -1, 0, 2);
        // cout<<ans<<"\n";
        ans += dfs(1, -1, 0, 3);
        cout << ans%MAX << "\n";
    }
}