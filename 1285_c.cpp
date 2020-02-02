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
    ll ans = 1e18, a, b;
    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ll num2 = x / i;
            ll num1 = i;
            ll a1 = 1;
            ll a2 = 1;
            ll lcm = (num1 * num2) / __gcd(num1, num2);
            ll k = x / lcm;
            for (auto h : pp)
            {
                if (k == 1)
                    break;
                ll c1 = 0, c2 = 0;
                ll c = 0;
                ll mul = 1;
                while (k % h == 0)
                {
                    k /= h;
                    c++;
                    mul *= h;
                }
                while (num1 % h == 0)
                {
                    num1 /= h;
                    c1++;
                }
                while (num2 % h == 0)
                {
                    num2 /= h;
                    c2++;
                }
                if (c1 > c2)
                {
                    a1 = a1 * mul;
                }
                else
                {
                    a2 = a2 * mul;
                }
            }
            num1 = i * a1;
            num2 = (x / i) * a2;
            ll aaa = max(num1, num2);
            // cout << num1 << " " << num2 << "\n";
            if (aaa < ans)
            {
                ans = aaa;
                a = num1;
                b = num2;
            }
        }
    }
    cout << a << " " << b;
}