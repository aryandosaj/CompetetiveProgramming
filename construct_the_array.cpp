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
#define MAX 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, x;
    cin >> n >> k >> x;
    ll dp[n + 1][k + 1];
    memset(dp, 0, sizeof dp);

    for (ll i = 0; i <= k; i++)
    {
        dp[1][i] = 0;
    }
    dp[1][1] = 1;

    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            for (ll g = 1; g <= k; g++)
            {
                if (j != g)
                    dp[i][j] = (dp[i][j] + dp[i - 1][g]) % MAX;
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout<<"\n";
    }
}