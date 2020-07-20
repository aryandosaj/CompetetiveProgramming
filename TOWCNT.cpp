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
pl up(pl p1, pl p2, ll x, ll y1)
{
    ll y = (p2.second - p1.second) * x + p2.first * p1.second - p2.second * p1.first;
    y1 = y1 * (p2.first - p1.first);
    return {y1, y};
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
        ll n, h;
        cin >> h >> n;
        vector<pair<pl, ll>> arr;
        ll ans[n];
        map<pair<pl, ll>, ll> mp;
        map<ll, ll> m;
        f(0, n)
        {
            ans[i] = 0;
            ll ty, x, a;
            cin >> ty >> x >> a;
            arr.pb({{x, a}, ty});
            mp[{{x, a}, ty}] = i;
            m[x]++;
        }
        f(0, n) if (m[arr[i].first.first] == 2) ans[i]++;
        sort(arr.begin(), arr.end());
        f(0, n)
        {
            ll x = arr[i].first.first, y = arr[i].first.second;
            pl p[2];
            p[0] = {arr[i].first.first + 1, 0};
            p[1] = {arr[i].first.first + 1, h};
            fi(i + 1, n)
            {
                if (arr[i].first.first == arr[j].first.first)
                    continue;
                ll ty = arr[j].second;
                pl temp0 = up(arr[i].first, p[0], arr[j].first.first, arr[j].first.second);
                pl temp1 = up(arr[i].first, p[1], arr[j].first.first, arr[j].first.second);
                // cout << i << " " << j << " " << temp1.first << " " << temp1.second << "\n";
                if (temp0.first > temp0.second && temp1.first < temp1.second)
                {
                    p[ty] = arr[j].first;
                    ans[mp[arr[i]]]++;
                    ans[mp[arr[j]]]++;
                }
                else if ((ty == 0 && temp1.first >= temp1.second) || (ty == 1 && temp1.first <= temp1.second))
                    break;
            }
        }
        f(0, n) cout << ans[i] << " ";
        cout << "\n";
    }
}