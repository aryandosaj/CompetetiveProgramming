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
//POWER
ll power(ll a, ll b, ll m)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= m;
        b /= 2;
        a *= a;
        a %= m;
    }
    return c;
}
ll invmod(ll x, ll m)
{
    return power(x, m - 2, m);
}
#define N 100005
vll graph[N];
ll ex[N];
ll val[N];
ll dfs1(ll u, ll p)
{
    ll ans = 1;
    ll c = 1;
    for (auto i : graph[u])
        if (i != p)
            c++;
    for (auto i : graph[u])
        if (i != p)
            ans = (ans + 1 + dfs1(i, u)) % MOD;
    return ex[u] = (ans * invmod(c, MOD)) % MOD;
}
void dfs(ll u, ll p, ll e)
{

    ll c = 1;
    ll sum = 1;
    for (auto i : graph[u])
        if (i != p)
            sum = (sum + 1 + ex[i]) % MOD, c++;
    if (u != 1)
        c++, sum = (sum + e + 1) % MOD;
    val[u] = (sum * invmod(c, MOD)) % MOD;
    for (auto i : graph[u])
        if (i != p)
        {
            ll v = (((sum - 1 - ex[i] + MOD + MOD) % MOD) * invmod(c - 1, MOD)) % MOD;
            dfs(i, u, v);
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
        ll u, v;
        cin >> u >> v;
        graph[u].pb(v); 
        graph[v].pb(u);
    }
    dfs1(1, 0);
    dfs(1, 0, 0);
    f(1, n + 1)
            cout
        << val[i] << " ";
    cout << "\n";
}