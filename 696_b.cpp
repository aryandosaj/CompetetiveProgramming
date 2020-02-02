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
vll graph[100005];
ll current_time = 0;
ld ans[100005];
ld start_time[100005];
void r_dfs(ll u, ll d)
{
    current_time++;
    start_time[u] = current_time;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v != d)
        {
            r_dfs(v, u);
        }
    }
}
void dfs(ll u, ll d)    

{
    ld p = 0;
    ld s = 0;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v != d)
            p += start_time[v], s++;
    }
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v != d)
            start_time[v] = p / s, dfs(v, u);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        ll x;
        cin >> x;
        graph[i+1].push_back(x);
        graph[x].push_back(i+1);
    }
    r_dfs(1, 0);
    dfs(1, 0);
    for (ll i = 1; i <= n; i++)
        cout << start_time[i] << " ";
}