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
ll arr[200005];
ll a[200005];
ll ind[200005];
vll adj[200005];
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
    f(1, n + 1) a[i] = i, ind[i] = i;
    f(1, m + 1) a[i] = i, ind[i] = i;
    ll ans = 0;
    f(0, m)
    {

        cin >> arr[i];
        if (i)
        {
            adj[arr[i]].pb(arr[i - 1]), adj[arr[i - 1]].pb(arr[i]);
            ans += abs(a[arr[i]] - a[arr[i - 1]]);
        }
    }
    cout << ans << " ";
    f(2, n + 1)
    {
        // fi(1, m + 1) cout << a[j] << " ";
        // cout << "\n";
        ll a1 = a[1];
        ll a2 = a[i];
        ll ia1 = ind[a[1]];
        ll ia2 = ind[a[i]];
        swap(a[i], a[1]);
        ind[a[1]] = 1;
        ind[a[i]] = i;
        ll fa1 = i;
        ll fa2 = 1;
        // cout << a1 << " " << ia1 << " " << fa1 << "\n";
        // cout << a2 << " " << ia2 << " " << fa2 << "\n";
        for (auto j : adj[a1])
        {
            if (j == a1 || j == a2)
                continue;
            ll k = ind[j];
            ans = ans - abs(k - ia1) + abs(k - fa1);
        }
        for (auto j : adj[a2])
        {
            if (j == a1 || j == a2)
                continue;
            ll k = ind[j];
            ans = ans - abs(k - ia2) + abs(k - fa2);
        }
        cout << ans << " ";
    }

    return 0;
}