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
pl a[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;

    f(0, n)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    ll ans = 0;
    ll ans2 = 0;
    // if (n == k)
    // {
    //     f(0, n) if (i & 1) ans = max(ans, a[i].first);
    //     else ans2 = max(ans2, a[i].first);
    //     cout << min(ans, ans2) << "\n";
    //     return 0;
    // }
    ll l = 0, h = 1e9;
    while (l <= h)
    {
        ll m = (l + h) / 2;
        // cout<<m<<"\n";
        ll f = 0;
        ll ind = 0;
        f(0, n)
        {
            if (ind & 1)
            {
                if (a[i].first <= m)
                    ind++;
            }
            else
            {
                ind++;
            }
            if (ind == k)
                break;
        }
        if (ind == k)
            f = 1;
        ll f1 = 0;
        ll ind1 = 0;
        f(0, n)
        {
            if (!(ind1 & 1))
            {
                if (a[i].first <= m)
                    ind1++;
            }
            else
            {
                ind1++;
            }
            if (ind1 == k)
                break;
        }
        if (ind1 == k)
            f1 = 1;
        if (f || f1)
        {
            h = m - 1;
            ans = m;
        }
        else
            l = m + 1;
    }
    cout << ans << "\n";
}