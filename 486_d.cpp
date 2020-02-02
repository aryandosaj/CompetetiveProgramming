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
ll arr[2001];
vll graph[2001];
vll graph2[2001];
unordered_map<ll, ll> child;
unordered_map<ll, ll> visit;
ll ans = 0, d;
void dfs(ll u, ll p, ll a)
{
    // cout<<u<<"\n";

    if (p != 0)
    {
        if ((a + d) < arr[u])
            return;
        if (arr[u] < a)
            return;
        graph2[u].push_back(p);
        graph2[p].push_back(u);
    }
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v != p)
        {
            dfs(v, u, a);
        }
    }
}
void calc(ll u, ll p,ll a)
{
    // cout << u << " " << p << "\n";
    ll temp = 1;
    for (ll i = 0; i < graph2[u].size(); i++)
    {
        ll v = graph2[u][i];
        if (v != p)
        {
            calc(v, u, a);
            if (!((visit[v])&&(arr[v]==a)))
                (temp *= (child[v] + 1)) ,temp = temp%MAX;
        }
    }
    child[u] = temp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> d >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++)
    {
        dfs(i, 0, arr[i]);
        calc(i, 0,arr[i]);
        visit[i] = 1;
        (ans += child[i]) % MAX;
        ans = ans%MAX;
        for (ll j = 1; j <= n; j++)
            graph2[j].clear();
        child.clear();
    }
    cout << ans%MAX;
}