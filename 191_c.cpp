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
struct dty
{
    ll v, i;
};

vll dfs_path;
vll lev_path;
vll graph[100005];
unordered_map<ll, ll> vis;
unordered_map<ll, ll> h;
unordered_map<ll, ll> lev;
unordered_map<ll, ll> mp;
unordered_map<ll, ll> parent;
unordered_map<ll,unordered_map<ll, ll>> fool;
unordered_map<ll,unordered_map<ll, ll>> ans;

dty tree[1000005];
ll cp = 0;
vector<dty> edges;

void make_tree(ll low, ll high, ll pos)
{
    if (low == high)
    {
        tree[pos].v = lev_path[low];
        tree[pos].i = low;
        return;
    }
    ll mid = (low + high) / 2;
    make_tree(low, mid, 2 * pos + 1);
    make_tree(mid + 1, high, 2 * pos + 2);
    if (tree[2 * pos + 1].v > tree[2 * pos + 2].v)
        tree[pos] = tree[2 * pos + 2];
    else
        tree[pos] = tree[2 * pos + 1];

    return;
}
dty rangeminquery(ll qlow, ll qhigh, ll low, ll high, ll pos)
{
    if ((qlow <= low) && (qhigh >= high)) //comleteOverlap
    {
        return tree[pos];
    }
    if ((qlow > high) || (qhigh < low)) //no overlap
    {
        return {MAX, MAX};
    }
    ll mid = (high + low) / 2;
    dty t1 = rangeminquery(qlow, qhigh, low, mid, 2 * pos + 1);
    dty t2 = rangeminquery(qlow, qhigh, mid + 1, high, 2 * pos + 2);
    if (t1.v < t2.v)
        return t1;
    else
        return t2;
}
void dfs(ll u)
{

    vis[u] = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!vis[v])
        {
            parent[v] = u;
            h[v] = cp++;
            dfs_path.push_back(v);
            lev[v] = lev[u] + 1;
            lev_path.push_back(lev[v]);
            dfs(v);
            dfs_path.push_back(u);
            lev_path.push_back(lev[u]);
            cp++;
        }
    }
}
void fun(ll u, ll p)
{
    ans[u][p] = fool[u][p];
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (v != p)
        {
            fun(v, u);
            ans[u][p] += ans[v][u];
        }
    }
    // cout<<u<<" "<<p<<" "<<ans[u][p]<<"\n";
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        dty temp;temp.i = u;
        temp.v = v;
        edges.push_back(temp);
    }
    dfs_path.push_back(1);
    lev_path.push_back(1);
    lev[1] = 1;
    h[1] = cp++;
    parent[1] = 0;
    dfs(1);
    make_tree(0, lev_path.size() - 1, 0);

    ll q;
    cin >> q;
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        if(h[a]>h[b])swap(a,b);
        dty w = rangeminquery(h[a], h[b], 0, lev_path.size() - 1, 0);
        ll par = dfs_path[w.i];
        // cout<<par<<"\n"<<w.i<<"\n";
        // cout<<a<<" "<<parent[a]<<"\n";
        // cout<<b<<" "<<parent[b]<<"\n";
        fool[a][parent[a]]++;
        fool[parent[a]][a]++;
        fool[parent[b]][b]++;
        fool[b][parent[b]]++;
        fool[par][parent[par]] -= 2;
        fool[parent[par]][par] -= 2;
    }
    fun(1,0);
    for(auto i:edges)
    cout<<max(ans[i.i][i.v],ans[i.v][i.i])<<" ";
}