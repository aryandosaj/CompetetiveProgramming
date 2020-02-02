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
ll c = 0, y = 0;
vll graph[100005];
ll bit[1000006];
ll val[100005];
void add(ll x,ll val)
{
    for (ll i = x; i < 1000006; i += (i & (-i)))
        bit[i] += val;
}
ll query(ll x)
{
    ll ans = 0;
    for (ll i = x; i >= 1; i -= (i & (-i)))
        ans += bit[i];
        return ans;
}
void dfs(ll u, ll dad)
{
    add(val[u],1);
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v != dad)
        {
            c += query(val[v]-1);
            // cout<<c<<"\n";
            dfs(v, u);
        }
    }
    add(val[u],-1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        c = 0;
        cin >> n;
        for (ll i = 0; i < 1000006; i++)
            bit[i] = 0;
        for (ll i = 0; i < 100005; i++)
            graph[i].clear(), val[i] = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> val[i + 1];
        }
        for (ll i = 0; i < n - 1; i++)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        

        dfs(1, 0);
        cout << c << "\n";
    }
}