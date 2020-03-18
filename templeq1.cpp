#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#define cin(x) scanf("%d", &x)
using namespace std;
#define ll int
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

ll ind_in_sort[100005];
ll ind_in_arr[100005];
pl arr[100005];
pl tree[400005];
ll lazy[400005];
ll n;
void propogate(ll l, ll h, ll pos)
{
    if (lazy[pos])
    {
        if (l == h)
        {
            tree[pos].first += lazy[pos];
            tree[pos].second += lazy[pos];
            lazy[pos] = 0;
            return;
        }
        tree[pos].first += lazy[pos];
        tree[pos].second += lazy[pos];
        lazy[2 * pos + 1] += lazy[pos];
        lazy[2 * pos + 2] += lazy[pos];
        lazy[pos] = 0;
    }
}
void build(ll l, ll h, ll pos)
{
    if (l == h)
    {
        tree[pos].first = arr[l].first;
        tree[pos].second = arr[l].first;
        return;
    }
    ll mid = (l + h) / 2;
    build(l, mid, 2 * pos + 1);
    build(mid + 1, h, 2 * pos + 2);
    tree[pos].first = min(tree[2 * pos + 1].first, tree[2 * pos + 2].first);
    tree[pos].second = max(tree[2 * pos + 1].second, tree[2 * pos + 2].second);
}

void range_update(ll l, ll h, ll pos, ll ql, ll qh, ll val)
{
    propogate(l, h, pos);
    if (qh < l || ql > h)
        return;
    if (l == h)
    {
        tree[pos].first += val, tree[pos].second += val;
        return;
    }
    if (l >= ql && h <= qh)
    {
        lazy[pos] += val;
        propogate(l, h, pos);
        return;
    }
    ll m = (l + h) / 2;
    range_update(l, m, 2 * pos + 1, ql, qh, val);
    range_update(m + 1, h, 2 * pos + 2, ql, qh, val);
    tree[pos].first = min(tree[2 * pos + 1].first, tree[2 * pos + 2].first);
    tree[pos].second = max(tree[2 * pos + 1].second, tree[2 * pos + 2].second);
}
ll bin_ind(ll l, ll h, ll pos, ll val)
{
    ll m = (l + h) / 2;
    propogate(l, h, pos);
    if (tree[pos].second <= val)
        return n;
    if (l == h)
        return l;
    propogate(l, m, 2 * pos + 1);
    if (tree[2 * pos + 1].second <= val)
        return bin_ind(m + 1, h, 2 * pos + 2, val);
    return bin_ind(l, m, 2 * pos + 1, val);
}
ll getVAL(ll l, ll h, ll pos, ll val)
{
    propogate(l, h, pos);
    if (l == h)
        return tree[pos].first;
    ll m = (l + h) / 2;
    if (val <= m)
        return getVAL(l, m, 2 * pos + 1, val);
    else
        return getVAL(m + 1, h, 2 * pos + 2, val);
}
void prnt_tree(ll l, ll h, ll pos)
{
    propogate(l, h, pos);
    if (l == h)
    {
        cout << tree[pos].first << " ";
        return;
    }
    ll m = (l + h) / 2;
    prnt_tree(l, m, 2 * pos + 1);
    prnt_tree(m + 1, h, 2 * pos + 2);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin(n);
    cin(q);
    f(0, n)
        cin(
            arr[i].first),
        arr[i].second = i;
    sort(arr, arr + n);
    f(0, n)
        ind_in_sort[arr[i].second] = i,
        ind_in_arr[i] = arr[i].second;
    build(0, n - 1, 0);

    while (q--)
    {
        ll t, x;
        cin(t);
        cin(x);
        if (t == 1)
        {
            x--;
            ll y = ind_in_sort[x];
            ll val = getVAL(0, n - 1, 0, y);
            ll z = bin_ind(0, n - 1, 0, val) - 1;
            ll k = ind_in_arr[z];
            swap(ind_in_sort[k], ind_in_sort[x]);
            ind_in_arr[z] = x;
            ind_in_arr[y] = k;
            range_update(0, n - 1, 0, z, z, 1);
        }
        else if (t == 2)
            printf("%d\n", n - bin_ind(0, n - 1, 0, x - 1));
        else
            range_update(0, n - 1, 0, bin_ind(0, n - 1, 0, x - 1), n - 1, -1);
    }
}