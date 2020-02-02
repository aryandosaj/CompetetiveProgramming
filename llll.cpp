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

vll graph[100005];
vll dfs_path;
unordered_map<ll, ll> vis;
unordered_map<ll, ll> h;
unordered_map<ll, ll> lev;
unordered_map<ll, ll> mp;
unordered_map<ll, ll> child;
unordered_map<ll, ll> parent;
ll tree[200002];
ll heavy[100005];
ll head[100005];
ll pos[100005];
ll arr[100005];
ll cp = 0;

void make_tree(ll low, ll high, ll pos)
{
    if (low == high)
    {
        tree[pos] = arr[low];
        return;
    }
    ll mid = (low + high) / 2;
    make_tree(low, mid, 2 * pos + 1);
    make_tree(mid + 1, high, 2 * pos + 2);
    tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
    return;
}
ll rangeminquery(ll qlow, ll qhigh, ll low, ll high, ll pos)
{
    if ((qlow <= low) && (qhigh >= high)) //comleteOverlap
    {
        return tree[pos];
    }
    if ((qlow > high) || (qhigh < low)) //no overlap
    {
        return MAX;
    }
    ll mid = (high + low) / 2;
    return max(rangeminquery(qlow, qhigh, low, mid, 2 * pos + 1), rangeminquery(qlow, qhigh, mid + 1, high, 2 * pos + 2));
}
ll query(ll a, ll b)
{
    ll ans = 0;
    while (head[a] != head[b])
    {
        if (lev[head[a]] > lev[head[b]])
        {
            swap(a, b);
        }
        ans = max(ans, rangeminquery(pos[head[b]], pos[b], 0, dfs_path.size() - 1, 0));
    }
    if (lev[a] > lev[b])
    {
        swap(a, b);
    }
    ans = max(ans,rangeminquery(pos[a],pos[b],0,dfs_path.size()-1,0));
    return ans;
}
void dfs(ll u)
{
    vis[u] = 1;
    child[u]++;
    ll ms = 0;
    ll mc = 0;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!vis[v])
        {
            parent[v] = u;
            lev[v] = lev[u] + 1;
            dfs(v);
            child[u] += child[v];
            if (child[v] > ms)
            {
                ms = child[v];
                mc = v;
            }
        }
    }
    heavy[u] = mc;
}
void decompose(ll u, ll p)
{
    vis[u] = 1;
    head[u] = p;
    pos[u] = cp++;
    dfs_path.push_back(arr[u]);
    if (heavy != 0)
    {
        decompose(heavy[u], p);
    }
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if ((!vis[v]) && (v != heavy[u]))
        {
            decompose(v, v);
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
    }
    for (ll i = 0; i < n; i++)
        cin >> arr[i + 1];
    lev[1] = 1;
    h[1] = cp++;
    dfs(1);
    make_tree(0, dfs_path.size() - 1, 0);
    cp = 0;
    vis.clear();
    decompose(0, 0);

    ll q;
    cin >> q;
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        ll w = query(a,b);
        cout << w << "\n";
    }
}