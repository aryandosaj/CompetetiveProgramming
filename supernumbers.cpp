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
pl arr[100005];
ll tree[400005];
set<ll> adj[100005];
set<ll> a;
ll arr1[100005];
ll vis[100005];
ll query(ll l, ll h, ll pos, ll ql, ll qh)
{
    if (h < ql || l > qh)
        return 0;
    if (l >= ql && h <= qh)
        return tree[pos];
    ll mid = (l + h) / 2;
    return max(query(l, mid, 2 * pos + 1, ql, qh), query(mid + 1, h, 2 * pos + 2, ql, qh));
}
void update(ll l, ll h, ll pos, ll ind, ll val)
{
    if (l == h && l == ind)
    {
        tree[pos] = val;
        return;
    }
    ll mid = (l + h) / 2;
    if (ind <= mid)
        update(l, mid, 2 * pos + 1, ind, val);
    else
        update(mid + 1, h, 2 * pos + 2, ind, val);
    tree[pos] = max(tree[2 * pos + 1], tree[2 * pos + 2]);
}
void dfs(ll ind, ll ans)
{
    a.insert(arr1[ind]);
    vis[ind] = 1;
    for (auto i : adj[ans])
        if (!vis[i] && arr1[i] < arr1[ind] && i < ind)
            dfs(i,ans-1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 10;
    while (t--)
    {
        a.clear();
        f(0, 100005) adj[i].clear(),vis[i]=0;
        f(0, 400005) tree[i] = 0;
        ll n;
        cin >> n;
        f(1, n + 1)
        {
            cin >> arr[i].first;
            arr[i].second = i;
            arr1[i] = arr[i].first;
        }
        sort(arr + 1, arr + n + 1);
        ll ans = 0;
        f(1, n + 1)
        {
            ll val = query(1, n, 0, 0, arr[i].second);
            update(1, n, 0, arr[i].second, val + 1);
            adj[val + 1].insert(arr[i].second);
            ans = max(ans, val + 1);
        }
        ll ind = n + 1;
        for(auto i:adj[ans])
            dfs(i,ans-1);
        cout<<a.size()<<"\n";
        for (auto i : a)
            cout << i << " ";
        cout << "\n";
    }
}