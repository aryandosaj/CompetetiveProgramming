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
ll fact[1050];
ll power(ll a, ll b, ll m)
{
    ll c = 1;
    a = a % m;
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
ll ncr(ll n, ll r)
{
    return (((fact[n] * invmod(fact[r], MOD)) % MOD) * invmod(fact[n - r], MOD)) % MOD;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    fact[0] = 1;
    f(1, 1050) fact[i] = (i * fact[i - 1]) % MOD;
    ll ans = 0;
    ll pre = 0;
    ll mod = MOD;
    for (int i = 1; i <= n; i++)
    {
        ll x = (ncr(m + i - 1, m) - pre + 10 * mod) % MOD;
        pre = (pre + x) % MOD;
        ans = (ans + ((x * ncr(m + (n - i + 1) - 1, m)) % MOD)) % MOD;
    }
    cout << ans;
}