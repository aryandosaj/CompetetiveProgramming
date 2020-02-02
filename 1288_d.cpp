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
ll arr[300005][9];
pl a[500];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    f(0, n)
    {
        fi(0, m) cin >> arr[i][j];
    }
    f(0, 1 << m)
        a[i] = {0, 0};
    f(0, n)
    {
        fi(0, 1 << m)
        {
            ll mn = MOD;
            fii(0, m)
            {
                if ((1 << k) & j)
                    mn = min(mn, arr[i][k]);
            }
            if (a[j].first < mn)
                a[j] = {mn, i};
        }
    }   
    
    ll ans = 0;
    pl ind;
    f(0, n)
    {
        fi(0, m)
        {
            ll x = 0;
            fii(0, m) if (arr[i][j] > arr[i][k])
                x = x | (1 << k);
            if (a[x].first >= arr[i][j])
            {
                if (ans < arr[i][j])
                    ans = arr[i][j], ind.first = i, ind.second = a[x].second;
            }
        }
    }
    cout << ind.first + 1 << " " << ind.second + 1;
}