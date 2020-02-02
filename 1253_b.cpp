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
    set<ll> s;
    set<ll> vis;
    ll f = 0;
    ll c = 0;
    vll ans;
    f(0, n)
    {
        c++;
        cin >> arr[i];
        if (arr[i] > 0)
        {
            if ((vis.find(arr[i]) != vis.end()) || (s.find(arr[i]) != s.end()))
            {
                f = 1;
                break;
            }
            else
            {
                s.insert(arr[i]);
                vis.insert(arr[i]);
            }
        }
        else
        {
            ll x = -1 * arr[i];
            if (s.find(x) == s.end())
            {
                f = 1;
                break;
            }
            s.erase(x);
        }
        if (s.empty())
        {
            ans.pb(c);
            c = 0;
            vis.clear();
        }
    }
    if (f || (s.size() > 0))
        cout << "-1";
    else
    {

        cout << ans.size() << "\n";
        for (auto i : ans)
            cout << i << " ";
        return 0;
    }
}