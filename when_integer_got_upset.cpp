#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000000007
ll n;
ll dp[5000][15][15];
ll a[15], p[15];

ll rec(ll mask, ll fir, ll las)
{
    if (dp[mask][fir][las] != -1)
        return dp[mask][fir][las];
    ll b = __builtin_popcountll(mask);
    if (b == n)
        return 0;
    ll ans = MAX;
    for (ll i = 0; i < n; i++)
    {
        if ((mask & (1 << i)) == 0)
            ans = min(ans, (a[fir] ^ a[las] ^ a[i]) * p[b] + rec(mask | (1 << i), i, fir));
    }
    return dp[mask][fir][las] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
            cin >> p[i];
        for (ll mask = 0; mask < 5000; mask++)
        {
            for (ll j = 0; j < n; j++)
            {
                for (ll g = 0; g < n; g++)
                {
                    // if (mask)
                    //     dp[mask][j][g] = MAX;
                    // else
                    dp[mask][j][g] = -1;
                }
            }
        }

        // for (ll mask = 0; mask < pow(2, n); mask++)
        //     for (ll j = 0; j < n; j++)
        //         for (ll g = 0; g < n; g++)
        //             for (ll f = 0; f < n; f++)
        //             {
        //                 if ((j != f) && (f != g) && (j != g) && (!(mask & (1 << j))))
        //                     dp[mask | (1 << j)][g][j] = min(dp[mask | (1 << j)][g][j], dp[mask][f][g] + p[j] * (a[f] ^ a[g] ^ a[j]));
        //             }
        ll ans = MAX;
        for (ll g = 0; g < n; g++)
        {
            for (ll f = 0; f < n; f++)
            {
                if (f != g)
                    ans = min(ans, rec((1 << g) | (1 << f), g, f));
            }
        }
        cout << ans << "\n";
    }
}