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
ll a[5005];
ll b[5005];
ll c[5005];
set<pl> graph[5005];
ll mx[5005];
ll n, m, k;
ll dp[5005][5005];
ll fun(ll ind, ll k)
{
    if (dp[ind][k] != -1)
        return dp[ind][k];
    if (ind >= n + 1)
        return dp[ind][k] = 0;
    if (k < a[ind])
        return dp[ind][k] = -mod;
    ll ans = fun(ind + 1, k + b[ind]);
    ll x = graph[ind].size();
    auto p = graph[ind].end();
    ll count = 0;
    ll cc = 0;
    while (x--)
    {
        p = prev(p);
        count++;
        pl temp = *p;
        cc += temp.first;
        ans = max(ans, cc + fun(ind + 1, k + b[ind] - count));
    }
    return dp[ind][k] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f(0, 5005) fi(0, 5005) dp[i][j] = -1;
    cin >> n >> m >> k;
    f(1, n + 1) cin >> a[i] >> b[i] >> c[i];
    f(0, m)
    {
        ll u, v;
        cin >> u >> v;
        graph[u].insert({c[v], v});
        mx[v] = max(mx[v], u);
    }
    f(1,n+1){
        graph[i].insert({c[i],i});
        mx[i] = max(mx[i], i);
    }
    f(1, n + 1)
    {
        vector<pl> temp;
        for (auto j : graph[i])
        {
            if (mx[j.second] != i)
                temp.pb(j);
        }
        for (auto j : temp)
            graph[i].erase(j);
    }
    cout << ((fun(1, k)<0)?-1:fun(1,k));
    return 0;
}