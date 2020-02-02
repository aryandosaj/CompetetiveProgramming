#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000007
ll val[100005];
vll graph[100005];
ll mm;
vll leaf;
ll k;
ll s;
unordered_map<ll, ll> child;
ll lc;
ll lcm(ll a, ll b)
{
    if (a == b)
        return a;
    return (a * b) / __gcd(a, b);
}
void dfs2(ll u, ll p)
{
    for (auto i : graph[u])
    {
        if (i != p)
        {
            dfs2(i, u);
            child[u]++;
        }
    }
}
void dfs(ll u, ll p, ll d)
{
    if (p > 0)
        d = d * child[p];
    lc = lcm(lc,d);
    if(d>s||d<0)
{        cout<<s;exit(0);}
    for (auto i : graph[u])
    {
        if (i != p)
            dfs(i, u, d);
    }
    if ((graph[u].size() == 1) && (u != 1))
        leaf.push_back(u),k=min(k,val[u]*d);
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll n;
    lc=1;
    k = 1000000000000000;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> val[i],s+=val[i];
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs2(1, 0);
    dfs(1, 0, 1);
    ll ans = s-k/lc*lc;
    cout << ans;
}