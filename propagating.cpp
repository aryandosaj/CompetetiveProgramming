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
vll graph[200005];
ll num[200005];
unordered_map<ll, ll> vis;
unordered_map<ll, ll> oe;
unordered_map<ll, ll> out;
unordered_map<ll, ll> in;
ll arr1[2000000];
ll arr2[2000000];
ll ce = 1, co = 1,c=1;
ll query(ll i)
{
    ll res = 0;
    for (i; i > 0; i -= i & (-i))
        res += arr1[i];
    return res;
}
void update(ll i, ll val)
{
    for (i; i < 2000000; i += (i & (-i)))
        arr1[i] += val;
}
ll query2(ll i)
{
    ll res = 0;
    for (i; i > 0; i -= i & (-i))
        res += arr2[i];
    return res;
}
void update2(ll i, ll val)
{
    for (i; i < 2000000; i += (i & (-i)))
        arr2[i] += val;
}
void dfs(ll u, ll d)
{
    vis[u] = 1;
    in[u]=c++;
    if (d & 1)
    {
        oe[u] = 1;
        // update(co, num[u]);
        // in[u] = co++;
    }
    else
    {
        oe[u] = 0;
        // update2(ce, num[u]);
        // in[u] = ce++;
    }

    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!vis[v])
        {
            dfs(v, d + 1);
        }
    }
    out[u]=c++;
    // if (d & 1)
    // {
    //     // update(co + 1, -num[u]);
    //     out[u] = co++;
    // }
    // else
    // {
    //     // update(ce + 1, -num[u]);
    //     out[u] = ce++;
    // }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,0);
    while (m--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x, val;
            cin >> x >> val;
            if (oe[x])
            {
                update(in[x], val);
                update(out[x] + 1, -val);
                update2(in[x], -val);
                update2(out[x] + 1, val);
            }
            else
            {
                update(in[x], -val);
                update(out[x] + 1, +val);
                update2(in[x], val);
                update2(out[x] + 1, -val);
            }
        }
        else
        {
            ll x;
            cin>>x;
            if(oe[x])
            cout<<query(in[x])+num[x]<<"\n";
            else
            cout<<query2(in[x])+num[x]<<"\n";
                
            
            
        }
        
    }
}