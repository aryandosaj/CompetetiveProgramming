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
pll a, b;
map<ll, ll> mp;
set<ll> v;
set<pl> sl;
set<pl> sr;
vll adjl[400005];
vll adjr[400005];
bool chk(pl p)
{
    if (sl.size() == 0)
        return 1;
    ll lmax = (*prev(sl.end())).first;
    ll rmin = (*sr.begin()).first;
    if (lmax > rmin)
        return 0;
    if (p.first > rmin || p.second < lmax)
        return 0;
    return 1;
}
bool solve(ll c)
{
    f(1, c + 1)
        adjl[i]
            .clear(),
        adjr[i].clear();
    sl.clear();
    sr.clear();
    f(0, a.size())
    {
        adjl[a[i].first].pb(i);
        adjr[a[i].second].pb(i);
    }
    f(1, c + 1)
    {
        for (auto j : adjl[i])
        {
            if (chk(b[j]))
            {
                sl.insert({b[j].first, j});
                sr.insert({b[j].second, j});
            }
            else
            {
                return 0;
            }
        }
        for (auto j : adjr[i])
        {
            sl.erase({b[j].first, j});
            sr.erase({b[j].second, j});
        }
    }
    return 1;
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
        ll sa, ea, sb, eb;
        cin >> sa >> ea >> sb >> eb;
        v.insert(sb);
        v.insert(ea);
        v.insert(sa);
        v.insert(eb);
        a.pb({sa, ea});
        b.pb({sb, eb});
    }
    ll c = 1;
    for (auto i : v)
        mp[i] = c++;
    f(0, a.size())
    {
        a[i] = {mp[a[i].first], mp[a[i].second]};
        b[i] = {mp[b[i].first], mp[b[i].second]};
    }
    ll ans = solve(c);
    if (ans == 1)
    {
        swap(a, b);
        if (solve(c))
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}