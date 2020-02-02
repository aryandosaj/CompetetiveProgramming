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
ll arr[200005];
vll graph[200005];
map<ll, ll> visit;
map<ll, ll> child;
map<ll, ll> level;
map<ll, ll> val;
ll n;
void dfs(ll u)
{
    visit[u] = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!visit[v])
        {
            level[v] = level[u] + 1;
            dfs(v);
            child[u] += child[v] + 1;
            val[u] +=val[v]+arr[v];
        }
    }
}
ll ans = 0,sum=0;
void rec(ll u, ll d)
{
    // cout << d << " ";
    ans = max(ans, d);
    visit[u] = 1;
    // d = d - val[u];
    for (ll i = 0; i < graph[u].size(); i++)
    {

        ll v = graph[u][i];
        if (!visit[v])
        {
            ll dd = d - (val[v] + arr[v]) + (sum - (val[v] + arr[v]));
            rec(v, dd);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum+=arr[i];
    }

    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    visit.clear();
    ll d = 0;
    for (ll i = 1; i <= n; i++)
    {
        d += level[i] * arr[i];
    }
    rec(1, d);
    cout << ans;
    // cout<<child[2];
}