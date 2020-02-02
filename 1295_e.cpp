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
ll p[200005];
ll a[200005];
ll ind[200005];
ll k[200005];
ll vis[200005];
ll n;
ll fun()
{
    f(0, 200005) vis[i] = 0, ind[i] = 0;
    ll c = 0;
    ll ans = 1e17;
    f(1, n)
    {
        if (vis[p[i]])
        {
            c -= a[i];
            ans = min(ans, c);
            continue;
        }
        else
        {
            if(p[i]>i)
            {
                c+=a[i];
            }
        }
        

    }
    // cout << ans << "\n";
    return ans;
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
    f(1, n + 1) cin >> p[i], k[i] = p[i];
    f(1, n + 1) cin >> a[i];
    ll ans = fun();
    cout << ans << "\n";

    reverse(p, p + n);
    reverse(k, k + n);
    reverse(a, a + n);
    ans = min(ans, fun());
    cout << ans << "\n";
}