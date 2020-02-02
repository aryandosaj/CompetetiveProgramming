#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#define deb(x) cout << #x << "  " << x << endl;

//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
template <class T>
ostream &operator<<(ostream &os, vector<T> V)
{
    os << "[ ";
    for (auto v : V)
        os << v << " ";
    os << "]";
    return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S)
{
    os << "{ ";
    for (auto s : S)
        os << s << " ";
    return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
    return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M)
{
    os << "{ ";
    for (auto m : M)
        os << "(" << m.first << ":" << m.second << ") ";
    return os << "}";
}
vll graph[1000006];
ll ans, aa;
ll val[1000006];
ll node[1000006];
ll child[1000006];
ll parent[1000006];
ll burn[1000006];

pl dfs(ll u, ll p, ll k)
{
    parent[u] = p;
    ll c = graph[u].size() - 1;
    if (u == 1)
        c++;
    child[u] = c + k - 1;
    if (c)
        for (auto i : graph[u])
        {
            if (i != p)
            {
                pl temp = dfs(i, u, c + k - 1);
                if (val[u] < temp.first)
                {
                    val[u] = temp.first;
                    node[u] = temp.second;
                }
            }
        }
    else
    {
        val[u] = k;
        node[u] = u;
    }
    return {val[u], node[u]};
}
ll cdfs(ll u);
ll rdfs(ll u, ll p)
{
    // cout<<u<<" ";
    burn[u] = 1;
    for (auto i : graph[u])
    {
        if (i != p && burn[i] == 0)
        {
            if (i == parent[u])
                rdfs(i, u);
            else
                cdfs(i);
        }
    }
}
ll cdfs(ll u)
{
    // cout<<"\n";
    // deb(u);
    // deb(node[u]);
    ll x = val[u] - child[parent[u]];
    if (x >= 1)
    {
        ans += x - 1;
        aa = max(ans, aa);
    }
    if (node[u] != u)
        rdfs(node[u], 0);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ans = 1;
    aa = 1;
    f(0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, 0, 0);
    cdfs(1);
    // f(1, n + 1) cout << child[i] << " ";
    // cout << "\n";
    // f(1, n + 1) cout << val[i] << " ";
    // cout << "\n";

    // f(1, n + 1) cout << node[i] << " ";
    // cout << "\n";
    cout << aa;
    return 0;
}