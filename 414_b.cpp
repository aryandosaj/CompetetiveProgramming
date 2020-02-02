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
    ll n, k;
    cin >> n >> k;
    ll dp[k + 1][n + 1];
    for (ll i = 0; i <= k; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (ll j = 0; j <= n; j++)
    {
        dp[1][j] = 1;
    }
    vll factor[2001];
    for(ll i=1;i<=2000;i++)
    {
        for(ll j=1;j<=i;j++)
        {
            if(i%j==0) factor[i].push_back(j);

        }
    }
    for (ll i = 2; i <= k; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            for (auto d:factor[j])
            {
                (dp[i][j] += dp[i - 1][d]) %= MAX;
            }
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        (ans += dp[k][i]) %= MAX;

    cout << ans;
}