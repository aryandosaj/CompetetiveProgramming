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
    fii(1, t + 1)
    {
        cout << "Case #" << k << ": ";
        ll n, d;
        cin >> n >> d;
        ll a[n + 1];

        f(0, n)
                cin >>
            a[i];
        sort(a, a + n);
        map<ll, ll> vis;
        ll ans = d - 1;
        f(0, n)
        {
            fi(1, d + 1)
            {
                ll no_of_p = 0;
                ll no_of_step = 0;
                vll r;
                for (ll h = 0; h < n; h++)
                {
                    ll v = 0;
                    for (ll g = 1; g <= d; g++)
                    {
                        if (a[i] * g == a[h] * j)
                        {
                            v = g;
                            break;
                        }
                    }
                    // if (i == 0)
                    // {
                    //     cout << v << "\n";
                    // }
                    if (v)
                    {
                        if (no_of_p + v <= d)
                        {
                            no_of_p += v;
                            no_of_step += v - 1;
                            if (no_of_p == d)
                            {
                                ans = min(ans, no_of_step);
                                break;
                            }
                        }
                        else
                        {
                            ll req = d - no_of_p;
                            no_of_p += req;
                            no_of_step += req;
                            ans = min(ans, no_of_step);
                            break;
                        }
                    }
                    else
                        r.pb(a[h]);
                }
                if (no_of_p < d)
                {
                    for (auto z : r)
                    {
                        ll another = z * j;
                        while (no_of_p < d && another > a[i])
                            another -= a[i], no_of_p++, no_of_step++;
                    }
                    if (no_of_p == d)
                    {
                        ans = min(ans, no_of_step);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}