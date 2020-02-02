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
ll n;
vll graph[201];
vll child;
unordered_map<ll, ll> level;
ll ans = 0;
unordered_map<ll, ll> vis;
unordered_map<ll, unordered_map<ll, ll>> mp;
ll mm = 0;
ll net = 0;
void dfs(ll u, ll p)
{
    // cout<<u<<" ";
    if (mm <= level[u])
    {
        mm = level[u];
        net = u;
    }
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if ((v != p) && (mp[u][v] == 0))
        {
            level[v] = level[u] + 1;
            dfs(v, u);
        }
    }
}
ll diameter(ll u)
{
    level.clear();
    mm = 0;
    dfs(u, 0);
    mm = 0;
    level.clear();
    // cout<<u<<" "<<net<<"\n";
    dfs(net, 0);
    return mm;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    stack<ll> st;
    st.push(1);
    ll ans = 0;
    while (!st.empty())
    {
        ll u = st.top();
        st.pop();
        vis[u] = 1;
        for (ll i = 0; i < graph[u].size(); i++)
        {
            ll v = graph[u][i];
            if (!vis[v])
            {
                mp[u][v] = 1;
                mp[v][u] = 1;
                ans = max(ans, diameter(u) * diameter(v));
                // cout << (u) << " " << (v) << "\n";
                // cout << diameter(u) << " " << diameter(v) << "\n";
                st.push(v);
                mp[u][v] = 0;
                mp[v][u] = 0;
            }
        }
    }
    cout << ans;
}