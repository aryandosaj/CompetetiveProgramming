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
#define deb(x) cout << #x << x << endl;
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
ll a[200005];
vector<pair<ll, pair<ll, ll>>> v;
ll arr[200005];
ll m, n, k, t;
bool fun(ll x)
{
    ll danger = a[x];
    f(0, 200005) arr[i] = 0;
    for (auto i : v)
    {
        if (i.first > danger)
        {
            arr[i.second.first]++;
            arr[i.second.second + 1]--;
        }
    }
    f(1, 200005) arr[i] += arr[i - 1];
    ll f = 0, c = 0;
    f(0, 200005)
    {
        if (arr[i])
            c++;
    }
    c *= 2;
    c += n + 1;
    return c <= t;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> k >> t;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(a, a + m);
    for (int i = 0; i < k; i++)
    {
        ll l, r, d;
        cin >> l >> r >> d;
        v.push_back({d, {l, r}});
    }
    sort(v.begin(), v.end());
    ll l = 0, r = m, ans = m;
    while (l <= r)
    {
        ll mid = (l + r) / 2;

        if (fun(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout<<m-ans;    
}