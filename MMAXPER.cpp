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
pl arr[1003];
ll dp[1003][2];
ll n;
ll rec(ll ind, ll k)
{
    if (ind == n + 1)
        return 0;
    if (dp[ind][k] != -1)
        return dp[ind][k];
    pl last = arr[ind - 1];
    ll ans = 0;
    if (ind == 1)
    {
        if (k == 0)
            ans = max(rec(ind + 1, 0) + arr[ind].second, rec(ind + 1, 1) + arr[ind].first);
        else
            ans = max(rec(ind + 1, 0) + arr[ind].second, rec(ind + 1, 1) + arr[ind].first);
    }
    else
    {
        if (k == 0)
            ans = max(rec(ind + 1, 0) + abs(arr[ind].first - last.first) + arr[ind].second, rec(ind + 1, 1) + abs(arr[ind].second - last.first) + arr[ind].first);
        else
            ans = max(rec(ind + 1, 0) + abs(arr[ind].first - last.second) + arr[ind].second, rec(ind + 1, 1) + abs(arr[ind].second - last.second) + arr[ind].first);
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
    cin >> n;
    memset(dp, -1, sizeof(dp));
    f(1, n + 1)
            cin >>
        arr[i].first >> arr[i].second;
    cout << max(rec(1, 0), rec(1, 1));
}