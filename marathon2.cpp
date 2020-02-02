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
ll arr[100005];
vll graph[100005];
unordered_map<ll, ll> odd;
unordered_map<ll, ll> even;
unordered_map<ll, ll> visit;
unordered_map<ll, ll> level;
ll mo = 0, me = 0;
ll node=0;
ll mm = 0;

void dfs(ll u, ll p)
{
    visit[u]=1;
    // cout<<level[u]<<" ";
    if (level[u] >= mm)
    {
        node = u;
        mm = level[u];
    }
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v != p)
        {
            level[v] = level[u] + 1;
            dfs(v, u);
            
        }
    }
}
ll longest(ll u)
{
    mm = 0;
    dfs(u, 0);
    mm = 0;
    level.clear();
    dfs(node, 0);
    return mm+1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        if (((arr[u] % 2 == 0) && (arr[v] % 2 == 0)) || ((arr[u] % 2 == 1) && (arr[v] % 2 == 1)))
        {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            if (arr[i] & 1)
            {
                mo = max(mo,longest(i));
            }
            else
            {
                me = max(me,longest(i));
            }
        }
    }
    cout << me << " " << mo;
}