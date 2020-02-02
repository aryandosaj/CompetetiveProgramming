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
ll pre[1000016];
ll vis[1003];
ll freq[1003];
vll graph[1003];
set<ll> ss;
ll n;
ll pp[1000006];
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

    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        ll m;
        cin >> s >> m;
        MAX = m;
        ll num = 0, cur = 0;
        ll mul = 1;
        n = s.length();

        ss.clear();
        pp[0] = 1 % m;
        for (int i = 0; i <= n + 1; i++)
            pre[i] = 0;
        for (int i = 1; i <= n + 1; i++)
            pp[i] = (pp[i - 1] * 10) % MAX;
        for (int i = 0; i < 1003; i++)
        {
            freq[i] = 0, vis[i] = 0;
            graph[i].clear();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            pre[i] = (pre[i + 1] + mul * (s[i] - '0')) % MAX;
            mul = (mul * 10) % MAX;
        }
        for (int i = 0; i < n; i++)
        {
            num = (cur + pre[i + 1]) % MAX;
            if (i != n - 1)
                cur = (cur + pp[n - i - 2] * (s[i] - '0')) % MAX;
            ss.insert(num);
            freq[num]++;
        }
        for (int i = 0; i < m; i++)
        {
            for (auto j : ss)
            {
                ll num = (pp[n-1] * i + j) % MAX;
                graph[num].push_back(i);
            }
        }
        ll ans = 0;
        dfs(0);
        for (auto i : ss)
        {
            if (vis[i])
                ans += freq[i];
        }
        cout << ans << "\n";
    }
}