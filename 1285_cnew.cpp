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
bool prime[1000006];
vll pp;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i < 1000006; i++)
    {
        if (prime[i] == 0)
        {
            pp.pb(i);
            for (int j = i; j < 1000006; j += i)
                prime[i] = 1;
        }
    }
    ll x;
    cin >> x;
    vll v;
    vll val;
    for (auto i : pp)
    {
        if (x % i == 0)
        {
            ll mul = 1;
            while (x % i == 0)
            {
                mul *= i;
                x /= i;
            }
            val.pb(mul);
        }
    }
    ll siz = val.size();
    ll ans = 1e18, a, b;
    f(0, (1ll << siz))
    {
        ll aa = 1, bb = 1;
        fi(0, siz)
        {
            if (i & (1 << j))
                aa *= val[j];
            else
                bb *= val[j];
        }
        ll aaa = max(aa, bb);
        if (aaa < ans)
        {
            ans = aaa;
            a = aa;
            b = bb;
        }
    }
    cout << a << " " << b;
}