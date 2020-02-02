#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
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
#define px second
#define py first

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
int compare(pl a, pl b)
{
    return a.px < b.px;
}
double closest_pair(pll pnts, int n)
{
    sort(pnts.begin(), pnts.end(), compare);
    double best = 1e17;
    set<pl> box;
    box.insert(pnts[0]);
    int left = 0;
    for (int i = 1; i < n; ++i)
    {
        while (left < i && pnts[i].px - pnts[left].px > best)
            box.erase(pnts[left++]);
        for (typeof(box.begin()) it = box.lower_bound(make_pair(pnts[i].py - best, pnts[i].px - best)); it != box.end() && pnts[i].py + best >= it->py; it++)
            best = min(best, sqrt(pow(pnts[i].py - it->py, 2.0) + pow(pnts[i].px - it->px, 2.0)));
        box.insert(pnts[i]);
    }
    return best;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
