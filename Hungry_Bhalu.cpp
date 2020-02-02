#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
vll graph[100005];
map<ll, vector<pair<ll, ll>>> mp;
unordered_map<ll, ll> vis;
ll dp[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m>>k;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        mp[w].push_back(make_pair(u, v));
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
    if(ans>=k)cout<<"YES";
    else cout<<"NO";
}