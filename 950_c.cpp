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
vll ans[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    set<ll> z;
    set<ll> o;
    f(0, s.length())
    {
        if (s[i] == '0')
            z.insert(i);
        else
            o.insert(i);
    }
    ll c = 0;
    ll num = 0;
    ll l = s.length();
    while (1)
    {
        if (z.size() == 0)
            break;
        vll temp;
        ll ind = *z.begin();
        temp.pb(ind);
        z.erase(ind);
        num++;
        while (1)
        {

            auto x = o.lower_bound(ind);
            if (x != o.end())
            {
                temp.pb(*x);
                num++;
                auto y = z.lower_bound(*x);
                o.erase(x);

                if (y == z.end())
                {
                    cout << "-1";
                    return 0;
                }
                else
                {
                    num++;
                    temp.pb(*y);
                    ind = *y;
                    z.erase(y);
                }
            }
            else
                break;
        }
        ans[c++] = temp;
    }
    if (num != l)
    {
        cout << "-1";
        return 0;
    }
    cout << c << "\n";
    f(0, c)
    {
        cout << ans[i].size() << " ";
        for (auto j : ans[i])
            cout << j+1 << " ";
        cout << "\n";
    }
}
