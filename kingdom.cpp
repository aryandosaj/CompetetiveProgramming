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
ll arr[45];
string a[3];

char rec(ll num, ll j)
{
    if (j <= 2)
        return a[j][num - 1];

    if (arr[j - 2] >= num)
        return rec(num, j - 2);
    else
    {
        num -= arr[j - 2];
        if (num > arr[j - 1])
            num -= arr[j - 1];
        return rec(num, j - 1);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll k;
    cin >> n >> a[1] >> a[2] >> k;
    ll aa = a[1].length();
    ll bb = a[2].length();
    arr[1] = aa;
    arr[2] = bb;
    ll cc = 0;
    ll j = 3;
    for (ll j = 3; j <= n+1; j++)
    {
        cc = aa + bb + bb;
        arr[j] = cc;
        aa = bb;
        bb = cc;
    }
    if (k <= arr[n])
        cout << rec(k, n);
    else
        cout << "-1";
}