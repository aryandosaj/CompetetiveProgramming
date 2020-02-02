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
ll dp[200005][3];
ll p[200005];
ll q[200005];
ll r[200005];
ll x[200005];
ll fun(ll n, ll pos)
{
    if (n == 0)
        return 0;
    if (dp[n][pos] != -1)
        return dp[n][pos];
    ll c = 0;
    if (x[n] != pos)
        c = 1;
    ll mm = fun(n - 1, pos);
    if (pos >= 1)
        mm = min(mm, fun(n - 1, pos - 1));
    if (pos == 2)
        mm = min(mm, fun(n - 1, pos - 2));
    return dp[n][pos] = c + mm;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f(0, 200005) fi(0, 3) dp[i][j] = -1;
    ll a, b, c;
    cin >> a >> b >> c;
    f(0, a) cin >> p[i], x[p[i]] = 0;
    f(0, b) cin >> q[i], x[q[i]] = 1;
    f(0, c) cin >> r[i], x[r[i]] = 2;
    sort(p, p + a);
    sort(q, q + b);
    sort(r, r + c);
    cout<<min(fun(a+b+c,0),min(fun(a+b+c,1),fun(a+b+c,2)));
}