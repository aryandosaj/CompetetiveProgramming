//AC ho BSDK
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 5000000
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
ll arr[10004];
ll bit[10004][51];
void update(ll ind, ll val, int j)
{
    for (ll i = ind; i < 10004; i += i & -i)
        bit[i][j] = (bit[i][j] + val) % MOD;
    return;
}
ll query(ll ind, ll j)
{
    ll ret = 0;
    for (ll i = ind; i > 0; i -= i & -i)
        ret = (ret + bit[i][j]) % MOD;
    return ret;
}
ll temp[10004][51];
ll vis[10004];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<ll> s;
    map<ll, ll> mp;
    ll n, k;
    cin >> n >> k;
    f(0, n) cin >> arr[i], s.insert(arr[i]);
    ll c = 0;
    for (auto i : s)
        mp[i] = ++c;
    f(0, n) arr[i] = mp[arr[i]];
    ll ans = 0;

    f(0, n)
    {
        if (vis[arr[i]] == 0)
        {
            update(arr[i], 1, 1);
            vis[arr[i]] = 1;
        }
        fi(2, k + 1)
        {
            ll val = query(arr[i] - 1, j - 1);
            ll x = (val - temp[arr[i]][j] + MOD + MOD) % MOD;
            update(arr[i], x, j);
            temp[arr[i]][j] = val;
        }
    }
    ans = query(10003, k);

    cout << ans;
}