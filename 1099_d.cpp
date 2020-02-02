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
ll a[100005];
ll s[100005];
map<ll, ll> vis;
void dfs(ll u, ll d, ll dad)
{
    // cout<<u<< " ";
    vis[u] = 1;
    ll mm = MAX;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!vis[v])
        {
            if ((d & 1) == 0)
            {
                mm = min(mm, s[v]);
            }
        }
    }

    if ((d & 1) == 0)
    {
        if (mm == MAX)
        {
            a[u] = 0;
            s[u] = s[dad];
        }
        else
        {
            a[u] = mm - s[dad];
            s[u] = a[u] + s[dad];
        }
    }
    else
    {
        a[u] = s[u] - s[dad];
    }
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!vis[v])
        {
            dfs(v, d + 1, u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll x;
        cin >> x;
        graph[x].push_back(i + 2);
        graph[i + 2].push_back(x);
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i + 1];
    }
    a[1] = 1;
    a[0] = 0;
    s[0] = 0;
    ll ans = 0;
    dfs(1, 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        ans += a[i];
        if (a[i] < 0)
        {
            cout << "-1";
            return 0;
        }
    }
        cout << ans;
}