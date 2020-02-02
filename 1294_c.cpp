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
        ll n, num;
        cin >> n;
        num = n;
        map<ll, ll> mp;
        vll v;
        if (n % 2 == 0)
        {
            while (n % 2 == 0)
            {
                n /= 2;
                v.pb(2);
            }
        }
        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                while (n % i == 0)
                {
                    n /= i;
                    v.pb(i);
                }
            }
        }
        if (n > 1)
            v.pb(n);
        if (v.size() < 3)
        {
            cout << "NO\n";
        }
        else
        {
            ll a = v[0], b = v[1], c = 1;
            int start = 2;
            if (a == b)
            {
                b *= v[2];
                start++;
            }
            c = num / (a * b);
            if (c == a || c == b || c == 1)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n"
                     << a << " " << b << " " << c << "\n";
            }
        }
    }
}