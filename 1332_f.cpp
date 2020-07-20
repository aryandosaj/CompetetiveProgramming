#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 998244353 
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
vll adj[300006];
ll dp[300005][3];
void dfs(ll u, ll p)
{
    dp[u][0]=dp[u][1]=dp[u][2]=1;
    for (auto i : adj[u])
    {
        if (i != p)
        {
            dfs(i, u);
            dp[u][0] = (dp[u][0] *( 2 * dp[i][0] + 2 * dp[i][1] - dp[i][2]) % MOD)%MOD;
            dp[u][1] = (dp[u][1] *( 2 * dp[i][0] + dp[i][1] - dp[i][2]) % MOD)%MOD;
            dp[u][2] = (dp[u][2] *( dp[i][0] + dp[i][1] - dp[i][2]) % MOD)%MOD;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    f(0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    ll ans = (dp[1][0]+dp[1][1]-dp[1][2]-1+2*MOD)%MOD;
    cout<<ans<<"\n";
}