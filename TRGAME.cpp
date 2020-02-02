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
vll graph[100005];
ll ans[100005];
ll mx[100005];
ll n;
void init(ll n)
{
    f(0, n + 1)
    {
        graph[i].clear();
        ans[i] = 0;
        mx[i] = 0;
    }
    return;
}
ll dfs(ll u, ll p)
{
    ll t = 1;
    for (auto i : graph[u])
    {
        if (i != p)
        {
            ll x = dfs(i, u);
            t += x;
            mx[u] = max(mx[u], x);
        }
    }
    if (n - t)
        mx[u] = max(mx[u], n - t);
    return t;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        init(n);
        ll start = 1;
        f(0, n - 1)
        {
            ll u, v;
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        f(1, n + 1) if (graph[i].size() == 1)
        {
            start = i;
            break;
        }
        dfs(start, 0);
        ll x;
        x = n / 2;
        f(1, n + 1)
        {
            if (n & 1)
            {
                ans[i] = 0;
                continue;
            }
            if (mx[i] > x)
            {
                ans[i] = 0;
            }
            else
            {

                ans[i] = 1;
            }
        }
        f(1, n + 1) cout << ans[i];
        cout << "\n";
    }
    return 0;
}