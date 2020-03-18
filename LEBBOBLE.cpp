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
ll bit[100005];
ll arr[100005];
ll arr1[100005];
ll p[100005];
void update(ll ind, ll val)
{
    for (ll i = ind; i < 100005; i += i & -i)
        bit[i] += val;
}
ll query(ll ind)
{
    ll ret = 0;
    for (ll i = ind; i > 0; i -= i & -i)
        ret += bit[i];
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        set<ll> s;
        ll n, d;
        cin >> n >> d;
        f(0, 100005) bit[i] = 0;
        f(0, n) cin >> arr[i], s.insert(arr[i]), s.insert(arr[i] + d), arr1[i] = arr[i] + d;
        f(0, n) cin >> p[i];
        map<ll, ll> mp;
        ll c = 1;
        for (auto i : s)
            mp[i] = c++;
        f(0, n) arr[i] = mp[arr[i]], arr1[i] = mp[arr1[i]];
        ll ans = 0;
        f(0, n)
        {
            ll x = query(100004);
            ans += p[i] * (x - query(arr1[i]));
            ans += (100 - p[i]) * (x - query(arr[i]));
            update(arr1[i], p[i]);
            update(arr[i], 100 - p[i]);
        }
        cout <<setprecision(4)<<fixed<< ans / 10000.0 << "\n";
    }
}