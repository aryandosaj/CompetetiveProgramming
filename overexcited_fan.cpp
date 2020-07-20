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
        ll x, y;
        cin >> x >> y;
        string m;
        cin >> m;
        ll tim = 0;
        ll c = 1;
        ll ans = 1e18;
        if (x == 0 && y == 0)
        {
            cout << "0\n";
            continue;
        }
        for (auto i : m)
        {
            tim++;
            if (i == 'N')
                y++;
            if (i == 'S')
                y--;
            if (i == 'E')
                x++;
            if (i == 'W')
                x--;
            ll req_tim = abs(x) + abs(y);
            if (req_tim <= tim)
                ans = min(ans, tim);
        }
        if (ans == 1e18)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << "\n";
    }
}