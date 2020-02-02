#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 9223372036854775807
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
ll arr[1000006];
ll a[1000006];
ll n, sum;

ll fun(ll x)
{
    f(0, n) a[i] = arr[i] % x;
    ll st = 0, s = 0, l = 0, r = 0, ans = 0;
    f(0, n)
    {
        s += a[i];
        if (s >= x)
        {
            ll temp = s - x;
            a[i] -= temp;
            s = x;
            l = 0;
            r = x - a[st];
            ll c = 0, cost = 0, cc = mod;
            fi(st, i + 1)
            {
                cost += c * a[j];
                c++;
            }

            cc = cost;
            fi(st + 1, i + 1)
            {

                l += a[j - 1];
                cost = cost + l - r;
                cc = min(cc, cost);
                r -= a[j];
            }
            a[i] = temp;
            st = i;
            s = temp;
            ans += cc;
        }
    }
    return ans;
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
    f(0, n) cin >> arr[i], sum += arr[i];
    vll v;  
    if ((sum & 1) == 0)
        v.push_back(2);
    while (sum % 2 == 0)
        sum /= 2;
    for (ll i = 3; i * i <= sum; i += 2)
    {
        if (sum % i == 0)
            v.push_back(i);
        while (sum % i == 0)
            sum /= i;
    }
    if (sum > 1)
        v.pb(sum);
    ll ans = mod;
    for (auto i : v)
    {
        ans = min(ans, fun(i));
    }
    if (ans == mod)
        ans = -1;
    cout << ans;

    return 0;
}