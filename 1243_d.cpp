#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
// ll siz[100005];
// ll dsu[100005];
// ll find(ll a)
// {
//     while (a != dsu[a])
//         a = dsu[a];
//     return a;
// }
// void join(ll a, ll b)
// {
//     a = find(a);
//     b = find(b);
//     if (a == b)
//         return;
//     if (siz[a] < siz[b])
//         swap(a, b);
//     dsu[b] = a;
//     siz[a] += siz[b];
// }
set<ll> s;
void dfs(ll u)
{
    unordered_map<ll, ll> vis;
    vll v;
    for (auto i : graph[u])
    {
        vis[i] = 1;
    }
    for (auto i : s)
    {
        if (vis[i] == 0)
        {
            v.push_back(i);
        }
    }
    for (auto i : v)
        s.erase(i);
    for (auto i : v)
        dfs(i);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = -1;
    while (1)
    {
        if (s.size() > 0)
        {
            ans++;
            int st = *s.begin();
            s.erase(st);
            dfs(st);
        }
        else
            break;
    }
    cout << ans;
}