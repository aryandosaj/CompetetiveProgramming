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
vll graph[400005];
unordered_map<ll, ll> vis;
unordered_map<ll, ll> h;
unordered_map<ll, ll> lev;
unordered_map<ll, ll> mp;
unordered_map<ll, ll> parent;
unordered_map<ll, ll> child;
ll po[400005];
unordered_map<ll,dty> tree;
ll cp = 0;

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
    child[u]++;
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
            child[u]+=child[v];
            dfs_path.push_back(u);
            lev_path.push_back(lev[u]);
            cp++;
        }
    }
}

vll dfs_path1;
vll lev_path1;
vll graph1[400005];
unordered_map<ll, ll> vis1;
unordered_map<ll, ll> h1;
unordered_map<ll, ll> lev1;
unordered_map<ll, ll> mp1;
unordered_map<ll, ll> child1;
// dty tree1[5000005];
unordered_map<ll,dty> tree1;

ll cp1 = 0;
unordered_map<ll, ll> parent1;
ll po1[400005];
void make_tree1(ll low, ll high, ll pos)
{
    if (low == high)
    {
        tree1[pos].v = lev_path1[low];
        tree1[pos].i = low;
        return;
    }
    ll mid = (low + high) / 2;
    // cout<<pos<<" ";
    make_tree1(low, mid, 2 * pos + 1);
    make_tree1(mid + 1, high, 2 * pos + 2);

    if (tree1[2 * pos + 1].v > tree1[2 * pos + 2].v)
        tree1[pos] = tree1[2 * pos + 2];
    else
        tree1[pos] = tree1[2 * pos + 1];

    return;
}
dty rangeminquery1(ll qlow, ll qhigh, ll low, ll high, ll pos)
{
    if ((qlow <= low) && (qhigh >= high)) //comleteOverlap
    {
        return tree1[pos];
    }
    if ((qlow > high) || (qhigh < low)) //no overlap
    {
        return {MAX, MAX};
    }
    ll mid = (high + low) / 2;
    dty t1 = rangeminquery1(qlow, qhigh, low, mid, 2 * pos + 1);
    dty t2 = rangeminquery1(qlow, qhigh, mid + 1, high, 2 * pos + 2);
    if (t1.v < t2.v)
        return t1;
    else
        return t2;
}
void dfs1(ll u)
{
    vis1[u] = 1;
    child1[u]++;
    for (ll i = 0; i < graph1[u].size(); i++)
    {
        ll v = graph1[u][i];
        if (!vis1[v])
        {
            parent1[v] = u;
            h1[v] = cp1++;
            dfs_path1.push_back(v);
            lev1[v] = lev1[u] + 1;
            lev_path1.push_back(lev1[v]);
            dfs1(v);
            child1[u]+=child1[v];
            dfs_path1.push_back(u);
            lev_path1.push_back(lev1[u]);
            cp1++;
        }
    }
}
ll spo[400005];
ll spo1[400005];
void ans_dfs(ll u)
{
    vis[u] = 1;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!vis[v])
        {
            spo[v] += spo[u];
            ans_dfs(v);
            po[u] += po[v];
        }
    }
}
void ans_dfs1(ll u)
{
    vis1[u] = 1;
    for (ll i = 0; i < graph1[u].size(); i++)
    {
        ll v = graph1[u][i];
        if (!vis1[v])
        {
            spo1[v] += spo1[u];
            ans_dfs1(v);
            po1[u] += po1[v];
        }
    }
}
ll tp = 0;
ll tp1 = 0;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph1[v].push_back(u);
        graph1[u].push_back(v);
    }
    parent[1] = 0;
    parent1[1] = 0;
    dfs_path.push_back(1);
    lev_path.push_back(1);
    lev[1] = 1;
    h[1] = cp++;
    dfs_path1.push_back(1);
    lev_path1.push_back(1);
    lev1[1] = 1;
    h1[1] = cp1++;
    dfs(1);
    dfs1(1);

    make_tree(0, dfs_path.size() - 1, 0);
    make_tree1(0, dfs_path1.size() - 1, 0);

    while (q--)
    {
        ll t, a, b, pp;
        cin >> t;
        if (t == 1)
        {
            cin >> a >> b >> pp;
            if (tp <= tp1)
            {

                dty w = rangeminquery(h[a], h[b], 0, lev_path.size() - 1, 0);
                po[a] += pp;
                po[b] += pp;
                po[parent[dfs_path[w.i]]] -= pp;
                po[dfs_path[w.i]] -= pp;
                tp += (lev[a] - w.v + 1) * pp + (lev[b] - w.v) * pp;
            }
            else
            {
                dty w1 = rangeminquery1(h1[a], h1[b], 0, lev_path1.size() - 1, 0);
                po1[a] += pp;
                po1[b] += pp;
                po1[parent1[dfs_path1[w1.i]]] -= pp;
                po1[dfs_path1[w1.i]] -= pp;
                tp1 += (lev1[a] - w1.v + 1) * pp + (lev1[b] - w1.v) * pp;
            }
        }
        else
        {
            cin >> a >> b;
            if (tp <= tp1)
            {
                spo[a] += b;
                tp+=b*child[a];
            }
            else
            {
                spo1[a] += b;
                tp1+=b*child1[a];
            }
        }
    }
    vis.clear();
    vis1.clear();
    ans_dfs1(1);
    ans_dfs(1);
    ll am = 0, am1 = 0;
    for (ll i = 0; i < 100005; i++)
    {
        po[i] += spo[i];
        po1[i] += spo1[i];
        am = max(am, po[i]);
        am1 = max(am1, po1[i]);
    }
    if (am >= am1)
    {
        cout << "noobda " << am;
    }
    else
    {
        cout << "pros " << am1;
    }
    // cout << am << " " << am1;
}