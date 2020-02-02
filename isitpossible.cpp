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
ll MAX;
ll vis[1003];
ll freq[1003];
vll graph[1003];
set<ll> ss;
ll n;
void dfs(ll u)
{
    bool ans = 0;
    vis[u] = 1;
    for (auto v : graph[u])
    {
        if (vis[v] == 0)
            dfs(v);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll d, m;
    cin >> d >> m;
    MAX = m;
    ss.clear();
    for (int i = 0; i < 1003; i++)
    {
        freq[i] = 0, vis[i] = 0;
        graph[i].clear();
    }

    for (int i = 0; i < d; i++)
    {
        int num;
        cin >> num;
        num = num % MAX;
        ss.insert(num);
        freq[num]++;
    }
    for (int i = 0; i < m; i++)
    {
        for (auto j : ss)
        {
            ll num = (10 * i + j) % MAX;
            graph[num].push_back(i);
        }
    }
    ll ans = 0;
    dfs(0);
    for (auto i : ss)
    {
        if (vis[i])
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}