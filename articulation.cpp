#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
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
ll dfs_low[100001];
ll dfs_num[100001];
void articulationPointAndBridge(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED)
        { // a tree edge
            dfs_parent[v.first] = u;
            if (u == dfsRoot)
                rootChildren++; // special case if u is a root
            articulationPointAndBridge(v.first);
            if (dfs_low[v.first] >= dfs_num[u]) // for articulation point
                articulation_vertex[u] = true;  // store this information first
            if (dfs_low[v.first] > dfs_num[u])  // for bridge
                printf(" Edge (%d, %d) is a bridge\n", u, v.first);
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); // update dfs_low[u]
        }
        else if (v.first != dfs_parent[u])                  // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]); // update dfs_low[u]
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}