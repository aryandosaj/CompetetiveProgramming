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
        ll n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        map<ll, ll> mp;
        ll b = 0;
        for (auto i : s)
        {
            if (i == '0')
                b++;
            else
                b--;
        }
        if (b == 0)
        {
            ll u = 0;
            ll f = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                    u++;
                else
                    u--;
                if (u == x)
                {
                    cout << "-1\n";
                    f = 1;
                    break;
                }
            }
            if (f == 0)
                cout << "0\n";
            continue;
        }
        ll ans = 0;
        if (x == 0)
            ans++;
        ll k = b;
        b = 0;
        for (auto i : s)
        {
            if (i == '0')
                b++;
            else
                b--;
            if (b == x)
                ans++;
            else
            {
                if (((x - b) * k) > 0)
                {
                    if (k < 0)
                    {
                        ll p = -k;
                        if (((b - x) % p) == 0)
                            ans++;
                    }
                    else
                    {
                        if (((x - b) % k) == 0)
                            ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}