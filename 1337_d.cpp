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
ll a[100005];
ll b[100005];
ll c[100005];
ll calc(ll a, ll y, ll z)
{
    return (a - y) * (a - y) + (y - z) * (y - z) + (a - z) * (a - z);
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
        ll r, g, bl;
        cin >> r >> g >> bl;
        f(0, r) cin >> a[i];
        f(0, g) cin >> b[i];
        f(0, bl) cin >> c[i];
        sort(a, a + r);
        sort(b, b + g);
        sort(c, c + bl);
        ll ans = 4e18;
        f(0, r)
        {
            {
                ll ind = lower_bound(b, b + g, a[i]) - b;
                if (ind != g)
                {
                    ll mid = (a[i]+b[ind])/2;
                    ll ind2 = lower_bound(c, c + bl, mid) - c;
                    if (ind2 != bl)
                        ans = min(ans, calc(a[i], b[ind], c[ind2]));
                    if (ind2 != 0)
                        ind2--, ans = min(ans, calc(a[i], b[ind], c[ind2]));
                }
                if (ind != 0)
                {
                    ind--;
                    ll mid = (a[i]+b[ind])/2;
                    ll ind2 = lower_bound(c, c + bl, mid) - c;
                    if (ind2 != bl)
                        ans = min(ans, calc(a[i], b[ind], c[ind2]));
                    if (ind2 != 0)
                        ind2--, ans = min(ans, calc(a[i], b[ind], c[ind2]));
                }
            }

            {
                ll ind = lower_bound(c, c + bl, a[i]) - c;
                if (ind != bl)
                {
                    ll mid = (a[i]+c[ind])/2;
                    ll ind2 = lower_bound(b, b + g, mid) - b;
                    if (ind2 != g)
                        ans = min(ans, calc(a[i], c[ind], b[ind2]));    
                    if (ind2 != 0)
                        ind2--, ans = min(ans, calc(a[i], c[ind], b[ind2]));
                }
                if (ind != 0)
                {
                    ind--;
                    ll mid = (a[i]+c[ind])/2;
                    ll ind2 = lower_bound(b, b + g, mid) - b;
                    if (ind2 != g)
                        ans = min(ans, calc(a[i], c[ind], b[ind2]));
                    if (ind2 != 0)
                        ind2--, ans = min(ans, calc(a[i], c[ind], b[ind2]));
                }
            }
        }
        cout << ans << "\n";
    }
}