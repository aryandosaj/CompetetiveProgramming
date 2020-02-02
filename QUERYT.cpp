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
ll g[205][205];
vll adj[40004];
ll val[40004];
ll dp[40004][205];
ll l;
ll tin[40004];
ll tout[40004];
ll tim;
ll up[100005][30];
void dfs1(ll u, ll p, ll x, ll va)
{
    if (g[val[u]][x] > 1)
        va++;
    dp[u][x] = va;
    for (auto i : adj[u])
    {
        if (i != p)
            dfs1(i, u, x, va);
    }
}

void dfs(ll u, ll p)
{
    tim++;
    tin[u] = tim;
    up[u][0] = p;
    for (ll i = 1; i <= l; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (ll i = 0; i < adj[u].size(); i++)
    {
        ll v = adj[u][i];
        if (v != p)
            dfs(v, u);
    }
    tout[u] = ++tim;
}
bool is_ancestor(ll u, ll v)
{
    if ((tin[v] >= tin[u]) && (tout[u] >= tout[v]))
        return true;
    return false;
}
ll lca(ll u, ll v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; i--)
    {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
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
    l = 20;
    tim = 0;
    f(1, 205) fi(1, 205) g[i][j] = __gcd(i, j);
    f(1, n + 1) cin >> val[i];
    f(0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 1);
    f(1, 205) dfs1(1, 0, i, 0);
    ll q;
    cin >> q;
    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        ll lc = lca(u, v);
        ll x = val[lc];
        if (x == 1)
        {
            cout << "0\n";
            continue;
        }
        if (u == v)
        {
            cout << (val[u] != 1) << endl;
            continue;
        }
        ll ans = dp[u][x] + dp[v][x] - 2 * dp[lc][x] + 1;
        cout << ans << "\n";
    }
}