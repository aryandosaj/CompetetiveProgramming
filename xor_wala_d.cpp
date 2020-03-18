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
ll arr[400005];
ll a[400005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    f(0, n) cin >> arr[i];
    ll ans = 0;
    f(0, 25)
    {
        ll mod = (1 << (i + 1));
        ll l1 = (1 << i);
        ll r1 = (1 << (i + 1)) - 1;
        ll l2 = (1 << (i + 1)) + (1 << (i));
        ll r2 = (1 << (i + 2)) - 2;
        fi(0, n)
            a[j] = arr[j] % mod;
        sort(a, a + n);
        ll c = 0;
        fi(0, n)
        {
            ll l = l1 - a[j];
            ll r = r1 - a[j];
            c += upper_bound(a + j + 1, a + n, r) - lower_bound(a + j + 1, a + n, l);
            l = l2 - a[j];
            r = r2 - a[j];
            c += upper_bound(a + j + 1, a + n, r) - lower_bound(a + j + 1, a + n, l);
        }
        if (c & 1)
            ans = ans | (1 << i);
    }
    cout << ans;
}