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
ll mo = 0, me = 0;
void dfs(ll u, ll p)
{
    ll m1o = 0, m2o = 0;
    ll m1e = 0, m2e = 0;
    if (arr[u] & 1)
        odd[u]++;
    else
        even[u]++;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v != p)
        {
            dfs(v, u);
            if (arr[v] & 1)
            {
                if (odd[v] > m1o)
                {
                    m2o = m1o;
                    m1o = odd[v];
                }
                else if (odd[v] > m2o)
                {
                    m2o = odd[v];
                }
            }
            else
            {
                if (even[v] > m1e)
                {
                    m2e = m1e;
                    m1e = even[v];
                }
                else if (even[v] > m2e)
                {
                    m2e = even[v];
                }
            }
        }
    }
    if (arr[u] & 1)
    {
        odd[u] += m1o + m2o;
        mo = max(mo, odd[u]);
    }
    else
    {
        even[u] += m1e + m2e;
        me = max(me, even[u]);
    }
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
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    cout << me << " " << mo;
}