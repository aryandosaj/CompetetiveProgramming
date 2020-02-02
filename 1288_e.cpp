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
ll bit[600005];
void update(ll x, ll val)
{
    for (ll i = x; i < 600005; i += i & -i)
        bit[i] += val;
}
ll query(ll x)
{
    ll r = 0;
    for (ll i = x; i > 0; i -= i & -i)
        r += bit[i];
    return r;
}
ll arr[600005];
vll adj[600005];
map<ll, ll> mp;
map<pl, ll> qans;
vll q[600005];
ll lv[600005];
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
    f(1, n + 1)
        arr[i] = n + 1 - i;
    f(1, m + 1)
    {
        cin >> arr[n + i];
        adj[arr[n + i]].pb(n + i);
    }
    f(1, n + 1)
    {
        ll last = n + 1 - i;
        for (auto j : adj[i])
        {
            q[j].pb(last);
            last = j;
        }
        q[n + m].pb(last);
    }
    memset(lv, -1, sizeof(lv));

    f(1, n + m + 1)
    {
        if (lv[arr[i]] != -1)
            update(lv[arr[i]], -1);
        lv[arr[i]] = i;
        update(i, 1);
        for (auto j : q[i])
        {
            ll x = query(i) - query(j-1);
            qans[{j, i}] = x - 1;
            // cout<<j<<" "<<i<<" "<<x-1<<"\n";
        }
    }

    f(1, n + 1)
    {
        ll last = n + 1 - i;
        ll mn = i, mx = i;
        // cout<<"--------------\n";
        for (auto j : adj[i])
        {
            mn = 1;
            ll x = qans[{last, j}];
            mx = max(mx, 1 + x);
            // cout << last << " " << j << " " << x << "\n";
            last = j;
        }
        ll x = qans[{last, n + m}];
        // cout<<last<<" "<<n+m<<" "<<x<<"\n";
        mx = max(mx, 1 + x);
        cout << mn << " " << mx << "\n";
    }
}