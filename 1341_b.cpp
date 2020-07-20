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
ll p[200005];
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
        f(1, n + 1)
        {
            p[i] = 0;
            cin >> arr[i];
        }
        vll v;
        f(1, n + 1)
        {
            if (i > 1 && i < n)
            {
                if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                    v.pb(i);
            }
            // cout << p[i] << " ";
        }
        // cout << "\n";
        ll ans = 0, l=1;
        f(1, n + 1)
        {

            ll r = i + k - 1;
            if (r > n)
                break;
            ll temp = upper_bound(v.begin(), v.end(), r - 1) - upper_bound(v.begin(), v.end(), i);
            if (ans < temp)
            {
                ans = temp;
                l = i;
                // cout << i << " " << r << " " << (p[r] - p[i]) << ans << l << "\n";
            }
        }
        cout << ans + 1 << " " << l << "\n";
    }
}