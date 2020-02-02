#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define NUM 10004
#define L 19
int tim;
int tin[NUM];
int tout[NUM];
map<int, int> lev;
map<int, int> nodes;
int up[NUM][20];
vector<pair<int, int>> graph[NUM];
void dfs_lca(int u, int p)
{
    tin[u] = tim++;
    up[u][0] = p;
    for (int i = 1; i <= L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto i : graph[u])
    {
        int v = i.first;
        int w = i.second;
        if (v != p)
        {
            lev[v] = lev[u] + w;
            nodes[v] = nodes[u] + 1;
            dfs_lca(v, u);
        }
    }
    tout[u] = tim++;
}
bool is_ancestor(int u, int v)
{
    if (u * v == 0)
        return 1;
    return ((tin[u] <= tin[v]) && (tout[u] >= tout[v]));
}
int lca(int u, int v)
{

    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = L; i >= 0; i--)
    {
        if (!(is_ancestor(up[u][i], v)))
            u = up[u][i];
    }
    return up[u][0];
}
void init()
{
    tim = 0;
    lev.clear();
    nodes.clear();
    for (int i = 0; i < NUM; i++)
    {
        graph[i].clear();
        for (int j = 0; j <= L; j++)
            up[i][j] = 0;
    }
}
int dist(int u, int v)
{
    return lev[u] + lev[v] - 2 * lev[lca(u, v)];
}
int kth(int u, int v, int k)
{

    int l_c_a = lca(u, v);
    int l1 = nodes[u] - nodes[l_c_a] + 1;
    int l2 = nodes[v] - nodes[l_c_a] + 1;
    // cout << l1 << " " << l2 << " " << k << "\n";
    
    if (k <= l1)
    {
        k--;
        for (int i = L; i >= 0; i--)
            if ((1 << i) & k)
                u = up[u][i];
        return u;
    }
    else
    {
        k = (l1 + l2 - 1) - k;
        
        for (int i = L; i >= 0; i--)
            if ((1 << i) & k)
                v = up[v][i];
        return v;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        init();
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        dfs_lca(1, 0);
        // cout<<lca(4,6);
        // return 0;
        string s;
        int a, b, k;
        while (1)
        {

            cin >> s;
            if (s == "DONE")
            {
                cout << "\n";
                break;
            }
            else if (s == "DIST")
            {
                cin >> a >> b;
                cout << dist(a, b) << "\n";
            }
            else
            {
                cin >> a >> b >> k;
                cout << kth(a, b, k) << "\n";
            }
        }
    }
}