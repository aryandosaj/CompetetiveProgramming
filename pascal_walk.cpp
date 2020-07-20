#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll int
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
ll dp[501][501];

ll rec(ll r, ll k)
{
    if (k > r || k < 1)
        return 0;
    if (dp[r][k] != -1)
        return dp[r][k];
    ll ans = rec(r - 1, k - 1) + rec(r - 1, k);
    if (ans > 1e9)
        ans = 1e9;
    return dp[r][k] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f(0, 501)
        fi(0, 501)
            dp[i][j] = -1;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;

    ll t;
    cin >> t;
    ll f = 1;
    fii(1, t + 1)
    {
        ll n;
        cin >> n;
        pll ans;
        ll sum = 0;
        ll num = n;
        ll c = 0;
        f(1, min(32, num + 1)) ans.pb({i, 1}), n--, c++;
        ll ii = 29;
        ll r = 30;
        ll flag = 0;

        while (n > 0)
        {
            if ((1 << ii) & n)
            {
                n = n ^ (1 << ii);
                if (flag == 0)
                    f(1, r + 1)
                        ans.pb({r, i});
                else
                    f(1, r + 1)
                        ans.pb({r, r + 1 - i});
                flag = 1 - flag;
                ii--;
                r--;
                continue;
            }
            if (flag == 0)
                ans.pb({r, 1});
            else
                ans.pb({r, r});
            r--;
            ii--;
            n--;
        }
        cout << "Case #" << k << ": "
             << "\n";
        for (auto j : ans)
            cout << j.first << " " << j.second << "\n";
        // cout << sum;
    }
}