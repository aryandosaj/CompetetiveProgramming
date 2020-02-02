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
ll n, m;
ll dp[100005];
ll a[100005];
pll arr;
ll fun(ll x)
{
    if (dp[x] != -1)
        return dp[x];
    if (x == m)
        return dp[x] = 0;
    if (a[x + 1])
        return dp[x] = fun(x + 1);
    ll ans = m-x;
    f(0, n)
    {
        if (x < arr[i].first)
        {
            ll tp = arr[i].first - x - 1;
            ans = min(ans, tp + fun(min(m, arr[i].second + tp)));
        }
    }
    return dp[x] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    f(0, 100005) dp[i] = -1;
    f(0, n)
    {
        pl temp;
        cin >> temp.first >> temp.second;
        fi(max(1ll, temp.first - temp.second), min(m+1, temp.first + temp.second + 1)) a[j] = 1;
        arr.push_back({temp.first - temp.second, temp.first + temp.second});
    }
    // sort(arr.begin(), arr.end(), greater<pl>());
    cout<<fun(0);

    return 0;
}