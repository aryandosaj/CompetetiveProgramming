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
pll graph[200005];
ll child[200005];
ll k;
void dfs(ll u, ll p)
{
    child[u] = 1;
    for (auto i : graph[u])
    {
        if (i.first != p)
        {
            dfs(i.first, u);
            child[u] += child[i.first];
        }
    }
}
ll dfsg(ll u, ll p)
{
    ll ans = 0;
    for (auto i : graph[u])
    {
        if (i.first != p)
        {
            if (child[i.first] & 1)
            {
                ans += i.second + dfsg(i.first, u);
            }
            else
            {
                ans += dfsg(i.first, u);
            }
        }
    }
    return ans;
}
ll find_c(ll u, ll p)
{
    for (auto i : graph[u])
    {
        if (i.first != p)
        {
            if (child[i.first] > k)
                return find_c(i.first, u);
        }
    }
    return u;
}
ll dfsb(ll u, ll p)
{
    ll ans = 0;
    for (auto i : graph[u])
    {
        if (i.first != p)
        {
            ans += child[i.first] * i.second + dfsb(i.first, u);
        }
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
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> k;
        f(0, 2 * k + 1) { child[i] = 0, graph[i].clear(); }
        f(0, 2 * k - 1)
        {
            ll a, b, t;
            cin >> a >> b >> t;
            graph[a].pb({b, t});
            graph[b].pb({a, t});
        }
        dfs(1, 0);
        ll g = dfsg(1, 0);
        ll c = find_c(1, 0);
        f(0, 2 * k + 1) child[i] = 0;
        dfs(c, 0);
        ll b = dfsb(c, 0);
        cout << g << " " << b << "\n";
    }
    return 0;
}