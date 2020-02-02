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
ll invMOD(ll x, ll m)
{
    return power(x, m - 2, m);
}
#define N 100005
vll graph[N];
ll dfs(ll u, ll p)
{
    ll ans = 1;
    ll c = 0;
    for (auto i : graph[u])
    {
        if (i != p)
            c++;
    }
    for (auto i : graph[u])
    {
        if (i != p)
        {
            ans = (ans + 1 + dfs(i, u)) % MOD;
        }
    }
    return (ans * invMOD(c + 1, MOD)) % MOD;
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
    f(1, n + 1)
            cout
        << dfs(i, 0) << " ";
}