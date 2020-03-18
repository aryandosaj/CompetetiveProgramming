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
ll arr[100005];
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
        vll v;
        ll n;
        cin >> n;
        f(1, n + 1) cin >> arr[i];
        arr[0] = -1;
        arr[n + 1] = -1;
        ll m = -1;
        f(1, n + 1)
        {
            if (i > 1)
            {
                if (arr[i] != -1 && arr[i - 1] != -1)
                    m = max(m, abs(arr[i] - arr[i - 1]));
            }
            if (arr[i] == -1)
            {
                if (arr[i - 1] != -1)
                    v.pb(arr[i - 1]);
                if (arr[i + 1] != -1)
                    v.pb(arr[i + 1]);
            }
        }
        sort(v.begin(), v.end());
        if (v.empty())
        {
            cout << "0 1"
                 << "\n";
            continue;
        }
        ll a = v[0];
        ll b = *prev(v.end());
        ll ans = (a + b) / 2;
        cout << max(m,b - ans) << " " << ans << "\n";
    }
}