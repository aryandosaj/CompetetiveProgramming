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
ll arr[300005];
ll n;
ll rec(ll ind, ll a1, ll d1, ll a2, ll d2)
{
    if (ind == n)
        {
            cout<<"Yes";
            exit(0);
        }
    if (a1 == MOD && a2 == MOD)
    {
        return rec(ind + 1, arr[ind], d1, a2, d2);
    }
    else if (a2 == MOD)
    {
        bool ans = rec(ind + 1, a1, d1, arr[ind], d2);
        if (d1 == MOD)
        {
            ans = ans | rec(ind + 1, arr[ind], arr[ind] - a1, a2, d2);
        }
        else if (arr[ind] - a1 == d1)
        {
            ans = ans | rec(ind + 1, arr[ind], d1, a2, d2);
        }
        return ans;
    }
    else
    {
        ll ans = 0;
        if (d1 == MOD)
            ans = ans | rec(ind + 1, arr[ind], arr[ind] - a1, a2, d2);
        else if (arr[ind] - a1 == d1)
            ans = ans | rec(ind + 1, arr[ind], d1, a2, d2);
        if (d2 == MOD)
            ans = ans | rec(ind + 1, a1, d1, arr[ind], arr[ind] - a2);
        else if (arr[ind] - a2 == d2)
            ans = ans | rec(ind + 1, a1, d1, arr[ind], d2);
        return ans;
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
    cin >> n;
    f(0, n)
    {
        cin >> arr[i];
    }
    rec(0, MOD, MOD, MOD, MOD);
   
        cout << "No";
}