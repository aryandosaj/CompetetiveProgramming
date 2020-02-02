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
ll arr[100005];
vll s;
ll rec(vll a, ll ind)
{
    vll a1, a2;
    ll num = (1ll << ind);
    ll f1 = 0, f2 = 0;
    for (auto i : a)
    {
        if (i & num)
        {
            f1 = 1;
            a1.pb(i);
        }
        else
            a2.pb(i);
    }
    for (auto i : a)
    {
        if ((i & num) == 0)
        {
            f2 = 1;
            break;
        }
    }
    if (ind == 0)
    {
        if (f1 == 0 || f2 == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    if (f1 == 0 || f2 == 0)
    {
        return rec(a, ind - 1);
    }
    else
    {
        return min(num + rec(a2, ind - 1), num + rec(a1, ind - 1));
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
    cin >> n;
    f(0, n)
    {
        cin >> arr[i];
        s.pb(arr[i]);
    }
    cout<<rec(s,31);
    
}