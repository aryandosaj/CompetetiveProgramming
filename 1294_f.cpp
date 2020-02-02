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
vll adj[200005];
ll a, b, c, cd;
vll path;
void dfs(ll u, ll p, ll d)
{
    if (d > cd)
    {
        cd = d;
        a = u;
    }
    for (auto i : adj[u])
    {
        if (i != p)
            dfs(i, u, d + 1);
    }
}
void dfs1(ll u, ll p, ll d)
{
    if (d > cd)
    {
        cd = d;
        b = u;
    }
    for (auto i : adj[u])
    {
        if (i != p)
            dfs1(i, u, d + 1);
    }
}
ll dfs2(ll u, ll p)
{
    ll z = 0;
    for (auto i : adj[u])
    {
        if (i != p)
            z = z | dfs2(i, u);
    }
    if (z)
        path.pb(u);
    if (u == a)
    {
        path.pb(u);
        return 1;
    }
    return z;
}
map<ll, ll> vis;
void dfs4(ll u, ll d)
{
    vis[u] = 1;
    if (d >= cd && u != a && u != b)
    {
        c = u;
        cd = d;
    }
    for (auto i : adj[u])
    {
        if (!vis[i])
            dfs4(i, d + 1);
    }
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
    f(0, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll ans = 0;
    dfs(1, 0, 1);
    cd = 0;
    dfs1(a, 0, 1);
    ans += cd;
    cd = 0;
    dfs2(b, 0);
    for (auto i : path)
        vis[i] = 1;
    for (auto i : path)
        dfs4(i, 0);
    ans += cd;
    cout << ans - 1 << "\n";
    cout << a << " " << b << " " << c;
}