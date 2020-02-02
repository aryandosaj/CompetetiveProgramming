#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define vll vector<ll>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        map<long long, vector<pair<ll, ll>>> mp;
        unordered_map<ll, ll> vis;
        long long ww[100005];
        ll dp[100005];
        ll n, m;
        cin >> n >> m;
        for (ll i = 1; i <= n; i++)
            cin >> ww[i];
        for (ll i = 0; i < m; i++)
        {
            ll u, v, w;
            cin >> u >> v;
            if (ww[u] < ww[v])
                mp[ww[v] - ww[u]].push_back(make_pair(u, v));
            if (ww[u] > ww[v])
                mp[ww[u] - ww[v]].push_back(make_pair(v, u));
        }
        ll ans = 0;
        ll c = 0;
        for (auto j : mp)
        {
            vll v;
            for (auto i : j.second)
            {
                if ((vis[i.first] == 0))
                {
                    v.push_back(1);
                    continue;
                }
                if ((vis[i.first] == 1))
                    v.push_back(dp[i.first] + 1);
            }
            ll c = 0;
            for (auto i : j.second)
            {
                dp[i.second] = max(dp[i.second], v[c++]);
                ans = max(ans, dp[i.second]);
                vis[i.first] = 1;
                vis[i.second] = 1;
            }
        }
        cout << ans + 1 << "\n";
    }
}