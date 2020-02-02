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
ll arr[3][100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    ll x = 0;
    while (q--)
    {
        ll r, c;
        cin >> r >> c;
        if (arr[r][c] == 0)
        {
            arr[r][c] = 1;
            if (r == 1)
            {
                ll c1 = c - 1, c2 = c, c3 = c + 1;
                if (c1 > 0)
                    if (arr[2][c1] == 1)
                        x++;
                if (arr[2][c2] == 1)
                    x++;
                if (c3 <= n)
                    if (arr[2][c3] == 1)
                        x++;
            }
            else
            {
                ll c1 = c - 1, c2 = c, c3 = c + 1;
                if (c1 > 0)
                    if (arr[1][c1] == 1)
                        x++;
                if (arr[1][c2] == 1)
                    x++;
                if (c3 <= n)
                    if (arr[1][c3] == 1)
                        x++;
            }
        }
        else
        {
            arr[r][c] = 0;
            if (r == 1)
            {
                ll c1 = c - 1, c2 = c, c3 = c + 1;
                if (c1 > 0)
                    if (arr[2][c1] == 1)
                        x--;
                if (arr[2][c2] == 1)
                    x--;
                if (c3 <= n)
                    if (arr[2][c3] == 1)
                        x--;
            }
            else
            {
                ll c1 = c - 1, c2 = c, c3 = c + 1;
                if (c1 > 0)
                    if (arr[1][c1] == 1)
                        x--;
                if (arr[1][c2] == 1)
                    x--;
                if (c3 <= n)
                    if (arr[1][c3] == 1)
                        x--;
            }
        }
        if (x)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}