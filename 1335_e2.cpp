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
vll ind[201];
ll arr[200005];

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
        ll n;
        cin >> n;
        // f(0, n + 1) fi(0, 201) pre[i][j] = 0;
        f(0, 201) ind[i].clear();
        f(1, n + 1)
        {
            cin >> arr[i], ind[arr[i]].pb(i);
            // fi(1, 201)
            //     pre[i][j] = pre[i - 1][j] + (j == arr[i]);
        }
        ll ans = 1;
        f(1, 201)
        {
            ll l = ind[i].size();

            for (ll j = 0; j < l / 2; j++)
            {
                ll l1 = ind[i][j];
                ll r1 = ind[i][l - 1 - j] - 1;
                ll m = (j + 1) * 2;
                fii(1, 201)
                {
                    ll d = upper_bound(ind[k].begin(), ind[k].end(), r1) - upper_bound(ind[k].begin(), ind[k].end(), l1) ;
                    ans = max(ans, m + d);
                }
            }
        }
        cout << ans << "\n";
    }
}