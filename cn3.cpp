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
vll graph[100005];
vll rgraph[100005];
ll ans[100005][2];
ll x;
ll dfs(ll u, ll num)
{
    
    ll a = 0;
    num++;
    if (ans[u][num & 1] != -1)
        return ans[u][num & 1];
    if ((u == x) && ((num & 1) == 0))
        return 1;
    if (u == x)
        return 0;
    for (auto i : rgraph[u])
    {
        a = (a + dfs(i, num)) % MAX;
    }
    return ans[u][num & 1] = a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while (t--)
    {
        for (ll i = 1; i <= 100000; i++)
            rgraph[i].clear(), ans[i][0] = -1, ans[i][1] = -1;
        ll n, m;
        cin >> n >> m >> x;
        for (ll i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            rgraph[v].push_back(u);
        }
        for (ll i = 1; i <= n; i++)
        {
            cout << dfs(i, 0) << " ";
        }
        cout<<"\n";
    }
}