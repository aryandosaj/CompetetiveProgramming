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
ll f[4];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a, b;
    cin >> a >> b;

    f(0, n)
    {
        ll x, y;
        cin >> x >> y;
        if (y >= b + 1)
            f[0]++;
        if (x <= a - 1)
            f[1]++;
        if (x >= a + 1)
            f[2]++;
        if (y <= b - 1)
            f[3]++;
    }
    ll x = max(f[0], max(f[1], max(f[2], f[3])));
    cout << x << "\n";
    f(0, 4)
    {
        if (x == f[i])
        {
            // cout<<i<<"\n";
            if (i == 0)
                cout << a << " " << b + 1 << "\n";
            else if (i == 1)
                cout << a - 1 << " " << b << "\n";
            else if (i == 2)
                cout << a + 1 << " " << b << "\n";
            else
                cout << a << " " << b - 1 << "\n";
            break;
        }
    }
    return 0;
}