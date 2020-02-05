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
ll arr[100005];
pl arr1[100005];
pl tree[800005];
ll lazy[800005];
ll f_index[100005];
ll left(ll i) { return 2 * i; }
ll right(ll i) { return 2 * i + 1; }
void propogate(ll l, ll h, ll pos)
{
    if (lazy[pos] != 0)
    {
        if (l != h)
        {
            lazy[left(pos)] += lazy[pos];
            lazy[right(pos)] += lazy[pos];
        }
        tree[pos].first += lazy[pos];
        tree[pos].second += lazy[pos];
        lazy[pos] = 0;
    }
}
void build(ll l, ll h, ll pos)
{
    if (l == h)
    {
        tree[pos] = {arr[l], arr[l]};
        return;
    }
    ll m = (l + h) / 2;
    build(l, m, left(pos));
    build(m + 1, h, right(pos));
    tree[pos].first = min(tree[left(pos)].first, tree[right(pos)].first);
    tree[pos].second = max(tree[left(pos)].second, tree[right(pos)].second);
}
ll query(ll l, ll h, ll pos, ll val)
{
    propogate(l, h, pos);
    if (l == h)
    {
        if (tree[pos].first >= val)
            return 1;
        return 0;
    }
    ll ans = 0;
    if (tree[pos].first >= val)
        return (h - l + 1);
    if (tree[pos].second < val)
        return 0;
    ll m = (l + h) / 2;
    ans += query(l, m, left(pos), val);
    ans += query(m + 1, h, right(pos), val);
    tree[pos].first = min(tree[left(pos)].first, tree[right(pos)].first);
    tree[pos].second = max(tree[left(pos)].second, tree[right(pos)].second);
    return ans;
}
void update(ll l, ll h, ll pos, ll val)
{
    propogate(l, h, pos);
    if (l == h)
    {
        if (tree[pos].first >= val)
            tree[pos] = {tree[pos].first - 1, tree[pos].first - 1};
        return;
    }
    if (tree[pos].first >= val)
    {
        lazy[pos] += -1;
        propogate(l, h, pos);
        return;
    }
    if (tree[pos].second < val)
        return;
    ll m = (l + h) / 2;
    update(l, m, left(pos), val);
    update(m + 1, h, right(pos), val);
    tree[pos].first = min(tree[left(pos)].first, tree[right(pos)].first);
    tree[pos].second = max(tree[left(pos)].second, tree[right(pos)].second);
}
void pupdate(ll l, ll h, ll pos, ll ind)
{
    propogate(l, h, pos);
    if (l == h)
    {
        tree[pos] = {tree[pos].first + 1, tree[pos].second + 1};
        return;
    }
    ll m = (l + h) / 2;
    if (ind <= m)
        pupdate(l, m, left(pos), ind);
    else
        pupdate(m + 1, h, right(pos), ind);
    tree[pos].first = min(tree[left(pos)].first, tree[right(pos)].first);
    tree[pos].second = max(tree[left(pos)].second, tree[right(pos)].second);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    f(1, n + 1) cin >> arr1[i].first, arr1[i].second = i;
    sort(arr1, arr1 + n);
    f(1, n + 1)
        f_index[arr1[i].second] = i,
        arr[i] = arr1[i].first;

    build(1, n, 1);
    while (q--)
    {
        ll t, x;
        cin >> t >> x;
        if (t == 1)
            pupdate(1, n, 1, f_index[x]);
        else if (t == 2)
            cout << query(1, n, 1, x) << "\n";
        else
            update(1, n, 1, x);
        // f(1,11)cout<<tree[i]<<"\n";
    }
}