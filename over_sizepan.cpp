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
        if (d == 2)
        {
            map<ll, ll> mp;
            f(0, n)
            {
                mp[a[i]]++;
            }
            ll ans = 1;
            for (auto i : mp)
            {
                if (i.second > 1)
                {
                    ans = 0;
                    break;
                }
            }
            cout << ans << "\n";
        }
        else if (d == 3)
        {
            ll ans = 2;
            map<ll, ll> mp;
            f(0, n)
                mp[a[i]]++;
            for (auto i : mp)
            {
                if (i.second > 2)
                    ans = 0;
                else
                {
                    ll num = i.first * 2;
                    if (mp.find(num) != mp.end())
                        ans = min(ans, 1ll);
                }
                if (i.second == 2)
                {
                    if (mp.upper_bound(i.first) != mp.end())
                        ans = min(ans, 1ll);
                }
            }
            cout << ans << "\n";
        }
    }
}