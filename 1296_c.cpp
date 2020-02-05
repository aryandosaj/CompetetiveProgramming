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
void solve()
{
    ll n;
    string s;
    cin >> n;
    cin >> s;
    map<pl, vll> mp;
    ll x = 0, y = 0;
    pl ans;
    ll d = MOD;
    mp[{x, y}].pb(0);
    f(0, n)
    {
        if (s[i] == 'L')
            x--;
        if (s[i] == 'R')
            x++;
        if (s[i] == 'U')
            y++;
        if (s[i] == 'D')
            y--;

        mp[{x, y}].pb(i + 1);
    }

    for (auto i : mp)
    {
        if (i.second.size() > 1)
        {
            fi(1, i.second.size())
            {
                ll dif = i.second[j] - i.second[j - 1] - 1;
                if (dif < d)
                {
                    d = dif;
                    ans = {i.second.at(j - 1) + 1, i.second.at(j)};
                }
            }
        }
    }
    if (d != MOD)
        cout << ans.first << " " << ans.second << "\n";
    else
        cout << "-1\n";
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
        solve();
}