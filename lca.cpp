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
dty tree[200002];
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
    ll ms = 0;
    ll mc = 0;
    for (ll i = 0; i < graph[u].size(); i++)
    {
        ll v = graph[u][i];
        if (!vis[v])
        {
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
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs_path.push_back(1);
    lev_path.push_back(1);
    lev[1] = 1;
    h[1] = cp++;
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
        cout << dfs_path[w.i] << "\n";
    }
}