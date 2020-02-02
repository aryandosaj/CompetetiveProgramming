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
vll graph[300005];
// unordered_map<ll, vector<unordered_map<ll, ll>>> weight;
map<ll, vector<pair<ll, ll>>> mp;
priority_queue<pair<ll, ll>> pq;
unordered_map<ll, ll> vis;
ll dp[300005];
int main()
{
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        // weight[u][v] = w;
        mp[w].push_back(make_pair(u, v));
    }
    ll ans = 0;ll c=0;
    for (auto j : mp)
    {
        c++;
        for (auto i : j.second)
        {
            if (vis[i.first])
            {
                if(vis[i.first]!=c)
                    dp[i.second] = dp[i.first] + 1;
                vis[i.second] = c;
            }
            else
            {
                if (!vis[i.second])
                    dp[i.second] = 1,vis[i.second]=c;
                dp[i.first] = 1;
                vis[i.first] = c;
            }
            ans = max(ans, dp[i.second]);
            ans = max(ans, dp[i.first]);
        }
    }
    cout << ans;
}