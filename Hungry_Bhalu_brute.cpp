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
vll graph[300005];
unordered_map<ll, ll> vis;
unordered_map<ll,unordered_map<ll,ll>> edge;
ll x;
void dfs(ll u,ll h,ll e)
{
    // cout<<u<<" ";
    x = max(x,h);
    for(ll i=0;i<graph[u].size();i++)
    {
        ll v = graph[u][i];
        if((!vis[v])&&(edge[u][v]>e)){dfs(v,h+1,edge[u][v]);}
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m ,k;
    cin >> n >> m >> k;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        edge[u][v]=w;
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        dfs(i,0,0);
        ans = max(ans,x);
        vis.clear();
        // cout<<"\n";
    }
    // cout<<ans;
    if(ans>=k)cout<<"YES";
    else cout<<"NO";

    
}