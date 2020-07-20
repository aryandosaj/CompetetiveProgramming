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
ll arr[200005];
ll f[400005];
ll mp[400005];

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
        ll n, k;
        cin >> n >> k;
        f(0, 2 * k + 2) f[i] = 0, mp[i] = 0;
        f(0, n)
                cin >>
            arr[i];
        map<ll, ll> mp;
        f(0, n / 2)
            f[min(arr[i], arr[n - 1 - i]) + 1]++,
            f[max(arr[i], arr[n - 1 - i]) + k + 1]--, mp[arr[i] + arr[n - i - 1]]++;
        ll ans = MOD;
        f(1, 2 * k + 1)
        {
            f[i] += f[i - 1];
            ans = min(ans, f[i] - mp[i] + n - f[i] * 2);
        }

        cout << ans << "\n";
    }
}