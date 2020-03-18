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
ll rec(ll n, ll m)
{
    ll ans = 0;
    if (n <= 0)
        return 0;

    if (m > 0)
    {
        if (n == 1)
            return 1;
        if (m & 1)
        {
            if (n & 1)
                ans += ((n / 2 + 1) * (n / 2 + 1)) + 2 * rec(n / 2, m / 2);
            else
                ans += (n / 2) * (n / 2 + 1) + rec(n / 2, m / 2) + rec(n / 2 - 1, m / 2);
        }
        else
        {
            if (n & 1)
                ans += 2 * rec(n / 2, m / 2);
            else
                ans += 2 * rec(n / 2, m / 2);
        }
    }
    return ans;
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
        ll n, m;
        cin >> n >> m;
        if (m == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        // cout<<rec(n,m)<<"\n";
        ll d = (n - m) / (m + 1);
        ll ans = (n * (n + 1)) / 2;

        if (n == m)
        {
            cout << ans << "\n";
            continue;
        }
        else
        {

            // ll h =m;
            // ll s = d-1;
            // ans-=h*(s*(s+1))/2;
            // ll k = (n-m*(d));
            // ans = ans - k*(k+1)/2;
            // cout<<ans<<"\n";
            // continue;

            
            {
                {
                    ll k = (n - (m+1) * d-m);
                    ans = ans - ((k)*(d+1) * (d + 2)) / 2;
                    ans = ans - (m+1-k)*(d*(d+1))/2;
                    cout<<ans<<"\n";
                    continue;
                }

            }

            // cout<<rec(n,m)<<"\n";
            // ll l = 0, h = n;
            // ll mid;
            // while (l < h)
            // {
            //     ll num = n;
            //     mid = (l + h) / 2;
            //     ll val = 0;
            //     ll x = (n * (n + 1)) / 2;
            //     ll k=0;
            //     while (1)
            //     {

            //         if (num >= mid)
            //         {
            //             k++;
            //             val += (mid * (mid + 1)) / 2;
            //             num -= mid;
            //         }
            //         else
            //         {

            //         }

            //     }
            // }
        }
    }
}