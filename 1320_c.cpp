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
pl arr[200005];
pl drr[200005];
pll d;
pll a;
vector<pair<pl, ll>> v;
ll tree[1000006];
ll lazy[1000006];
void propogate(ll l, ll h, ll pos)
{
    tree[pos] += lazy[pos];
    if (l == h)
    {
        lazy[pos] = 0;
        return;
    }
    lazy[2 * pos + 1] += lazy[pos];
    lazy[2 * pos + 2] += lazy[pos];
    lazy[pos] = 0;
}
void build(ll l, ll h, ll pos)
{
    if (l == h)
    {
        tree[pos] = -d[l].second;
        return;
    }
    ll m = (l + h) / 2;
    build(l, m, 2 * pos + 1);
    build(m + 1, h, 2 * pos + 2);
    tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
}
void range_update(ll l, ll h, ll pos, ll ql, ll qh, ll val)
{
    propogate(l, h, pos);
    if (ql > h || qh < l)
        return;
    if (ql <= l && qh >= h)
    {
        lazy[pos] += val;
        propogate(l, h, pos);
        return;
    }
    ll m = (l + h) / 2;
    range_update(l, m, 2 * pos + 1, ql, qh, val);
    range_update(m + 1, h, 2 * pos + 2, ql, qh, val);
    tree[pos] = max(tree[2 * pos + 1], tree[2*pos + 2]);
}
bool compare(pl p, pl q)
{
    if (p.first != q.first)
        return p.first > q.first;
    return p.second < q.second;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, p;
    cin >> n >> m >> p;
    f(0, n)
    {
        ll a, ca;
        cin >> a >> ca;
        arr[i] = {a, ca};
    }
    f(0, m)
    {
        ll d, cd;
        cin >> d >> cd;
        drr[i] = {d, cd};
    }
    sort(arr, arr + n, compare);
    sort(drr, drr + n, compare);
    ll mm = MOD;
    ll mim = MOD;
    f(0, n) if (mm > arr[i].second)
        mm = arr[i].second,
        a.pb(arr[i]),mim = min(mim,arr[i].second);
    mm = MOD;
    f(0, m) if (mm > drr[i].second)
        mm = drr[i].second,
        d.pb(drr[i]);

    // for (auto i : a)
    //     cout << " (" << i.first << " " << i.second << ") ";
    // cout << "\n";
    // for (auto i : d)
    //     cout << " (" << i.first << " " << i.second << ") ";
    // cout << "\n";
    reverse(a.begin(), a.end());
    reverse(d.begin(), d.end());
    build(0, d.size() - 1, 0);
    ll ma = a[a.size() - 1].first;
    f(0, p)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        v.push_back({{x, y}, z});
    }
    sort(v.begin(), v.end(), less<pair<pl, ll>>());
    ll ans = tree[0] -mim;
    for (auto i : v)
    {
        ll val = 0;
        if (i.first.first+1 > ma)
            break;
        pl pp = *lower_bound(a.begin(), a.end(), make_pair(i.first.first+1, -1ll));
        ll ql = lower_bound(d.begin(), d.end(), make_pair(i.first.second+1, -1ll)) - d.begin();
        range_update(0, d.size() - 1, 0, ql, d.size() - 1, i.second);
        val= -pp.second + tree[0];
        ans = max(ans, val);
        // cout << i.first.first << " " << pp.first << " " << ql << " " << tree[0] << " " << val << "\n";
    }
    cout << ans;
}