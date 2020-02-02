#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000007
vll graph[100005];
ll dp[100005][2][2];
ll dfs(ll u, ll de, ll f, ll p)
{
    if (dp[u][de][f] != -1)
        return dp[u][de][f];
    ll ans = 1;
     
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v != p)
        {
            if (f == 1)
                ans *= dfs(v, 1 - de, 0, u);
            else
                ans *= (dfs(v, de, 1, u) + dfs(v, 1 - de, 0, u));
            ans=ans%MAX;
        }
    }
    // if(ans==0)return 1;
    return dp[u][de][f] = ans % MAX;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 0; i < 100005; i++)for(ll j=0;j<2;j++)
        dp[i][j][0] = -1, dp[i][j][1] = -1;
    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<(dfs(1,1,0,0)+dfs(1,0,0,0))%MAX;
}