#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define vll vector<ll>
#define MAX 1000000007
vll adj[100005];
ll arr[100005];
ll dad[100005];
ll pp[100005];

ll n, l;
// vector<vector<ll>> adj;


ll timer;
vector<ll> tin, tout;
vector<vector<ll>> up;

void dfs(ll v, ll p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (ll i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (ll u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(ll u, ll v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (ll i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(ll root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<ll>(l + 1));
    dfs(root, root);
}
void dfs2(ll u, ll mm, ll p, ll o)
{

    if (arr[u] >= mm)
    {
        mm = arr[u];
        o = u;
    }
    dad[u] = o;
    for (ll i = 0; i < adj[u].size(); i++)
    {
        ll v = adj[u][i];
        if (v != p)
        {
            dfs2(v, mm, u, o);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;l = 22;
    for (ll i = 0; i < n; i++)
        cin >> arr[i + 1], dad[i + 1] = i + 1;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    n++;
    preprocess(1);
    dfs2(1,0,0,0);
    ll q;cin>>q;
    while(q--)
    {
        ll u,v;
        cin>>u>>v;
        cout<<dad[lca(u,v)]<<"\n";
    }
    
}
// struct comp{
//     bool operator()( dt const & a,dt const & b )
//     {
//         return a.x<b.x
//     }
// };