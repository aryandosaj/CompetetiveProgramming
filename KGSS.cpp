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
pl tree[400005];
ll arr[100005];
pl merg(pl a, pl b)
{
    vll v;
    v.push_back(a.first);
    v.push_back(a.second);
    v.push_back(b.first);
    v.push_back(b.second);
    sort(v.begin(), v.end(), greater<ll>());
    return {v[0], v[1]};
}
pl query(ll l, ll h, ll pos, ll ql, ll qh)
{
    // cout<<pos<<"\n";
    // cout<<l<<" "<<ql<<" "<<h<<" "<<qh<<"\n";
    if (l > qh || h < ql)
        return {-1, -1};
    if (l >= ql && h <= qh)
        return tree[pos];
    ll m = (l + h) / 2;
    pl temp = merg(query(l, m, 2 * pos + 1, ql, qh), query(m + 1, h, 2 * pos + 2, ql, qh));
    // cout<<temp.first<<" "<<temp.second<<"\n";
    return temp;
}

void build(ll l, ll h, ll pos)
{
    if (l == h)
    {
        tree[pos] = {arr[l], -1};
        return;
    }
    ll m = (l + h) / 2;
    build(l, m, 2 * pos + 1);
    build(m + 1, h, 2 * pos + 2);
    tree[pos] = merg(tree[2 * pos + 1], tree[2 * pos + 2]);
}
void update(ll l, ll h, ll pos, ll ind, ll val)
{
    if (l == h)
    {
        arr[l] = val;
        tree[pos] = {val, -1};
        return;
    }
    ll m = (l + h) / 2;
    if (ind <= m)
        update(l, m, 2 * pos + 1, ind, val);
    else
        update(m + 1, h, 2 * pos + 2, ind, val);
    tree[pos] = merg(tree[2 * pos + 1], tree[2 * pos + 2]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    f(0, 400005) tree[i] = {0, 0};
    ll n;
    cin >> n;
    f(0, n) cin >> arr[i];
    build(0, n - 1, 0);
    // cout<<tree[0].first<<" "<<tree[0].second<<"\n";
    ll m;
    cin >> m;
    while (m--)
    {
        char c;ll a, b;
        cin >> c >> a >> b;

        if (c == 'U')
            update(0, n - 1, 0, a - 1, b);
        else
        {
            pl temp = query(0,n-1,0,a-1,b-1);
            cout<<temp.first+temp.second<<"\n";
        }
    }
}