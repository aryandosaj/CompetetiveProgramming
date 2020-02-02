#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
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
ll arr[100005];
unordered_map<ll, ll> mp;
ll fact[100005];
ll ncr(ll n, ll r)
{
    return (((fact[n] * power(fact[r], mod - 2, mod)) % mod) * power(fact[n - r], mod - 2, mod)) % mod;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    f(1, 100005) fact[i] = (fact[i - 1] * i) % mod;
    ll t;
    cin >> t;
    while (t--)
    {
        mp.clear();
        ll n, s = 0;
        cin >> n;
        f(0, n)
        {
            cin >> arr[i];
            s += arr[i];
            mp[arr[i]]++;
        }
        ll c = 0;
        ll ans = 1;
        ll cnt = 1;
        if (n == 1)
        {
            cout << "1\n";
            continue;
        }
        while ((s & 1) == 0)
        {
            cnt *= 2;
            ll num = s / 2;
            ll f = mp[num];
            c += f;
            if (cnt > 100000)
                break;
            ans = (ans * ncr(cnt, f)) % mod;
            s /= 2;
            cnt -= f;
        }
        if (c != n)
        {
            cout << "0\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
    return 0;
}