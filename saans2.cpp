#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#include <bits/stdc++.h>
vector<int> adj[100005];
map<int, int> vis;
map<pair<int, int>, int> edge;
int ans;
void dfs(int u)
{
    vis[u] = 1;
    cout<<u<<"\n";
    for (int i = 0; i < adj[u].size(); i++)
    {

        for (int j = i + 1; j < adj[u].size(); j++)
        {
            if (edge.find({adj[u][i], adj[u][j]}) != edge.end())
            {
                cout<<"here";
                int a = adj[u].size() + adj[adj[u][i]].size() + adj[adj[u][j]].size() - 6;
                ans = min(ans, a);
            }
        }
    }
    for (auto i : adj[u])
    {
        if (vis[i] == 0)
            dfs(i);
    }
}

int bestTrio(int n, vector<int> u, vector<int> v)
{
    ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        edge[{u[i], v[i]}] = 1;
        edge[{v[i], u[i]}] = 1;
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<int> u, v;
    f(0, n)
    {
        ll x;
        cin >> x;
        u.pb(x);
    }
    f(0, n)
    {
        ll x;
        cin >> x;
        v.pb(x);
    }
    cout << bestTrio(n, u, v);
}
