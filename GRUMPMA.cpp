#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
#define MAX 1000000007
ll dp[10004][102];
ll arr[10004];
ll m, n, k;
ll fact(ll nn)
{
    ll res = 1;
    for (ll i = 2; i <= nn; i++)
        res = (res * i) % MAX;
    return res;
}
ll nCr(ll nn, ll r)
{
    return (fact(nn) * power((fact(r) * fact(nn - r)) % MAX, MAX - 2, MAX)) % MAX;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {

        cin >> n >> k >> m;
        ll f = k / m;
        // if(k==m)f--;
        for (ll i = 1; i <= n; i++)
            cin >> arr[i], arr[i] = arr[i] % m;

        ll ans = 0;
        for (ll i = 0; i < 10004; i++)
        {
            for (ll j = 0; j < 102; j++)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][1] = 1;

        for (ll i = 1; i <= n; i++)
        {
            if (arr[i] > k)
            {
                continue;
            }
            for (ll j = 1; j <= f + 1; j++)
            {

                if (arr[i] == 0)
                {
                    if(m<=k)
                    dp[arr[i]][j] = (dp[arr[i]][j] + dp[m - 1][j - 1]) % MAX;
                    // else 
                    // dp[arr[i]][j] = (dp[arr[i]][j] + dp[m - 1][j - 1]) % MAX;

                }
                else
                {
                    dp[arr[i]][j] = (dp[arr[i]][j] + dp[arr[i] - 1][j]) % MAX;
                }
                // cout << dp[arr[i]][j] << " ";
            }
            // cout << "\n";
        }
        // if (k % m == 0)
        //     cout << dp[k % m][f] << "\n";
        // else
        if (m == 1)
        {
            cout << nCr(n, k) << "\n";
        }
        else
        {
            cout << dp[k % m][f + 1] << "\n";
        }
    }
}