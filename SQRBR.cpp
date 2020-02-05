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
ll dp[50][50];
ll n;
ll seq[50];
ll rec(ll ind, ll x)
{
    // cout<<ind<<" "<<x<<"\n";
    if (dp[ind][x] != -1)
        return dp[ind][x];
    if (x < 0)
        return 0;
    if (ind > 2 * n + 1)
        return 0;
    if (x == 0 && ind == 2 * n + 1)
        return 1;
    if (seq[ind])
        return dp[ind][x] = rec(ind + 1, x + 1);
    return dp[ind][x] = rec(ind + 1, x + 1) + rec(ind + 1, x - 1);
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
        memset(dp, -1, sizeof(dp));
        memset(seq, 0, sizeof(seq));
        ll k;
        cin >> n >> k;
        f(0, k)
        {
            ll x;
            cin >> x;
            seq[x] = 1;
        }
        cout << rec(1, 0) << "\n";
    }
}